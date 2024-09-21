#ifndef __LINKED_LIST__
#define __LINKED_LIST__
#include <stdbool.h>
#define btoa(x) ((x) ? "true" : "false")
typedef struct Node Node;
struct Node {
  int value;
  Node *next;
};
typedef struct LinkedList LinkedList;
struct LinkedList {
  Node *headPtr;
};
LinkedList *newLinkedList(void);
void addNode(LinkedList *ptrLinkedList, int value);
void showList(LinkedList *ptrLinkedList);
Node *getLast(LinkedList *ptrLinkedList);
bool DeleteNode(LinkedList *ptrLinkedList, int pos);
#endif
