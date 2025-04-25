#include<stdio.h>
#include<string.h>


void encrypt (char *pt, char *ct, int rails){
    int i,j,len,count;
    char code[100][1000];
    len=strlen(pt);
    for(i=0;i<rails;i++){
        for(j=0;j<len;j++){
            code[i][j]='\0';
        }
    }
    count=0;
    j=0;
    while(j<len){
        if(count%2==0){
            for(i=0;i<rails;i++){
                code[i][j]=pt[j]; 
                j++;
            }
        
        }
        else{
            for(i=rails-2;i>0;i--){
                code[i][j]=pt[j];
                j++;
            }  
        } 
        count++;
    }
    int k=0;
    for(i=0;i<rails;i++){
        for(j=0;j<len;j++){
            if(code[i][j]!='\0'){
                ct[k]=code[i][j];
                k+=1;
            }
        }  
    }
}

void decrypt(char *ct, char *dt, int rails) {
    int i, j, count;
    int len = strlen(ct);
    char code[100][1000];
    
    len=strlen(ct);
    for(i=0;i<rails;i++){
        for(j=0;j<len;j++){
            code[i][j]='\0';
        }
    }
    count=0;
    j=0;
    while(j<len){
        if(count%2==0){
            for(i=0;i<rails;i++){
                code[i][j]='*'; 
                j++;
            }
        
        }
        else{
            for(i=rails-2;i>0;i--){
                code[i][j]='*';
                j++;
            }  
        } 
        count++;
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (code[i][j] == '*' && index < len) {
                code[i][j] = ct[index++];
            }
        }
    }

    int k=0;
    for(j=0;j<len;j++){
        for(i=0;i<rails;i++){
            if(code[i][j]!='\0'){
                dt[k]=code[i][j];
                k+=1;
            }
        }  
    }
    
}

int main()
{
    int rails,count,code[100][1000];
    char ct[1000];
    char pt[1000];
    char dt[1000];
    printf("Enter Plain Text: ");
    scanf("%s", pt);
    printf("Enter Key (No. of Rails): ");
    scanf("%d",&rails);
    
    encrypt(pt, ct, rails);
    printf("Encrypted Message: %s\n", ct);
    decrypt(ct, dt, rails);
    printf("Decrypted Message: %s\n", dt);
}
