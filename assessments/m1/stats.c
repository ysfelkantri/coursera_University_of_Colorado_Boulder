/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char* test, unsigned int size_of_array){
  printf("*****************************************\n");
  printf("*\tmedian  \t : %d \t\t*\n", find_median(test,size_of_array));
  printf("*\tmean    \t : %d \t\t*\n", find_mean(test,size_of_array));
  printf("*\tmaximum \t : %d \t\t*\n", find_maximum(test,size_of_array));
  printf("*\tminimum \t : %d \t\t*\n", find_minimum(test,size_of_array));
  printf("*****************************************\n");
}

//Given an array of data and a length, prints the array to the screen
void print_array(unsigned char* test, unsigned int size_of_array){
  printf("\tvalues of my array are : \n*****************************************\n");
  for (int i = 0;i<size_of_array;i++)
    printf("*\tvalue at index %d : %d\t\t*\n",i,test[i]);
  printf("*****************************************\n");
}

//Given an array of data and a length, returns the median value
unsigned char find_median(unsigned char* test, unsigned int size_of_array){
  unsigned char* sorted_array = (unsigned char*) malloc(sizeof(unsigned char)*size_of_array);
  for (int i = 0; i<size_of_array; i++)
    sorted_array[i] = test[i] ;
  sort_array(sorted_array, size_of_array);
  if (!(size_of_array%2)) //if even 
	return (sorted_array[size_of_array>>1]+sorted_array[(size_of_array+1)>>1])>>1 ;
  else //if odd 
	return (unsigned char) (sorted_array[(size_of_array+1)>>1])>>1 ;
}


// Given an array of data and a length, returns the mean
unsigned char find_mean(unsigned char* test, unsigned int size_of_array) {
  short int sum =0 ;
  for ( int i = 0; i<size_of_array; i++)
    sum += test[i];
  return (unsigned char)(sum/size_of_array) ;
}

//Given an array of data and a length, returns the maximum
unsigned char find_maximum(unsigned char* test, unsigned int size_of_array) {
  unsigned char max = 0 ;
  for (int j = 0; j<size_of_array; j++)
    if(max < test[j]) 
	  max = test[j] ;
  return (unsigned char) max ;
}

//Given an array of data and a length, returns the minimum
unsigned char find_minimum(unsigned char* test, unsigned int size_of_array) {
  unsigned char min = 255 ;
  for (int j = 0; j<size_of_array; j++)
    if(min > test[j]) 
	  min = test[j] ;
  return (unsigned char) min ;
}

//Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
void sort_array(unsigned char* test, unsigned int size_of_array) {
  unsigned char temp = 0 ;
  for (int i = 0; i<size_of_array; i++){
    for (int j = 0; j<size_of_array; j++){
	  if (test[j]<=test[j+1]){
	    temp = test[j];
 		test[j]=test[j+1];
		test[j+1]=temp;
	  }
    }
  }
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Statistics and Printing Functions */
  print_statistics(test,SIZE);
  print_array(test,SIZE);
}

/* Add other Implementation File Code Here */
