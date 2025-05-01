#include <stdio.h>

int hcf (int a, int b){
    while (b!=0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modInverse(int e, int phi){
    int d=1+phi;
    for (int k=1; ((d%e)!=0); k++ ){
        d=1+k*phi;
    }
    d= (int)d/e;
    return d;
}

int mod_exp(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

void keys(int p, int q, int *e, int *d, int *n){
    *n=p*q;
    int phi= (p-1)*(q-1);
    for (int i=2; i<phi; i++){
        if (hcf(i, phi)==1) {
            *e=i; 
            break;}
    }
    *d = modInverse(*e, phi);
    //printf("\nn= %d phi=%d e=%d d=%d\n", *n, phi, *e, *d);
}

int encrypt(int *M, int *e, int *n){
    return mod_exp(*M, *e, *n);
}

int decrypt(int *C, int *d, int *n){
    return mod_exp(*C, *d, *n);
}

int main(){
    int p,q, e,d,n,M, C, m;
    printf ("Enter a prime numbers p and q: ");
    scanf ("%d %d", &p, &q);
    keys(p, q, &e, &d, &n);
    printf ("Enter Message to be encrypted: ");
    scanf ("%d", &M);
    C= encrypt (&M, &e, &n);
    printf("Encrypted Message: %d", C);
    m= decrypt (&C, &d, &n);
    printf("\nDecrypted Message: %d", m);
    return 0;
}