#include"server.h"


int main(){
	long long int n = 50000;
	printf("sizeOfArr,Time of Bubble, Time of Merge, Time of Quick, Time of Selection, comparisons of Bubble, comparisons of Merge, comparisons of Quick, comparisons of Selection\n");

	while (n < 1000001) {
		long long int *arrForBubbleSort = (long long int*)calloc(sizeof(long long int), n);
        long long int *arrForMergeSort = (long long int*)calloc(sizeof(long long int), n);
        long long int *arrForQuickSort = (long long int*)calloc(sizeof(long long int), n);
        long long int *arrForSelectionSort = (long long int*)calloc(sizeof(long long int), n);

		
        time_t t;
        srand((unsigned) time(&t));
        //seed the randomizer so that we get pseudo random values instead of same pattern
		for (int i = 0; i < n; i++) {
			unsigned long long int no = rand() % n + 1;
			arrForBubbleSort[i] = no;
			arrForMergeSort[i] = no;
			arrForQuickSort[i] = no;
            arrForSelectionSort[i] = no;
		}

		clock_t bubbleStartTimeStamp, bubbleEndTimeStamp, MergeStartTimeStamp, MergeEndTimeStamp, QuickStartTimeStamp, QuickEndTimeStamp, selectionEndTimeStamp, selectionStartTimeStamp;

		//Bubble sort
		bubbleStartTimeStamp = clock();
        compBubble = 0;
        bubbleSort(arrForBubbleSort, n);
		unsigned long long int bubbleComparisons = compBubble;
		bubbleEndTimeStamp = clock();
		

        //Merge Sort
        MergeStartTimeStamp = clock();
        compsMerge = 0;
		mergeSort(arrForMergeSort, 0, n-1);
        unsigned long long int mergeComparisons = compsMerge;
		MergeEndTimeStamp = clock();
		
		//Quick Sort
        compQuick = 0;
		QuickStartTimeStamp = clock();
		quickSort(arrForQuickSort,0,n-1);
        unsigned long long int quickComparisons = compQuick;
		QuickEndTimeStamp = clock();
		
		//Selection sort
        compSelection = 0;
		selectionStartTimeStamp = clock();
		selectionSort(arrForSelectionSort, n);
        unsigned long long int selectionComparisons = compSelection;
		selectionEndTimeStamp = clock();
		
        printf("%li", n);
        printf(", %lf",(double)(bubbleEndTimeStamp - bubbleStartTimeStamp)/1000);
        printf(", %lf",(double)(MergeEndTimeStamp - MergeStartTimeStamp) /1000);
		printf(", %lf",(double)(QuickEndTimeStamp - QuickStartTimeStamp) /1000);
		printf(", %lf,",(double)(selectionEndTimeStamp - selectionStartTimeStamp) /1000);

        printf(" %llu, %llu, %llu, %llu\n",
			bubbleComparisons,
			mergeComparisons,
			quickComparisons,
            selectionComparisons
        );

		n += 50000;
        free(arrForBubbleSort);
        free(arrForMergeSort);
        free(arrForQuickSort);
        free(arrForSelectionSort);
	}

	return 0;
}

