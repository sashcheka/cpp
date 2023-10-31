#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

class Wallet {
  private:
    string address;
    string privateKey;
    string publicKey;
  public:
    string generateKeys() {};
    void printWallet() {
      cout << "Wallet address: " << this->address << "\n";
      cout << "Wallet public key: " << this->publicKey << "\n";
    }
};

int main() {
  Transaction t("s", "t", 6.9, 69228322);
  t.printTransaction();
}