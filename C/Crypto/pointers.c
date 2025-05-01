#include <stdio.h>
#include <string.h>

void callFunc (int *n, int c, char *pt, char *ct){
    *n=500;
    c=80;
    *pt='B';
    ct[0]='C';
    ct[1]='D';
    printf("\nInside function, n= %d, m= %d pt=%c,  ct= %s", *n, c, *pt, ct);
}
int main(){
    int n=100;
    int m=50;
    char pt='A';
    char ct[] = "AB";
    printf("Before function, n= %d, m= %d, pt= %c, ct= %s", n, m, pt, ct);
    callFunc(&n, m, &pt, ct);
    printf("\nAfter function, n= %d, m= %d pt=%c, ct= %s", n, m, pt, ct);
}