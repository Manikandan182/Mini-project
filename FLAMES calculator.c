#include <stdio.h>
#include <string.h>

void removeMatchedChar(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j] && str1[i] != ' ') {
                str1[i] = str2[j] = '*';
                break;
            }
        }
    }
}

int countRemainingChars(char *str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '*' && str[i] != ' ') {
            count++;
        }
    }
    return count;
}

char* getFlamesResult(int count) {
    char flames[] = "FLAMES";
    int index = 0;

    for (int i = 6; i > 1; i--) {
        index = (count % i) - 1;
        if (index >= 0) {
            memmove(&flames[index], &flames[index + 1], i - index - 1);
        } else {
            index = i - 1;
            memmove(&flames[index], &flames[index + 1], i - index - 1);
        }
    }
    switch(flames[0]) {
        case 'F': return "Friends";
        case 'L': return "Lovers";
        case 'A': return "Affection";
        case 'M': return "Marriage";
        case 'E': return "Enemies";
        case 'S': return "Siblings";
    }
    return NULL;
}

int main() {
    char name1[100], name2[100];

    printf("Enter the first name: ");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1, "\n")] = 0;  // Remove newline character

    printf("Enter the second name: ");
    fgets(name2, sizeof(name2), stdin);
    name2[strcspn(name2, "\n")] = 0;  // Remove newline character

    removeMatchedChar(name1, name2);
    int remainingChars = countRemainingChars(name1) + countRemainingChars(name2);

    char *result = getFlamesResult(remainingChars);

    printf("The relationship is: %s\n", result);

    return 0;
}
