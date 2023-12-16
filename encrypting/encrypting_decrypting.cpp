#include <openssl/aes.h>
#include <openssl/rand.h>
#include <iostream>
#include <cstring>

int main() {
    unsigned char *plaintext = (unsigned char *)"Hello, world!";
    int plaintext_len = strlen((char *)plaintext) + 1;

    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char iv_copy[AES_BLOCK_SIZE];

    RAND_bytes(key, sizeof(key));
    RAND_bytes(iv, sizeof(iv));
    memcpy(iv_copy, iv, AES_BLOCK_SIZE);

    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    memset(ciphertext, 0, sizeof(ciphertext));
    memset(decryptedtext, 0, sizeof(decryptedtext));

    AES_KEY enc_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &enc_key, iv, AES_ENCRYPT);

    int ciphertext_len = plaintext_len + (AES_BLOCK_SIZE - (plaintext_len % AES_BLOCK_SIZE));

    std::cout << "Ciphertext: ";
    for (int i = 0; i < ciphertext_len; i++) {
        std::cout << std::hex << (int)ciphertext[i];
        std::cout << (i < ciphertext_len - 1 ? " " : "");
    }
    std::cout << std::endl;

    AES_KEY dec_key;
    AES_set_decrypt_key(key, 128, &dec_key);
    AES_cbc_encrypt(ciphertext, decryptedtext, ciphertext_len, &dec_key, iv_copy, AES_DECRYPT);

    std::cout << "Decrypted text: " << decryptedtext << std::endl;

    return 0;
}
