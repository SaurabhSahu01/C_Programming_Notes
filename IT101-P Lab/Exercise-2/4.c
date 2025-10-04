#include <stdio.h>

int main() {
    int num, original, reverse = 0, digit;
    printf("Enter an integer : ");
    scanf("%d", &num);
    original = num;

    while (num != 0) {
        digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }

    printf("The reverse of a given number : %d\n", reverse);
    if (original == reverse)
        printf("%d is a palindrome\n", original);
    else
        printf("%d is not a palindrome\n", original);

    return 0;
}
