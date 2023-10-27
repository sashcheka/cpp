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
    string calculateHash(int& index, long& timestamp, string previousHash) {};
    int mineBlock(int& difficulty) {};
    void printBlock() {};
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
    Transaction createTransaction(string& receiverAddress, double& amount) {
      long timestamp = time(0);

      Transaction newTransaction;
      newTransaction.senderAddress = this->address;
      newTransaction.receiverAddress = receiverAddress;
      newTransaction.amount = amount;
      newTransaction.timestamp = timestamp;

      string signature = this->signTransaction(newTransaction);
      newTransaction.signature = signature;

      return newTransaction;
    }

    string signTransaction(Transaction transaction) {
      return "signature";
    }
    void printWallet() {};
};

int main() {
  cout << time(0);
}