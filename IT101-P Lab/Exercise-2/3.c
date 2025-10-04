#include <stdio.h>

int main() {
    int start, end, i, j, is_prime;
    scanf("%d %d", &start, &end);
    for (i = start; i <= end; i++) {
        if (i < 2) continue;
        is_prime = 1;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
