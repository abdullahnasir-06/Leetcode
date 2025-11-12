#include <stdio.h>

int main() {
    int x, original, reversed = 0, remainder;

    printf("Enter an integer: ");
    scanf("%d", &x);

    original = x;  

    
    if (x < 0) {
        printf("false\n");
        return 0;
    }

    
    while (x != 0) {
        remainder = x % 10;
        reversed = reversed * 10 + remainder;
        x /= 10;
    }


    if (original == reversed)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
