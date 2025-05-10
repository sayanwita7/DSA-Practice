#include <stdio.h>
#include <string.h>
#include <ctype.h>

void capitalize (char *m){
    int j=0;
    while (m[j]!='\0'){
        char c=m[j];
        m[j]=toupper(c);
        j++;
    }
}

void encrypt (char *pt , char *ct, char *key){
    for (int k=0; k< strlen(pt); k++){
        int n= (int) pt[k]-65;
        ct[k]=key[n];
    }
    ct[strlen(pt)]='\0';
}

void decrypt(char *ct, char *dt, char *key) {
    char reverse_key[26];
    for (int i = 0; i < 26; i++) {
        reverse_key[key[i] - 'A'] = 'A' + i;
    }
    for (int k = 0; k < strlen(ct); k++) {
        dt[k] = reverse_key[ct[k] - 'A'];
    }
    dt[strlen(ct)] = '\0';
}


int main(){
    char pt[100], ct[100], key[26], dt[100];
    printf("Enter plain text (CAPITAL LETTERS): ");
    scanf ("%s", pt);
    printf("Enter key (CAPITAL LETTERS): ");
    scanf ("%s", key);

    capitalize(pt);
    capitalize(key);

    encrypt (pt, ct, key);
    decrypt(ct, dt, key);

    printf("Key: %s\n", key);
    printf("Plain Text: %s\n", pt);
    printf("Cipher Text: %s\n", ct);
    printf("Decrypted Text: %s\n", dt);    
}