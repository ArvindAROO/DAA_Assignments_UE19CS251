#include"server.h"
void swap(long long int* ele1,long long int* ele2){
    int tmp = *ele1;
	*ele1 = *ele2;
	*ele2 = tmp;
}


void bubbleSort(long long int a[], long int n){
	for (unsigned long long int outerLoop = 0; outerLoop < n - 1; outerLoop++) {
		for (unsigned long long int innerLoop = 0; innerLoop < n - outerLoop - 1; innerLoop++) {
            compBubble++;
			if (a[innerLoop] > a[innerLoop + 1]) {
				swap(&a[innerLoop + 1], &a[innerLoop]);
			}
		}
	}
}



unsigned long long int partition (long long int arr[],long int lowerLimit,long int upperLimit){
    long int pivot = arr[upperLimit];
    long int index = (lowerLimit - 1);

    for (long int iter = lowerLimit; iter <= upperLimit- 1; iter++)
    {
        compQuick++;
        if (arr[iter] < pivot)
        {
            index++; 
            swap(&arr[index], &arr[iter]);
        }
    }
    swap(&arr[index + 1], &arr[upperLimit]);
    return (index + 1);
}
void quickSort(long long int arr[], long int lowerLimit, long int upperLimit){
    if (lowerLimit < upperLimit)
    {
        long int partitionIndex = partition(arr, lowerLimit, upperLimit);

        quickSort(arr, lowerLimit, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, upperLimit);
    }
}




void merge(long long int arr[],long int leftIndex,long int mid,long int rightIndex){
    int i, j, k;
    int n1 = mid - leftIndex + 1;
    int n2 = rightIndex - mid;

    unsigned long long int LeftArray[n1], RighArray[n2];

    for (i = 0; i < n1; i++)
        LeftArray[i] = arr[leftIndex + i];
    for (j = 0; j < n2; j++)
        RighArray[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = leftIndex;
    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RighArray[j]) {
            arr[k] = LeftArray[i];
            i++;
        }
        else {
            arr[k] = RighArray[j];
            j++;
        }
        k++;
        compsMerge++;
    }

    
    while (i < n1) {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = RighArray[j];
        j++;
        k++;
    }
}

void mergeSort(long long int arr[],long int leftIndex,long int rightIndex){
    if (leftIndex < rightIndex) {
        long int mid = leftIndex + (rightIndex - leftIndex) / 2;

        mergeSort(arr, leftIndex, mid);
        mergeSort(arr, mid + 1, rightIndex);

        merge(arr, leftIndex, mid, rightIndex);
    }
}


void selectionSort(long long int arr[], long int n){
	long int i, j, indexOfMin;
    for (i = 0; i < n - 1; i++) {

		indexOfMin = i;

		for (j = i + 1; j < n; j++){
            compSelection++;
			if (arr[j] < arr[indexOfMin])
				indexOfMin = j;
        }
		swap(&arr[indexOfMin], &arr[i]);
	}
}
