#include <stdio.h>
#include <stdlib.h>
#include "webpage.h"


int main() {
    Dlist list;
    int val;
    int opt;
    while (1) {
        system("cls");
        printf("Enter the option \n 1 - New Webpage \n 2 - Go Front\n 3 - Go Back\n 4 - Exit\n");
        printf("Enter the option ");
        scanf("%d", &opt);
        system("cls");
        switch (opt) {
        case 1:
            printf("Inserted new page.");
            printf("%d", list.newpage());
            printf("\n(Press any key to continue)");
            break;

        case 2:
            val = list.front();
            if (val != -1) {
                printf("Moved front. \nCurrent page: %d", val);
            } 
            else {
                printf("Cannot go front.");
            }
            printf("\n(Press any key to continue)");
            break;

        case 3:
            val = list.back();
            if (val != -1) {
                printf("Moved back. \nCurrent page: %d", val);
            } 
            else {
                printf("Cannot go back.");
            }
            printf("\n(Press any key to continue)");
            break;

        case 4:
            return 0;

        default:
            printf("Incorrect input.\n");
            return 0;
        }

        getchar();
        getchar();

    }
    return 0;
}
