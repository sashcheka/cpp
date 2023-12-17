#include <iostream>
#include <string>

using namespace std;

string XOR(string& text, const char& key) {
  for (int i = 0; i < text.size(); i++) {
    text[i] = text[i] ^ key;
  }
  return text;
}

int main() {
  string plaintext = "Artsiom";
  char key = '2';
  
  XOR(plaintext, key);
  cout << "ciphertext: " << plaintext << endl;
  
  XOR(plaintext, key);
  cout << "plaintext: " << plaintext << endl;
  cin.get();
}