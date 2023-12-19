#include "linked.h"

const char *HELP =
        "q - Quit \n"
        "p <element> - Push\n"
        "r <index> - Remove\n"
        "f <amount> - Fill\n"
        "h - Help\n";

void fill(List *list, size_t amount) {
    while (amount > 0) {
        amount--;
        listPush(list, (int64_t) amount);
    }
}

int main() {
    List list = listCreate();

    printf("%s", HELP);
    while (1) {
        listPrint(list);

        char input;
        printf("> ");
        scanf(" %c", &input);

        switch (input) {
            case 'q':
                listDelete(list);
                return 0;
            case 'p': {
                int64_t element;
                scanf(" %lld", &element);
                listPush(&list, element);
                break;
            }
            case 'r': {
                size_t index;
                scanf(" %lld", &index);
                listRemove(&list, index);
                break;
            }
            case 'f': {
                size_t amount;
                scanf("%lld", &amount);
                fill(&list, amount);
                break;
            }
            case 'h':
                printf("%s", HELP);
                break;
            default:
                printf("Invalid option: '%c'\n", input);
        }
    }
}
