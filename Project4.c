#include <stdio.h>
#include <string.h>
#include <math.h>

//declare algorithm functions here
int distance(int xOne, int xTwo, int yOne, int yTwo);

struct City {
	int id;
	int x;
	int y;
};


int main(int argc, char *argv[]) {
	FILE *inputFile = fopen(argv[2], "r");
	int i = 0, j = 0, k = 0, l = 0, ans = 0, num, someNumber, n;
	char *out;
	struct City cities[n]; //change n to be the number of cities or update this the be dynamic
	
	strcpy(out, argv[2]);
	strcat(out, ".tour");
	
	while(fscanf(inputFile, "%d", &num) == 1) {
		k = i - 1;
		
		if(k % 3 == 0) {
			cities[j].y = num;
			j++;
		}
		
		else if(k % 2 == 0 && k % 3 != 0) {
			cities[j].x = num;
		}
		
		else {
			cities[j].id = num;
		}
		
		i++;
	}
	fclose(inputFile);
	
	//Cost matrix creater. Ex. cost[2][4] = the distance from cities[2].id to cities[4].id
	int cost[j][j];
	for(i = 0; i <= j; i++) {
		for(k = 0; k < j; k++) {
			cost[i][k] = distance(cities[i].x, cities[k].x, cities[i].y, cities[k].y);
		}
	}
	
	
	if(j < someNumber ) { //change someNumber to real value
		//call algorithm
	}
	
	else if(j > someNumber && j < someNumber) { //change someNumber to real value
		//call algorithm
	}
	
	//... more if else statements for the number of algorithms to be thorough
	
	else {
		//more fun stuff goes here
	}
	
	FILE *outputFile = fopen(out, "ab+");
	i = 0;
	fprintf(outputFile, "%d\n", &ans);
	
	while (i <= j) {
		fprintf(outputFile, "%d\n", &cities[i].id);
	}
	
	fprintf(outputFile, "\n");
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