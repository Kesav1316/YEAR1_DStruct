#include <stdio.h>
#include "q3.h"

int main() {
    BST tree;
    int n, target;
    printf("Enter the number of elements ");
    scanf("%d", &n);
    printf("Enter the elements ");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        tree.insert(num);
    }
    printf("Enter the number ");
    scanf("%d", &target);
    tree.PrevandNext(target);

    return 0;
}
