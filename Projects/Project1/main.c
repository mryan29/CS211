#include <stdio.h>
#include <stdlib.h>

/* FUNCTION DECLARATIONS */
void makeArrayCopy(int [], int [], int);
void myFavoriteSort(int [], int);
int linSearch (int [], int, int, int); 
int binSearch(int [], int, int, int*);
void printArray(int [], int);

int main (int argc, char** argv)
{

 	/* prompt the user for input */
 	system("clear");
 	printf ("\nEnter in a list of numbers to be stored in a dynamic array.\n");
 	printf ("End the list with the terminal value of -999\n");
 
 	// initialize array to max size
 	int val; 					// stores user input
 	int sz = 100;				// initial size of array
 	int size = 0;				// keep track of how many elements to store in array
 	int *firstArray = (int*) malloc(sizeof(int) * sz); 	// dynamically allocate array
 
 
 	/* loop until the user enters -999 */
 	scanf ("%d", &val);
 	if (val == -999) { printf("Invalid input. List must be of minimum size 1. Exiting program.\n"); return 0; }		// added to handle empty input
 	
	while (val != -999) {
		
    	/* store the value into an array */
    	if (size >= sz) {
    		int* tmp = (int *) malloc(sizeof(int) * (sz * 2));
    		for (int i = 0; i < sz; i++) {
    			tmp[i] = firstArray[i];
    		}
    		free(firstArray);
    		firstArray = tmp;
    		sz = sz * 2;
    	}
    	firstArray[size] = val;

   		/* get next value */
    	scanf("%d", &val);
    
    	size++;
   }

 	/* make a copy of the array of values */
	int* secondArray = (int*) malloc(sizeof(int) * size); // size == sz???
	makeArrayCopy(firstArray, secondArray, size);
		
	// testing
	printf("\nFirst Array:\t\t\t");
	for (int i = 0; i < size; i++) {
		printf("%d ", firstArray[i]);
	}
	printf("\n");
	printf("Second Array (Copied):\t\t");
	for (int i = 0; i < size; i++) {
		printf("%d ", secondArray[i]);
	}
	printf("\n"); 
 
 	/* sort one of the arrays */
	myFavoriteSort(secondArray, size);
 	printf("Second Array (Sorted):\t\t");
 	printArray(secondArray, size);
 	printf("\n\n");
 

 	/* loop until the user enters -999 */
 	printf ("Enter in a list of numbers to use for searching.  \n");
 	printf ("End the list with a terminal value of -999\n");
 	scanf ("%d", &val);
 	if (val == -999) { printf("Invalid input. List must be of minimum size 1. Exiting program.\n"); return 0; }		// added to handle empty input
 
 	while (val != -999)
	{
		int linPos = 0, linRes = 0;
		int binPos = 0, binRes = 0;
		
   		printf("\nTarget: %d\n", val);
   		
    	/* use the value in a linear search on the unsorted array */
    	printf("*Linear Search*\n");
		linPos = linSearch(firstArray, size, val, 0);
		
		/* print out info about the linear search results  */
		if (linPos == -1) {
			printf("Target not found at position: -1,\t number of comparisons: %d.\n", size);
		} else {
			printf("Found target with numComparisons: %d, at pos: %d\n", linPos+1, linPos);
		}
	
    	/* use the value in a binary search on the sorted array */
		printf("*Binary Search*\n");
		binRes = binSearch(secondArray, size, val, &binPos);
		
		/* print out info about the binary search results  */
		if (binRes == -1) {
			printf("Target not found at position: -1,\t number of comparisons: %d.\n\n", size);
		} else {
			printf("Found target with numComparisons: %d, at pos: %d\n\n", binRes+1, binRes);
		}
		
    	/* get next value */
   		scanf("%d", &val);
	}

	printf ("Good bye\n");
 	return 0;
 } 


/* FUNCTION DEFINITIONS */

/* makeArrayCopy */
void makeArrayCopy(int fromArray[], int toArray[], int size) {
	for (int i = 0; i < size; i++) {
		//*(toArray + i) = fromArray[i];
		toArray[i] = fromArray[i];
	}
}

/* myFavoriteSort */
void myFavoriteSort(int arr[], int size) {
	for (int j = 0; j < size - 1; j++) {
		for (int i = 0; i < size - j - 1; i++) {
			if (arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			} 
		}
	}
}

/* linSearch */
int linSearch (int arr[], int size, int target, int numComparisons) {
	
	for (numComparisons = 0; numComparisons < size; numComparisons++) {
		
		if (arr[numComparisons] == target) {break;
		} else if (arr[numComparisons] != target && numComparisons == size - 1) {
			numComparisons = -1;break;
		}
		
	}
	
	return numComparisons;
}

/* binSearch */
int binSearch(int arr[], int size, int target, int *numComparisons) {
	
	int lower = 0; 			// lower bound (first element)
	int upper = size - 2;	// upper bound (last element)
	
	
	while (lower <= upper) {
	
		int midpt = (lower + upper)/2;		// midpoint of array
		*numComparisons++;	
		
		if (target > arr[midpt]) { lower = midpt + 1; }		// search upper half of array
		
		else if (target == arr[midpt]) {					// return midpoint if equal
			return midpt;
			break;
		} 
		
		else { upper = midpt - 1; }							// search lower half of array
	}
	
	if (lower > upper) { return -1; } 						// if not found, return -1
	
}

/* helper print function */
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}