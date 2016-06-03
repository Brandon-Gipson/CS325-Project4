#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

struct City {
	long int id;
	long int x;
	long int y;
};

//declare algorithm functions here
int distance(int xOne, int xTwo, int yOne, int yTwo);

int main(int argc, char *argv[]) {
	int i = 0, j = 0, k = 0, l = 0, num = 0, shortCityID = 0, totalCities = 0, cityNumber = 0, isVisited = 0, totalCost = 0, current = 0, dCost = INT_MAX;
	char filename[100];
	struct City cities[100];
	int cost[100][100];
	int path[100];
	int pathSize;

	memset(path, 0, sizeof(path[100] * 0));
	memset(cost, 0, sizeof(cost[0][0]) * 100 * 100);
	
	strcpy(filename, argv[1]);
	FILE *inputFile = fopen(filename, "r");
	
	strcat(filename, ".tour");
	
	while(fscanf(inputFile, "%d", &num) == 1) {
		k = i + 1;
		
		if(k % 3 == 0) {
			cities[j].y = num;
			j++;
		}
		
		else if((k % 2 == 0) && (k % 3 != 0)) {
			cities[j].x = num;
		}
		
		else {
			cities[j].id = num;
		}
		
		if(k == 3) {
			i = 0;
		}
		
		else {
			i++;
		}
		
	}
	fclose(inputFile);
	
	//print cities for testing
	/*
	for(i = 0; i < j; i++) {
		printf("City ID: %d (%d, %d) \n", cities[i].id, cities[i].x, cities[i].y);
	}*/
	
	//Cost matrix creater. Ex. cost[2][4] = the distance from cities[2].id to cities[4].id
	
	totalCities = j;
	
	for(i = 0; i <= j; i++) {
		for(k = 0; k < j; k++) {
			cost[i][k] = distance(cities[i].x, cities[k].x, cities[i].y, cities[k].y);
		}
	}
	
	//print cost matrix for testing
	/*
	for(i = 0; i <= j; i++) {
		for(k = 0; k < j; k++) {
			printf("[%d][%d] %d ", i, k, cost[i][k]);
		}
		printf("\n\n");
	}*/
	
	path[0] = cities[0].id;
	pathSize = 1;
	
	while(pathSize < totalCities) {
		for(j = 0; j < totalCities; j++) {
			if(cost[current][j-1] < dCost) {
				for(k = 0; k < pathSize; k++) {
					if(cities[j-1].id == path[k]) {
						isVisited = 0;
					}
					else {
						isVisited = 1;
					}
				}
				if(isVisited == 1) {
					dCost = cost[current][j-1];
					cityNumber = j;
					shortCityID = cities[j-1].id;
				}
			}
		}
		totalCost += dCost;
		dCost = INT_MAX;
		current =  cityNumber;
		path[pathSize] = shortCityID;
		pathSize++;
	}
	
	FILE *outputFile = fopen(filename, "ab+");
	fprintf(outputFile, "%d\n", totalCost);
	
	for (i = 0; i <= j; i++) {
		fprintf(outputFile, "%d\n", path[i]);
	}
	
	fclose(outputFile);

	
	return 0;
}

//algorithm functions go here

/********************************************
* Returns the distance between two cities
*********************************************/
int distance(int xOne, int xTwo, int yOne, int yTwo) {
	int ans;
	
	ans = sqrt((pow((xOne - xTwo), 2) + pow((yOne-yTwo), 2)));
	
	return ans;
}