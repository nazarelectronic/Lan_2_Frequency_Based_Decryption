#include <string.h>
#include <stdio.h>
#include <iostream>

void break_Caesar(const char *encTxt);
void decrypt(char *txt, uint8_t key);


int main() {
    char txt[256];

    printf("enter the encrypted text: ");
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = '\0';
    break_Caesar(txt);

    return 0;
}



void break_Caesar(const char *encTxt) {
    char temp[256];
    for (uint8_t key = 1; key <= 26; key++) {
        strcpy(temp, encTxt);
        decrypt(temp, key);
        printf("Key - %d, Text - %s\n", key, temp);
    }
}

void decrypt(char *txt, uint8_t key) {
    for (uint8_t i = 0; txt[i] != '\0'; i++) {
        if (isalpha(txt[i])) {
            char base = islower(txt[i]) ? 'a' : 'A';
            txt[i] = (txt[i] - base - key + 26) % 26 + base;
        }
    }
}




