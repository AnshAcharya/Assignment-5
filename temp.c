#include <stdio.h>

int max_single_valued_substrings(char s[], int k) {
    int max_count = 0;
    int current_count = 1;

    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            current_count++;
        } else {
            current_count = 1;
        }

        if (current_count == k) {
            max_count++;
            current_count = 0;  // reset count after finding a substring
        }
    }

    return max_count;
}

int all_substrings_same_char(char s[], int k) {
    char first_char = s[0];
    
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] != first_char) {
            return 0;  // Substring has different characters
        }
    }

    return 1;  // All characters in the substring are the same
}

int main() {
    char s[] = "aacbbbbbb";
    int k = 2;
    
    int max_count = max_single_valued_substrings(s, k);
    int are_all_same_char = all_substrings_same_char(s, k);

    if (are_all_same_char) {
        printf("All substrings of length %d have the same character.\n", k);
        printf("The maximum number of such substrings is: %d\n", max_count);
    } else {
        printf("Not all substrings of length %d have the same character.\n", k);
    }

    return 0;
}
