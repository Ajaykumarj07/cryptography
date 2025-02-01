#include <stdio.h>
#include <stdlib.h>

#define N 2 


int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}


int determinant(int key[N][N]) {
    return (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
}


void hill_decrypt(int key[N][N], char *ciphertext) {
    int det = determinant(key);
    int det_inv = modInverse(det, 26);
    if (det_inv == -1) {
        printf("Determinant has no inverse, attack failed.\n");
        return;
    }

   
    int inverse[N][N] = {
        {key[1][1] * det_inv % 26, -key[0][1] * det_inv % 26},
        {-key[1][0] * det_inv % 26, key[0][0] * det_inv % 26}
    };

  
    int len = 2;
    int cipher_vals[N] = {ciphertext[0] - 'A', ciphertext[1] - 'A'};
    int plain_vals[N];

    for (int i = 0; i < N; i++) {
        plain_vals[i] = (inverse[i][0] * cipher_vals[0] + inverse[i][1] * cipher_vals[1]) % 26;
        if (plain_vals[i] < 0) plain_vals[i] += 26;
    }

    printf("Decrypted text: %c%c\n", plain_vals[0] + 'A', plain_vals[1] + 'A');
}

int main() {
    int key[N][N] = {{9, 4}, {5, 7}};  
    char ciphertext[] = "LF"; 

    hill_decrypt(key, ciphertext);

    return 0;
}
