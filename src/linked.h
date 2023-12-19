#ifndef LINKED_LIST_LINKED_H
#define LINKED_LIST_LINKED_H

#include <stdint.h>

typedef struct Node {
    int64_t item;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *last;
} List;

List listCreate();

void listDelete(List list);

void listPush(List *list, int64_t element);

void listPushBack(List *list, int64_t element);

void listRemoveFirst(List *list);

bool listRemove(List *list, size_t index);

void listPrint(List list);

#include "linked.c"

#endif