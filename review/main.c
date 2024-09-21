#include <stdio.h>
#include <stdlib.h>
int main() {

  int N;
  printf("How many numbers:\n");
  scanf("%i", &N);
  int *ptrArray = (int *)malloc(sizeof(int) * N);
  int *ptrArrayTemp = ptrArray;
  int i = 0;
  int c = 0;
  while (i < sizeof(int) * N) {
    *ptrArrayTemp = c;
    c++;
    ptrArrayTemp++;
    i += sizeof(int);
  }
  i = 0;
  ptrArrayTemp = ptrArray;
  while (i < sizeof(int) * N) {
    printf("number: %i", *ptrArrayTemp);
    printf("\n");
    ptrArrayTemp++;
    i += sizeof(int);
  }
  return 0;
}
