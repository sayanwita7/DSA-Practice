#include <stdio.h>
#include <string.h>
int main(){
    int n= (7-8) % 2;
    printf("Mod: %d", &n);
    char pt[10];
    printf("Enter string: ");
    scanf ("%9s", pt);
    printf("String entered: %s", pt);
    printf("\nSize of string: %d", sizeof(pt));
    printf("\nSize of string: %d", strlen(pt));
    printf("\npt[%d]: %c", 11, pt[11]);
}