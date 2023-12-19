#include "stdio.h"
#include <stdint.h>
#include <stdlib.h>

#include "linked.h"

List listCreate() {
    List list = {
            .head = NULL,
            .last = NULL
    };

    return list;
}

void listDelete(List list) {
    Node *current = list.head;

    while (current) {
        Node *ptr = current->next;

        free(current);
        current = ptr;
    }
}

void listPush(List *list, int64_t element) {
    Node *new_node = malloc(sizeof(Node));
    new_node->item = element;
    new_node->next = list->head;

    if (!list->head) {
        list->last = new_node;
    }

    list->head = new_node;
}

void listPushBack(List *list, int64_t element) {
    Node *new_node = malloc(sizeof(Node));
    new_node->item = element;
    new_node->next = NULL;

    if (list->last) {
        list->last->next = new_node;
    } else {
        list->head = new_node;
        list->last = new_node;
    }
}

void listRemoveFirst(List *list) {
    if (list->head) {
        list->head = list->head->next;
    }
}

bool listRemove(List *list, size_t index) {
    Node *current = list->head;

    if (index == 0) {
        listRemoveFirst(list);
        return true;
    }

    while (index >= 0 && current && current->next) {

        if (index == 0) {
            *current = *current->next;
            return true;
        }

        index--;
        current = current->next;
    }

    return false;
}

void listPrint(List list) {
    Node *current = list.head;

    while (current) {
        printf("%lld ", current->item);

        current = current->next;
    }

    printf("\n");
}
