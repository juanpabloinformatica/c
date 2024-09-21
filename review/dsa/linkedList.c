#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  LinkedList *ptrLinkedList = newLinkedList();
  for (int i=0;i<10;i++){
      addNode(ptrLinkedList,i);
  }
  showList(ptrLinkedList);
  bool result = DeleteNode(ptrLinkedList,9);
  printf("result: %s\n", btoa(result));
  showList(ptrLinkedList);
  return 0;
}
LinkedList *newLinkedList(void) {
  // would it work or linkedlist will be out of the stack and my malloc is
  // pointing to null after stack done.
  LinkedList *ptrLinkedList = (LinkedList *)malloc(sizeof(LinkedList));
  Node *headPtr = NULL;
  LinkedList linkedList = {.headPtr = headPtr};
  *ptrLinkedList = linkedList;
  return ptrLinkedList;
};
void addNode(LinkedList *ptrLinkedList, int value) {
  Node *ptrNode = (Node *)malloc(sizeof(Node));
  Node node = {.value = value, .next = NULL};
  *ptrNode = node;
  if (ptrLinkedList->headPtr == NULL) {
    ptrLinkedList->headPtr = ptrNode;
  } else {
    Node *last = getLast(ptrLinkedList);
    last->next = ptrNode;
  }
};
bool DeleteNode(LinkedList *ptrLinkedList, int pos) {
  int count = 0;
  Node *tmpPtrNode = ptrLinkedList->headPtr;
  Node *antTmpPtrNode = NULL;
  for (; tmpPtrNode->next != NULL && count != pos;
       antTmpPtrNode = tmpPtrNode, tmpPtrNode = tmpPtrNode->next) {
    count++;
  }
  if (pos != count) {
    return false;
  }
  if (antTmpPtrNode == NULL) {
    antTmpPtrNode = ptrLinkedList->headPtr;
    ptrLinkedList->headPtr = ptrLinkedList->headPtr->next;
    free(antTmpPtrNode);
  } else {
    printf("count: %d", count);
    antTmpPtrNode->next = tmpPtrNode->next;
    tmpPtrNode->next = NULL;
    free(tmpPtrNode);
  }
  return true;
}
Node *getLast(LinkedList *ptrLinkedList) {
  Node *tmpPtrNode = ptrLinkedList->headPtr;
  for (; tmpPtrNode->next != NULL; tmpPtrNode = tmpPtrNode->next) {
    ;
  }
  return tmpPtrNode;
};
void showList(LinkedList *ptrLinkedList) {
  Node *tmpPtrNode = ptrLinkedList->headPtr;
  for (; tmpPtrNode != NULL; tmpPtrNode = tmpPtrNode->next) {
    printf("%d", tmpPtrNode->value);
    if (tmpPtrNode->next != NULL) {
      printf("->");
    }
  }
  printf("\n");
}
