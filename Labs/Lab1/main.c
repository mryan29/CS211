#include <stdio.h>

#define size_t SIZE_MAX

int main (int argc, char** argv)
{
 int val;

 /* prompt the user for input */
 printf ("Enter in a list of numbers ito be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");
 
 // initialize array to max size
 int firstArray[SIZE_MAX];
 int size = 0;
 
 /* loop until the user enters -999 */
 scanf ("%d", &val);
 while (val != -999)
   {
    /* store the value into an array */
    firstArray[i] = val;
    

    /* get next value */
    scanf("%d", &val);
    
    size++;
   }

 /* make a copy of the array of values */
	secondArray = malloc(sizeof(int) * size);
	
	for (int i = 0; i < size; i++) {
		*(secondArray + i) = firstArray[i];
	}
		
 /* sort one of the arrays */
 

 /* loop until the user enters -999 */
 printf ("Enter in a list of numbers to use for searching.  \n");
 printf ("End the list with a terminal value of -999\n");
 scanf ("%d", &val);
 while (val != -999)
   {
    /* use the value in a linear search on the unsorted array */

    /* print out info about the linear search results  */

    /* use the value in a binary search on the unsorted array */

    /* print out info about the binary search results  */

    /* get next value */
    scanf("%d", &val);
   }


 printf ("Good bye\n");
 return 0;
} 