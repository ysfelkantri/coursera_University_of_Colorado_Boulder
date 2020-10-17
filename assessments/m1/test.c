
#include <stdio.h>
#include "stats.h"
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)
// - A function that prints the statistics of an array including minimum, maximum, mean, and median.

//Given an array of data and a length, returns the median value
unsigned char find_median(unsigned char* test, unsigned int size_of_array){
  sort_array(test, size_of_array);
  print_array(test,size_of_array) ;
  if (!(size_of_array%2)) //if even 
	return (test[size_of_array>>1]+test[(size_of_array+1)>>1])>>1 ;
  else //if odd 
	return (unsigned char) (test[(size_of_array+1)>>1])>>1 ;
 
}

unsigned char find_mean(unsigned char* test, unsigned int size_of_array) {
  unsigned char result=0 ;
  for ( int i; i<size_of_array; i++){
    result += test[i];
  }
   result = result/size_of_array;
  return size_of_array ;
}

//Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
void sort_array(unsigned char* test, unsigned int size_of_array) {
  int temp = 0;
  for (int i=0; i<size_of_array; i++){
    for (int j=0; j<size_of_array; j++){
	  if (test[j]<=test[j+1]){
	    temp = test[j];
 		test[j]=test[j+1];
		test[j+1]=temp;
	  }
    }
  }
  return;
}

void print_array(unsigned char* test, unsigned int size_of_array){
  printf("values of my array are : \n*******************************************\n");
  for (int i =0 ;i<size_of_array;i++){
    printf("%d",i);
    printf("value at index %d : %d \n",i,test[i]);
  }
  printf("\n*******************************************\n");
  return;
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  
  sort_array(test,SIZE);
  print_array(test,SIZE) ;
  
  //unsigned char c= find_median(test,SIZE);
  //printf("%d",c);
  //find_mean(test,SIZE);
  //print_array(test,SIZE);
  //printf("mean  \t : %d \n", find_mean(test,SIZE));
  //printf("median    \t : %d \n", find_median(test,SIZE));
  
}

/* Add other Implementation File Code Here */
