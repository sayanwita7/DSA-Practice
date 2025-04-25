#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char text[100];
	int k=3;
	printf("Enter the plain text: ");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")]='\0';
	
	printf("PLain Text: %s\n", text);
	
	char etext[100];
	for (int i=0; text[i] != '\0' ; i++){
		int pc = (int) text[i];
		if ((pc>=65 && pc <=90) || (pc>=97 && pc<=122)) {
			pc+=k;
			if ((pc>122) || (pc>90 && pc<97)){
				pc-=26;
			}
		}
		char cc = (char) pc;
		etext[i]=cc;
	}
	printf("Standard Caesar Cipher Text: %s\n", etext);
	
	k=0;
	printf ("Enter Key Value for Modified Caesar Cipher: ");
	scanf("%d", &k);
	
	char etext2[100];
	for (int i=0; text[i] != '\0' ; i++){
		int pc = (int) text[i];
		if ((pc>=65 && pc <=90) || (pc>=97 && pc<=122)) {
			pc+=k;
			if ((pc>122) || (pc>90 && pc<97)){
				pc-=26;
			}
		}
		char cc = (char) pc;
		etext2[i]=cc;
	}
	printf("Modified Caesar Cipher Text: %s\n", etext2);
	
	char key[26];
	printf("Enter the key for Monoalphabetic Substitution: ");
	fgets(key, sizeof(key), stdin);
	key[strcspn(key, "\n")]='\0';
	printf("Key: %s\n", key);
	
	char etext3[100];
	for (int i=0; text[i] != '\0' ; i++){
		for (int j=0; j<26; j++){
			if (text[i] == key[j]){
				etext3[i]=key[j];
			}
		}
	}
	
	printf("Monoalphabetic Cipher: %s\n", etext3);
	
}
