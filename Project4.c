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
int cost[15200][15200];


int main(int argc, char *argv[]) {
	int i = 0, j = 0, k = 0, num = 0, shortCityID = 0, totalCities = 0, cityNumber = 0, isVisited = 0, totalCost = 0, current = 0, dCost = INT_MAX;
	char filename[100];
	struct City cities[15200];
	
	int path[15200];
	int pathSize;

	memset(path, 0, sizeof(path[0] * 15200));
	memset(cost, 0, sizeof(cost[0][0]) * 15200 * 15200);
	
	strcpy(filename, argv[1]);
	FILE *inputFile = fopen(filename, "r");
	
	while(fscanf(inputFile, "%d", &num) == 1) { //Reads input from file
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
	
	
	
	totalCities = j;
	
	//Cost matrix creater. Ex. cost[2][4] = the distance from cities[2].id to cities[4].id
	for(i = 0; i <= j; i++) {
		for(k = 0; k < j; k++) {
			cost[i][k] = distance(cities[i].x, cities[k].x, cities[i].y, cities[k].y);
		}
	}
	
	
	path[0] = cities[0].id;
	pathSize = 1;
	
	//Calculates nearest neighbor
	while(pathSize < (totalCities-1)) {
		for(j = 0; j < (totalCities-1); j++) {
			if(cost[current][j] < dCost) {
				for(k = 0; k < pathSize; k++) {
					if(cities[j].id == path[k]) {
						isVisited = 0;
					}
					else {
						isVisited = 1;
					}
				}
				if(isVisited == 1) {
					dCost = cost[current][j];
					cityNumber = j;
					shortCityID = cities[j].id;
				}
			}
		}
		totalCost += dCost;
		dCost = INT_MAX;
		current =  cityNumber;
		path[pathSize] = shortCityID;
		pathSize++;
	}
	
	strcat(filename, ".tour");
	FILE *outputFile = fopen(filename, "ab+");
	fprintf(outputFile, "%d\n", totalCost);
	
	for (i = 0; i <= pathSize; i++) {
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