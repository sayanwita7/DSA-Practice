#include <stdio.h>

int mod_exp(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;  // In case base is larger than modulus
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int main() {
    int P, G, a, b;
    printf("Enter a prime number (P): ");
    scanf("%d", &P);
    printf("Enter a primitive root (G): ");
    scanf("%d", &G);
    
    printf("Enter Alice's private key (a): ");
    scanf("%d", &a);
    
    printf("Enter Bob's private key (b): ");
    scanf("%d", &b);
    
    // Calculate public keys
    int A = mod_exp(G, a, P);  // Alice's public key
    int B = mod_exp(G, b, P);    // Bob's public key
    
    // Calculate shared secret keys
    int SA = mod_exp(B, a, P);  // Alice's shared key
    int SB = mod_exp(A, b, P);    // Bob's shared key

    printf("\nPublicly Shared Prime (P): %d", P);
    printf("\nPublicly Shared Base (G): %d", G);
    printf("\nAlice's Private Key (a): %d", a);
    printf("\nBob's Private Key (b): %d", b);
    printf("\nAlice's Public Key (A): %d", A);
    printf("\nBob's Public Key (B): %d", B);
    printf("\nShared key of Alice = %d", SA);
    printf("\nShared key of Bob = %d", SB);
    
    if (SA == SB) {
        printf("\nKey exchange successful!\n");
    } else {
        printf("\nKey exchange not successful!\n");
    }

    return 0;
}


/* Enter a prime number (P): 23
Enter a primitive root (G): 5
Enter Alice's private key (a): 6
Enter Bob's private key (b): 15

Publicly Shared Prime (P): 23
Publicly Shared Base (G): 5
Alice's Private Key (a): 6
Bob's Private Key (b): 15
Alice's Public Key (A): 8
Bob's Public Key (B): 19
Shared key of Alice = 2
Shared key of Bob = 2
Key exchange successful!
*/
