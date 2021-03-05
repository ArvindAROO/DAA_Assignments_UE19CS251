
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int compBubble; 
unsigned long long int compQuick;
unsigned long long int compsMerge;
unsigned long long int compSelection;

void swap(long long int*, long long int*);


void bubbleSort(long long int*, long int);


unsigned long long int partition (long long int*, long int, long int);
void quickSort(long long int*, long int, long int);


void merge(long long int*, long int, long int, long int);
void mergeSort(long long int*, long int, long int);


void selectionSort(long long int*, long int);