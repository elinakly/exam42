#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

// Function to check if a substring is a palindrome
int is_palindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Is a palindrome
}
void biggest_pal(char *str) {
    int n = strlen(str);
    int max_len = 0;
    int start = 0;

    int i = 0;
    while (i < n) { // Replacing the outer for loop with a while loop
        int j = i;
        while (j < n) { // Replacing the inner for loop with a while loop
            if (is_palindrome(str, i, j)) {
                int len = j - i + 1;
                if (len > max_len) {
                    max_len = len;
                    start = i;
                } else if (len == max_len) {
                    start = i; // If the length is the same, pick the last one
                }
            }
            j++;
        }
        i++;
    }
    if (max_len > 0) {
        int k = start;
        while (k < start + max_len) {
            putchar(str[k]);
            k++;
        }
        putchar('\n');
    } else {
        putchar('\n');
    }
}
int main(int argc, char *argv[]) {
    if (argc == 2) {
        biggest_pal(argv[1]);
    } else {
        putchar('\n');
    }

    return 0;
}