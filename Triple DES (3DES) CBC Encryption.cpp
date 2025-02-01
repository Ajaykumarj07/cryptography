#include <stdio.h>
#include <openssl/des.h>

void triple_des_encrypt(char *plaintext, char *key, char *iv) {
    DES_cblock key1, key2, key3, ivec;
    memcpy(key1, key, 8);
    memcpy(key2, key + 8, 8);
    memcpy(key3, key + 16, 8);
    memcpy(ivec, iv, 8);

    DES_key_schedule ks1, ks2, ks3;
    DES_set_key_unchecked(&key1, &ks1);
    DES_set_key_unchecked(&key2, &ks2);
    DES_set_key_unchecked(&key3, &ks3);

    DES_cblock ciphertext;
    DES_ede3_cbc_encrypt((unsigned char *)plaintext, (unsigned char *)&ciphertext, 8, &ks1, &ks2, &ks3, &ivec, DES_ENCRYPT);

    printf("Encrypted text: %s\n", ciphertext);
}

int main() {
    char plaintext[8] = "SECUREME";
    char key[24] = "THREEKEYENCRYPTION!!";
    char iv[8] = "INITVECT";

    triple_des_encrypt(plaintext, key, iv);
    return 0;
}
