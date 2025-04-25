#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char text[100];
	printf("Enter the plain text: ");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")]='\0';
	
	printf("PLain Text: %s\n", text);
	
	char key[27];
	printf("Enter the key for Monoalphabetic Substitution: ");
	scanf("%26s", key);
	printf("Key: %s\n", key);
	
	char etext3[100];
	for (int i=0; text[i] != '\0' ; i++){
		if (isalpha(text[i])){
		for (int j=0; j<26; j++){
			if (text[i] == key[j]){
				etext3[i]=key[j];
				break;
			}
		}
		}
	}
	
	printf("Monoalphabetic Cipher: %s\n", etext3);
}
