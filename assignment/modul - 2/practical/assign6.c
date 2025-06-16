#include <stdio.h>

int main() {
    int i;

    printf("\nNumbers using continue (skip 3):\n");

    for (i = 1; i <= 10; i++) {
        if (i == 3) {
            continue; // skip when i is 3
        }
        printf("%d ", i);
    }

    return 0;
}
