#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void bubble_sort(int arr[],int n);
void heapify(int arr[], int i);
void build_heap(int arr[], int n);
void heap_sort(int arr[],int n);
void quick_sort(int arr[], int left, int right);
void merge_sort(int arr[], int left, int right);
float execution_time(void (*f)(int[], int),int,int[]);
float execution_time_3variable(void (*f)(int[], int, int),int,int[], int);
int heap_size;
int max_size = 1000000;
int main(void) {
  int decision = 0;
  while(decision == 0) {
    printf("%s", "Enter 1 for going with custom size array, 2 for powers of tens\n");
    scanf("%d", &decision);
    printf("%d\n", decision);
    if (decision != 1 && decision != 2) {
      printf("%s", "Enter 1 for going with custom size array, 2 for powers of tens\n");
      decision = 0;
    }
  }
  switch (decision) {
    case 1:
      {
        int array_size;
        clock_t s, e;
        heap_size = array_size;
        printf("%s", "Please enter an integer for array size: ");
        scanf("%d", &array_size);
        int arr[array_size];
        for(int i=0;i<array_size;i++) {
          arr[i] = rand();
        }
        /*
        for(int i=0;i<array_size; i++) {
          printf("%d\n", arr[i]);
        }*/
        double exectime;
        
        exectime = execution_time(insertion_sort,array_size, arr);
        exectime = exectime / CLOCKS_PER_SEC;
        printf("%s%f%s", "Insertion Sort:",exectime, "\n");

        exectime = execution_time(selection_sort,array_size, arr);
        exectime = exectime / CLOCKS_PER_SEC;
        printf("%s%f%s", "Selection Sort:",exectime, "\n");

        exectime = execution_time(bubble_sort,array_size, arr);
        exectime = exectime / CLOCKS_PER_SEC;
        printf("%s%f%s", "Bubble Sort",exectime, "\n");

        exectime = execution_time(heap_sort,array_size, arr);
        exectime = exectime / CLOCKS_PER_SEC;
        printf("%s%f%s", "Heap Sort",exectime, "\n");

        exectime = execution_time_3variable(quick_sort, 0, arr,array_size-1);
        exectime = exectime / CLOCKS_PER_SEC;
        printf("%s%f%s", "Quick Sort: ",exectime, "\n");
        
        exectime = execution_time_3variable(merge_sort, 0, arr,array_size-1);
        exectime = exectime / CLOCKS_PER_SEC;
        printf("%s%f%s", "Merge Sort: ",exectime, "\n");
        break;
      }
    case 2:
      {
        int array_size = 10;
        clock_t s, e;
        heap_size = array_size;
        double exectime;
        for(int i=1; i<7; i++) {
          int* arr;
          //array_size = int_exponential(10, i);
          arr = (int *)malloc(array_size * sizeof(int));
          for(int j=0;j<array_size;j++) {
            arr[j] = rand();
          } //arr is available to use with randomly assigned integers 
          
         /*
          for(int k = 0; k<array_size; k++) {
            if ((k + 100) > array_size) { printf("%d%s%d%s", k, "element is: ", arr[k], "\n"); }
          }*/
          printf("%s%d%s", "Size of array: ", array_size, "\n");
          
          exectime = execution_time(insertion_sort,array_size, arr);
          exectime = exectime / CLOCKS_PER_SEC;
          printf("%s%f%s", "Insertion Sort:",exectime, "\n");
          
          exectime = execution_time(selection_sort,array_size, arr);
          exectime = exectime / CLOCKS_PER_SEC;
          printf("%s%f%s", "Selection Sort:",exectime, "\n");
          
          exectime = execution_time(bubble_sort,array_size, arr);
          exectime = exectime / CLOCKS_PER_SEC;
          printf("%s%f%s", "Bubble Sort: ",exectime, "\n");
          
          exectime = execution_time(heap_sort,array_size, arr);
          exectime = exectime / CLOCKS_PER_SEC;
          printf("%s%f%s", "Heap Sort: ",exectime, "\n");

          exectime = execution_time_3variable(quick_sort, 0, arr,array_size-1);
          exectime = exectime / CLOCKS_PER_SEC;
          printf("%s%f%s", "Quick Sort: ",exectime, "\n");
          
          exectime = execution_time_3variable(merge_sort, 0, arr,array_size-1);
          exectime = exectime / CLOCKS_PER_SEC;
          printf("%s%f%s", "Merge sort: ",exectime, "\n");
          free(arr);
          array_size = array_size * 10;
        }
        break;
      }
    }
}

float execution_time(void (*f)(int*, int),int n,int arr[]) {
  clock_t start = clock();
  (*f)(arr, n);
  clock_t end = clock();
  return end - start;
}

float execution_time_3variable(void (*f)(int[], int, int),int left,int arr[], int right) {
  clock_t start = clock();
  (*f)(arr, left, right);
  clock_t end = clock();
  return end - start;
}

void insertion_sort(int arr[], int n) {
  int key,k;
  for(int i = 1; i < n; i++) {
    key = arr[i];
    for(k = i-1; k>=0 && key <= arr[k]; k--) {
      arr[k+1] = arr[k];
    }
    arr[k+1] = key;
  }
}

void selection_sort(int arr[],int n) {
  int index, j, min;
  for(int i = 0; i< (n-1); i++) {
    min = arr[n-1];
    index = n-1;
    for(j = i; j< (n-1); j++) {
      if(arr[j] < min) {
        min = arr[j];
        index = j;
      }
    }
    if (i != index) {
      arr[index] = arr[i];
      arr[i] = min;
    }
  }
}

void bubble_sort(int arr[],int n) {
  int temp, k, move;
  for(move = 0; move < (n-1); move++) {
    for(k = 0; k < (n-1-move); k++) {
      if(arr[k] > arr[k+1]) {
        temp = arr[k];
        arr[k] = arr[k+1];
        arr[k+1] = temp;
      }
    }
  }
}

void heapify(int arr[], int i) {
  int left(int i);
  int right(int i);

  int left_child, right_child, max, temp;
  left_child = left(i);
  right_child = right(i);
  if((left_child <= heap_size) && (arr[left_child] > arr[i])) {
    max = left_child;
  }
  else {
    max = i;
  }
  if((right_child <= heap_size) && (arr[right_child] > arr[max])) {
    max = right_child;
  }
  if (max != i) {
    temp = arr[max];
    arr[max] = arr[i];
    arr[i] = temp;
    heapify(arr, max);
  }
}

int left(int i) {
  return (2*i+1);
}

int right(int i) {
  return (2*i+2);
}

void build_heap(int arr[], int n) {
  int i;
  heap_size = n-1;
  for(i = (n-1)/2; i >= 0; i--) {
    heapify(arr,i);
  }
}

void heap_sort(int arr[], int n) {
  int i, temp;
  build_heap(arr, n);
  for(i = n-1; i >= 1; i--) {
    temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;
    heap_size--;
    heapify(arr, 0);
  }
}

void quick_sort(int arr[], int left, int right) {
  int k, j, q,temp;
  k = left;
  j = right;
  
  q = arr[(left+right)/2];

  do {
    while((arr[k] < q) && (k < right)) {
      k++;
    }
    while((arr[j] > q) && (j > left)) {
      j--;
    }
    if (k <= j) {
      temp = arr[k];
      arr[k] = arr[j];
      arr[j] = temp;
      k++;
      j--;
    }
  }while(k <= j);
  
  if (left < j) {
    quick_sort(arr, left, j);
  }
  if (k < right) {
    quick_sort(arr, k, right);
  }
}

void merge_sort(int arr[], int left, int right) {
  void merge(int arr[], int left, int k, int right);

  int k;
  if (left < right) {
    k = (left + right)/2;
    merge_sort(arr, left, k);
    merge_sort(arr, k+1, right);

    merge(arr, left, k, right);
    }
  }

void merge(int arr[], int left, int k, int right) {
  int i, j, l = 0;
  int* temp_arr;
  temp_arr = (int *)malloc(max_size * sizeof(int));

  for (i=left, j = k+1; (i <=k) && (j <= right);) {
    if (arr[i] < arr[j]) {
      temp_arr[l] = arr[i];
      i++;
      l++;
    }
    else {
      temp_arr[l] = arr[j];
      j++;
      l++;
    }
  }
  while(i <=k) {
    temp_arr[l] = arr[i];
    i++;
    l++;
  }
  while (j <= right) {
    temp_arr[l] = arr[j];
    j++;
    l++;
  }
  for (i = left, l = 0; i<= right; i++, l++) {
    arr[i]= temp_arr[l];
  }
}
