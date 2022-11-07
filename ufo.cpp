#include <iostream>
#include <vector>
#include "ufo_functions.hpp"

int main() {

  greet();
  // Player answers and the word they are trying to guess
  std::string codeword = "codecademy";
  std::string answer = "__________\n";
  int misses = 0;

  std::vector<char> incorrect;
  bool guess = false;
  char letter;
   while(answer != codeword && misses < 7) {
    // Player's turn
    display_misses(misses);
    display_status(incorrect, answer);
    std::cout << "Please enter your guess: ";
    std::cin >> letter;
      for (int i = 0; i < codeword.length(); i++) {
        if (codeword[i] == letter) {
          answer[i] = letter;
          guess = true;
        }
      }
      // User guessed right or wrong
      if (guess) {
        std::cout << "Correct!";
      } else if (!guess) {
        std::cout << "Incorrect! The tractor beam pulls the person in further.";
        incorrect.push_back(letter);
        misses++;
      }
      guess = false;
  }
  end_game(answer, codeword);
}