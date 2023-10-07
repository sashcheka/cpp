#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

int main() {
  vector<int> cards =
      {2,2,2,2,
       3,3,3,3,
       4,4,4,4,
       5,5,5,5,
       6,6,6,6,
       7,7,7,7,
       8,8,8,8,
       9,9,9,9,
       10,10,10,10,
       10,10,10,10,
       10,10,10,10,
       10,10,10,10,
      };
  int score = 0;
  float chance = 100;
  
  srand ( time(NULL) );
  while (score <= 21) {
    int cards_amount = size(cards);
    int random_index = rand() % cards_amount;
    int random_card = cards[random_index];
    
    
    std::cout << "card: " << random_card << endl;
    std::cout << "score: " << score << endl;
    std::cout << "chance: " << chance << " %" << endl;
    
    cards.erase(cards.begin() + random_index);
    
    string input;
    cin >> input;
    if (input.compare("exit") == 0) {
      cout << "your score is " << score << " LESS or EQUAL than 21";
      return 0;
    }
    
    score += random_card;
    
    float cards_for_success_count = 0;
    float cards_for_failure_count = 0;
    
    for (int i = 0; i < cards_amount; i++) {
      if (cards[i] <= 21 - score) {
        cards_for_success_count += 1;
      }
      else {
        cards_for_failure_count += 1;
      }
    }
    
    if (cards_for_failure_count == 0) {
      chance = 100;
    }
    else {
      chance = cards_for_success_count / cards_for_failure_count * 100;
    }
  }
  cout << "your score is " << score << " MORE than 21";
  return 0;
}