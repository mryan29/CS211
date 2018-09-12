#include <stdio.h>

void makeArrayCopy(int [], int [], int);
void myFavoriteSort(int [], int);
int linSearch (int [], int, int, int); // currently doesn't work searching on arr of less than 5
void printArray(int [], int);

/* current issues */
// lin search doesnt work on arr of less than 5 values
// not doing dynamic arrays
// lin search needs to return two values, not one
// lin search's last parameter should be int *, not just int
int main (int argc, char** argv)
{
 int val;

 /* prompt the user for input */
 printf ("Enter in a list of numbers to be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");
 
 // initialize array to max size
 int firstArray[100];
 int size = 0;
 
 /* loop until the user enters -999 */
 scanf ("%d", &val);
 while (val != -999)
   {
    /* store the value into an array */
    firstArray[size] = val;

    /* get next value */
    scanf("%d", &val);
    
    size++;
   }

 /* make a copy of the array of values */
	//secondArray = malloc(sizeof(int) * size);
	int secondArray[size];
	makeArrayCopy(firstArray, secondArray, size);
		
		
	// testing
	for (int i = 0; i < size; i++) {
		printf("%d ", firstArray[i]);
	}
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", secondArray[i]);
	}
	printf("\n");
 
 /* sort one of the arrays */
 myFavoriteSort(secondArray, size);
 printArray(secondArray, size);
 

 /* loop until the user enters -999 */
 printf ("Enter in a list of numbers to use for searching.  \n");
 printf ("End the list with a terminal value of -999\n");
 scanf ("%d", &val);
 int found;
 while (val != -999)
   {
   	printf("val: %d\n", val);
    /* use the value in a linear search on the unsorted array */
    /* print out info about the linear search results  */
	found = linSearch(firstArray, size, val, 0);
	if (found == -1) {
		printf("Target not found at position: -1,\t number of comparisons: %d.\n", size);
	} else {
		printf("Found target with numComparisons: %d, at pos: %d\n", found, found-1);
	}
    /* use the value in a binary search on the unsorted array */

    /* print out info about the binary search results  */

    /* get next value */
    scanf("%d", &val);
   }



 printf ("Good bye\n");
 return 0;
} 


void makeArrayCopy(int fromArray[], int toArray[], int size) {
	for (int i = 0; i < size; i++) {
		//*(toArray + i) = fromArray[i];
		toArray[i] = fromArray[i];
	}
}

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

int linSearch (int arr[], int size, int target, int numComparisons) {
	for (numComparisons = 0; numComparisons < size; numComparisons++) {
		if (arr[numComparisons] == target) {break;
		} else if (arr[numComparisons] != target && numComparisons == size - 1) {
			numComparisons = -1;break;
		}
		numComparisons++;
	}
	return numComparisons;

}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}