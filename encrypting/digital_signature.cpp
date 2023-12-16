#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/sha.h>

using namespace std;

RSA* generate_rsa_keys() {
    RSA* rsa = RSA_new();
    BIGNUM* e = BN_new();
    BN_set_word(e, RSA_F4);

    if (RSA_generate_key_ex(rsa, 2048, e, NULL) != 1) {
        RSA_free(rsa);
        BN_free(e);
        return nullptr;
    }

    BN_free(e);
    return rsa;
}

unsigned char* sign_message(RSA* rsa, const string& message, unsigned int& sig_len) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)message.c_str(), message.size(), hash);

    unsigned char* sig = new unsigned char[RSA_size(rsa)];
    if (RSA_sign(NID_sha256, hash, SHA256_DIGEST_LENGTH, sig, &sig_len, rsa) != 1) {
        delete[] sig;
        return nullptr;
    }

    return sig;
}

bool verify_signature(RSA* rsa, const string& message, unsigned char* sig, unsigned int sig_len) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)message.c_str(), message.size(), hash);

    return RSA_verify(NID_sha256, hash, SHA256_DIGEST_LENGTH, sig, sig_len, rsa) == 1;
}

int main() {
    RSA* rsa = generate_rsa_keys();
    if (!rsa) {
        cerr << "Error generating RSA keys." << endl;
        return 1;
    }

    string message = "Hello, world!";
    unsigned int sig_len = 0;

    unsigned char* signature = sign_message(rsa, message, sig_len);
    if (!signature) {
        cerr << "Error creating signature." << endl;
        RSA_free(rsa);
        return 1;
    }

    cout << "Signature: ";
      for (unsigned int i = 0; i < sig_len; ++i) {
      printf("%02x", signature[i]);
    }
    cout << endl;
    
    if (verify_signature(rsa, message, signature, sig_len)) {
      cout << "Signature successfully verified." << endl;
    } else {
      cout << "Signature verification failed." << endl;
    }

    delete[] signature;
    RSA_free(rsa);

    return 0;
}
