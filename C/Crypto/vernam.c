#include <stdio.h>
#include <string.h>

void vernam_cipher(const char *input, char *output, const char *key, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i];
    }
    output[length] = '\0';
}

int main() {
    char plaintext[256]; 
    char key[256];       
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    int length = strlen(plaintext);
    printf("Enter the key (same length as plaintext): ");
    fgets(key, sizeof(key), stdin);
    char ciphertext[length+1];
    char decrypted[length+1]; 
    vernam_cipher(plaintext, ciphertext, key, length);
    vernam_cipher(ciphertext, decrypted, key, length);
    printf("\nCiphertext (ASCII values): ");
    for (int i = 0; i < length; i++) {
        printf("%d ", (unsigned char)ciphertext[i]);
    }
    printf("\nDecrypted Text: %s\n", decrypted);
    return 0;
}
