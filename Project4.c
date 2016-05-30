#include <stdio.h>
#include <string.h>

//declare algorithm functions here

struct City {
	int id;
	int x;
	int y;
};


int main(int argc, char *argv[]) {
	FILE *inputFile = fopen(argv[2], "r");
	int i = 0, j = 0, k = 0, ans = 0, num, someNumber, n;
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