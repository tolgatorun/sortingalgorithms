#include <stdio.h>
#include <stdlib.h>
//int int_exponential(int x, int y);

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
        printf("%s", "Please enter an integer for array size: ");
        scanf("%d", &array_size);
        int arr[array_size];
        for(int i=0;i<array_size;i++) {
          arr[i] = rand();
        }
        for(int i=0;i<array_size; i++) {
          printf("%d\n", arr[i]);
        }
      }
    case 2:
      {
        int siz = 10;
        for(int i=1; i<7; i++) {
          int* arr;
          //siz = int_exponential(10, i);
          arr = (int *)malloc(siz * sizeof(int));
          for(int j=0;j<siz;j++) {
            arr[j] = rand();
          } //arr is available to use with randomly assigned integers 
          
         /*
          for(int k = 0; k<siz; k++) {
            if ((k + 100) > siz) { printf("%d%s%d%s", k, "element is: ", arr[k], "\n"); }
          }
          */
          printf("%d%s", siz * sizeof(int), "\n");
          free(arr);
          siz = siz * 10;
        }
      }
    }
}
/*
int int_exponential(int x, int y) {
  int start = 1;
  for(int i =0; i<y; i++) {
  start = start * x;
  }
  return start;
}
*/