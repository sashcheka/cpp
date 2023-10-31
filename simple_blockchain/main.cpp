#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/sha.h>

using namespace std;

class Wallet {
private:
  string address;
  RSA* keyPair;
  string publicKey;

  string generateAddress() {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, publicKey.c_str(), publicKey.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
      ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str().substr(0, 40);
  }

public:
  Wallet() {
    keyPair = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    if (keyPair == nullptr) {
      cout << "Error generating key pair." << endl;
      exit(1);
    }

    BIO* bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(bio, keyPair);
    size_t key_len = BIO_pending(bio);
    char* key_chars = new char[key_len];
    BIO_read(bio, key_chars, key_len);
    publicKey = string(key_chars, key_len);
    delete[] key_chars;
    BIO_free_all(bio);

    address = generateAddress();
  }

  ~Wallet() {
    RSA_free(keyPair);
  }

  void printWallet() {
    cout << "Wallet address: " << this->address << "\n";
    cout << "Wallet public key: " << this->publicKey << "\n";
  }
};

class Transaction {
  public:
    string senderAddress;
    string receiverAddress;
    double amount;
    long timestamp;
    string signature;
  public:
    Transaction(const string& senderAddress, const string& receiverAddress, double amount, long timestamp)
        : senderAddress(senderAddress), receiverAddress(receiverAddress), amount(amount), timestamp(timestamp) {}
    
    string signTransaction(Transaction transaction) {};
    void printTransaction() {
      cout << "Transaction sender address: " << this->senderAddress << "\n";
      cout << "Transaction receiver address: " << this->receiverAddress << "\n";
      cout << "Transaction amount: " << this->amount << "\n";
      cout << "Transaction timestamp: " << this->timestamp << "\n";
    }
};

class Block {
  private:
    int index;
    long timestamp;
    int nonce;
    string hash;
    string previousHash;
  public:
    Block(int index, long timestamp, int nonce, string& hash, string& previousHash)
      : index(index), timestamp(timestamp), nonce(nonce), hash(hash), previousHash(previousHash) {}

    string calculateHash(int index, long timestamp, string& previousHash) {};
    int mineBlock(int& difficulty) {};
    void printBlock() {
      cout << "Block index: " << this->index << "\n";
      cout << "Block timestamp: " << this->timestamp << "\n";
      cout << "Block nonce: " << this->nonce << "\n";
      cout << "Block hash: " << this->hash << "\n";
      cout << "Block previousHash: " << this->previousHash << "\n";
    }
};

class Blockchain {
  private:
    vector<Block> chain;
    int difficulty;
  public:

    Block createGenesisBlock() {};
    Block addBlock(Block& newBlock) {};
    bool isValid() {};
    void printChain() {};
};

int main() {
  Wallet wallet;
  wallet.printWallet();
}