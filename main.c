#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidEmail(char* email) {
    int atSymbolIndex = -1;
    int dotSymbolIndex = -1;
    int emailLength = strlen(email);

    // Find the index of the "@" symbol
    for (int i = 0; i < emailLength; i++) {
        if (email[i] == '@') {
            atSymbolIndex = i;
            break;
        }
    }

    // Find the index of the "." symbol
    for (int i = atSymbolIndex; i < emailLength; i++) {
        if (email[i] == '.') {
            dotSymbolIndex = i;
            break;
        }
    }

    // Check if there is a valid "@" and "."
    if (atSymbolIndex == -1 || dotSymbolIndex == -1) {
        return false;
    }

    // Check if "@" and "." are in the correct order
    if (dotSymbolIndex < atSymbolIndex) {
        return false;
    }

    // Check if there are characters before "@" and after "."
    if (atSymbolIndex == 0 || dotSymbolIndex == emailLength - 1) {
        return false;
    }

    return true;
}

int main() {
    char email[100];

    printf("Enter an email address: ");
    scanf("%s", email);

    if (isValidEmail(email)) {
        printf("The email address %s is valid.", email);
    } else {
        printf("The email address %s is invalid.", email);
    }

    return 0;
}
