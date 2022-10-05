/*
* File: sorting.c
* Author: vmm
* Description: The module for sorting.
* Date: 2021/2022
*/

void bubbleSort(int indexes[], int size, int (*cmpFunc) (int a, int b)) {
  int i, j, done;
  
  for (i = 0; i < size-1; i++){
    done=1;
    for (j = size-1; j > i; j--) 
      if ((*cmpFunc)(indexes[j-1], indexes[j])) {
	      int aux = indexes[j];
	      indexes[j] = indexes[j-1];
	      indexes[j-1] = aux;
	      done=0;
      }
    if (done) break;
  }
}
