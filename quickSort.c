#include<stdio.h>
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int parition(int arr[], int low, int high){
  int pivot =  arr[high];
  int i = low - 1;
  int j;
  for(j = low; j<high; j++){
    if(arr[j]<pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[high], &arr[i+1]);
  return i+1;
}

void quickSort(int arr[], int low, int high){
  if(low<high){
    int part = parition(arr, low, high);
    quickSort(arr, part+1, high);
    quickSort(arr, low, part-1);
  }
}

void display(int arr[], int n){
  int i;
  for(i = 0; i<n; i++){
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main(){
  int n,i;
  scanf("%d", &n);
  int arr[n];
  for(i = 0; i<n; i++){
    scanf("%d",&arr[i]);
  }
  printf("Unsorted Array: \n");
  display(arr, n);

  printf("Sorted Array: \n");
  quickSort(arr, 0, n-1);
  display(arr, n);
  return 0;
}
