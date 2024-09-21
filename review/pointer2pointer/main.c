#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORDNUMBERS 10
#define MAXWORDLENGTH 30
char *words[MAXWORDNUMBERS];
int wordsIndex = 0;
void printWords(void);
void sortArray(void);
void readFile(void);
void writeToFile(void);

int main() {
  readFile();
  sortArray();
  writeToFile();
  return 0;
}
// void sortarray(){
// }
void sortArray(void) {
  int maxLengthWord = strlen(words[0]);
  char *tempPointer;
  for (int i = 0; i < MAXWORDNUMBERS; i++) {
    for (int j = i + 1; j < MAXWORDNUMBERS - 1; j++) {
      if (strlen(words[j]) < strlen(words[i])) {
        tempPointer = words[i];
        words[i] = words[j];
        words[j] = tempPointer;
      }
    }
  }
}
void writeToFile(void) {
  FILE *ptrFile;
  ptrFile = fopen("./wordsOrdered.txt", "w");
  for (int i = 0; i < MAXWORDNUMBERS; i++) {
    fprintf(ptrFile, "%s", words[i]);
  }
  fclose(ptrFile);
}
void printWords(void) {
  for (int i = 0; i < MAXWORDNUMBERS; i++) {
    printf("%s", words[i]);
  }
}
void readFile(void) {
  FILE *ptrFile;
  ptrFile = fopen("./words.txt", "r");
  char temporal[MAXWORDLENGTH];
  while (fgets(temporal, MAXWORDLENGTH, ptrFile) != NULL) {
    char *ptrTemporal = (char *)malloc(sizeof(char) * MAXWORDLENGTH + 1);
    strcpy(ptrTemporal, temporal);
    words[wordsIndex++] = ptrTemporal;
  }
  fclose(ptrFile);
}
