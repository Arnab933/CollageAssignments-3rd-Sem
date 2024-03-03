#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int*arr,int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if(arr[j-1] > arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selectionSort(int* arr,int n){
    int min_idx = 0;
    for (int i = 0; i < n; i++)
    {
        min_idx = i;
        for (int j = i+1; j < n - i ; j++)
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int partition(int* arr,int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    if(low < high){
        while(arr[i] <= pivot && i <= high)
            i++;
        while(arr[j] > pivot && j >= low)
            j--;
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int* arr,int low,int high){
    if(low < high){
        int pivotIdx = partition(arr,low,high);
        quickSort(arr,low,pivotIdx - 1);
        quickSort(arr,pivotIdx + 1,high);
    }
}

void insertionSort(int* arr,int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = i;j>0; j--)
        {
            if(arr[j-1] > arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp; 
            }
        }
    }
}


void mergeSort(int* arr,int s,int e){
    if(s >= e)
        return ;
    int mid = s +(e - s)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    
    int len1 = mid-s+1;
    int len2 = e - mid;
    
    int *leftArr = (int*)calloc(len1,sizeof(int));
    int *rightArr = (int*)calloc(len2,sizeof(int));

    for (int i = 0; i < len1; i++)
    {
        leftArr[i] = arr[s+i];
    }

    for (int i = 0; i < len2; i++)
    {
        rightArr[i] = arr[mid+1+i];
    }
    
    int i = 0,j = 0;
    int k = s;

    while(i < len1 && j < len2){
        if(leftArr[i] < rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while (i < len1)
    {
        arr[k++] = leftArr[i++];
    }
    while (j < len2)
    {
        arr[k++] = rightArr[j++];
    }
}


int main()
{
 printf("Enter the number of elements of the array:\n");
 int n;
 scanf("%d",&n);
 int arr[n];
 printf("Enter elements of the array:\n");
 for (int i = 0; i < n; i++)
 {
    scanf("%d",&arr[i]);
 }
 printf("Enter your choice:\n");
 int choice;
 printf(" 1->Insertion sort \n 2->Bubble sort \n 3->Selection sort \n 4->Quick sort \n 5->Merge sort\n");
 scanf("%d",&choice);
 switch (choice)
 {
 case 1:
    insertionSort(arr,n);
    break;
 case 2:
    BubbleSort(arr,n);
    break;
 case 3:
    selectionSort(arr,n);
    break;
 case 4:
    quickSort(arr,0,n-1);
    break;
 case 5:
    mergeSort(arr,0,n-1);
    break;
 default:
    printf("Pls enter a valid choice");
    break;
 }
 printf("The sorted array is:\n");
 for (int i = 0; i < n; i++)
 {
    printf("%d ",arr[i]);
 }
 return 0;
}
