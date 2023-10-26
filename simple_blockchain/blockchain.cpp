#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

class Transaction {
public:
  string fromAddress;
  string toAddress;
  float amount;

  Transaction(string fromAddress, string toAddress, float amount) {
    this->fromAddress = fromAddress;
    this->toAddress = toAddress;
    this->amount = amount;
  }
};

class Block {
public:
  long long index;
  time_t timestamp;
  vector<Transaction> transactions;
  string previousHash;
  string hash;
  long long nonce;

  Block(long long index, time_t timestamp, vector<Transaction> transactions, string previousHash) {
    this->index = index;
    this->timestamp = timestamp;
    this->transactions = transactions;
    this->previousHash = previousHash;
    this->nonce = 0;
    this->hash = calculateHash();
  }

  string calculateHash() const {
    stringstream ss;
    ss << index << timestamp;
    for (const Transaction& tx : transactions) {
      ss << tx.fromAddress << tx.toAddress << tx.amount;
    }
    ss << previousHash << nonce;
    return sha256(ss.str());
  }

  void mineBlock(int difficulty) {
    string target(difficulty, '0');
    while (hash.substr(0, difficulty) != target) {
      nonce++;
      hash = calculateHash();
    }
    cout << "Block mined: " << hash << endl;
  }

  string getHash() const {
    return hash;
  }

  string getPreviousHash() const {
    return previousHash;
  }

  static string sha256(const string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for (unsigned char i : hash) {
      ss << hex << setw(2) << setfill('0') << (int)i;
    }
    return ss.str();
  }
};

class Blockchain {
public:
  vector<Block> chain;
  int difficulty;
  vector<Transaction> pendingTransactions;
  float reward;

  Blockchain(int difficulty, float reward) {
    this->difficulty = difficulty;
    this->reward = reward;
    this->chain.push_back(createGenesisBlock());
  }

  Block createGenesisBlock() {
    return Block(0, time(nullptr), vector<Transaction>(), "0");
  }

  Block getLatestBlock() const {
    return chain.back();
  }

  float getBalance(const string& address) const {
    float balance = 0.0f;

    for (const Block& block : chain) {
      for (const Transaction& trans : block.transactions) {
        if (trans.fromAddress == address) {
          balance -= trans.amount;
        }

        if (trans.toAddress == address) {
          balance += trans.amount;
        }
      }
    }

    return balance;
  }


  void minePendingTransactions(string minerAddress) {
    Block block(chain.size(), time(nullptr), pendingTransactions, getLatestBlock().hash);
    block.mineBlock(difficulty);
    cout << "Block successfully mined!" << endl;
    chain.push_back(block);

    pendingTransactions.clear();
    pendingTransactions.push_back(Transaction("", minerAddress, reward));
  }

  void addTransaction(const Transaction& transaction) {
    if (transaction.fromAddress.empty() || transaction.toAddress.empty()) {
      throw invalid_argument("Transaction must include from and to address");
    }
    pendingTransactions.push_back(transaction);
  }

  bool isChainValid() const {
    for (size_t i = 1; i < chain.size(); i++) {
      const Block& currentBlock = chain[i];
      const Block& previousBlock = chain[i - 1];

      if (currentBlock.hash != currentBlock.calculateHash()) {
        return false;
      }

      if (currentBlock.previousHash != previousBlock.hash) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Blockchain myBlockchain(3, 100.0f);

  cout << "Mining block 1..." << endl;
  myBlockchain.addTransaction(Transaction("address1", "address2", 50.0f));
  myBlockchain.addTransaction(Transaction("address2", "address1", 30.0f));
  myBlockchain.minePendingTransactions("minerAddress");

  cout << "Balance of minerAddress: " << myBlockchain.getBalance("minerAddress") << endl;

  cout << "Mining block 2..." << endl;
  myBlockchain.addTransaction(Transaction("address1", "address2", 20.0f));
  myBlockchain.addTransaction(Transaction("address2", "address1", 10.0f));
  myBlockchain.minePendingTransactions("minerAddress");

  cout << "Balance of minerAddress: " << myBlockchain.getBalance("minerAddress") << endl;

  cout << "Mining block 3..." << endl;
  myBlockchain.addTransaction(Transaction("address1", "address2", 15.0f));
  myBlockchain.addTransaction(Transaction("address2", "address1", 5.0f));
  myBlockchain.minePendingTransactions("minerAddress");

  cout << "Balance of minerAddress: " << myBlockchain.getBalance("minerAddress") << endl;

  return 0;
}
