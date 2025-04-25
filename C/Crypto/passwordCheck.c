#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(){
	char pass[100];
	printf("Enter password: ");
	scanf("%s", pass);
	
	printf("\nPassword provided: %s\n", pass);
	int l = strlen(pass);
	bool isLength= false, isFirst=false, isLast=false, hasDigit=false, hasSpecial=false;
	
	if (l== 8){
		isLength = true;
	}
	if (isupper(pass[0])){
		isFirst =true;
	}
	if (isupper(pass[l-1])){
		isLast =true;
	}
	
	for (int i=0; i<l; i++){
		if (isdigit(pass[i])){
			hasDigit=true;
		}
		int sp= (int) pass[i];
		if ((sp>32 && sp<47)|| (sp>57 && sp<65)){
			hasSpecial=true;
		}
	}
	
	
	if (isLength && isFirst && isLast && hasDigit && hasSpecial){
		printf("Valid Password!");
	}
	else{
		printf("Not Valid Password!");
	}
	return 0;
}
