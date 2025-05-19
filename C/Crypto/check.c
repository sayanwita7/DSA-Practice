#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateKey(const char *plaintext, const char *key, char *newKey) {
    int pLen = strlen(plaintext);
    int kLen = strlen(key);
    for (int i = 0, j = 0; i < pLen; i++, j++) {
        if (j == kLen) {
            j = 0;
        }
        newKey[i] = key[j];
    }
    newKey[pLen] = '\0';
}

void encrypt(const char *plaintext, const char *key, char *ciphertext) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[i] = (plaintext[i]+ key[i]) % 26 + 'A';
        } else {
            ciphertext[i] = plaintext[i]; // Keeping non-alphabetic characters unchanged
        }
    }
    ciphertext[length] = '\0';
}

void decrypt(const char *ciphertext, const char *key, char *decryptedText) {
    int length = strlen(ciphertext);
    for (int i = 0; i < length; i++) {
        if (isalpha(ciphertext[i])) {
            decryptedText[i] = ( ciphertext[i]- key[i]+ 26) % 26 + 'A';
        } else {
            decryptedText[i] = ciphertext[i];
        }
    }
    decryptedText[length] = '\0';
}

int main() {
    char plaintext[100], key[100], newKey[100], ciphertext[100], decryptedText[100];
    
    printf("Enter plaintext (only alphabets): ");
    scanf("%s", plaintext);
    printf("Enter key (only alphabets): ");
    scanf("%s", newKey);
    //generateKey(plaintext, key, newKey);
    encrypt(plaintext, newKey, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);
    decrypt(ciphertext, newKey, decryptedText);
    printf("Decrypted Text: %s\n", decryptedText);
    
    return 0;
}
