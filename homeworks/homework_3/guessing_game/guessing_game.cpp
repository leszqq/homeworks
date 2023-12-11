#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

class RandomGen {
public:
  RandomGen(int low_limit = 1, int high_limit = 10)
      : _random_engine{_random_device()}, _distribution{low_limit,
                                                        high_limit} {};
  int GetNext() { return _distribution(_random_engine); }

private:
  std::random_device _random_device;
  std::mt19937 _random_engine;
  std::uniform_int_distribution<int> _distribution;
};

void PrintWelcome() {
  cout << "Welcome to the GUESSING GAME!" << endl;
  cout << "I willl generate a number and you will guess it!" << endl;
}

int GetSmallest() {
  cout << "Please provide the smallest number:" << endl;
  int num{};
  cin >> num;
  return num;
}

int GetLargest() {
  cout << "Please provide the largest number:" << endl;
  int num{};
  cin >> num;
  return num;
}

int main() {
  PrintWelcome();
  int smallest = GetSmallest();
  int largest = GetLargest();
  int num = RandomGen(smallest, largest).GetNext();
  cout << "I've generated a number. Try to guess it!" << endl;
  int k{};
  while (true) {
    ++k;
    cout << "Please provide the next guess:" << endl;
    int guess;
    cin >> guess;
    if (guess < num) {
      cout << "Your number is too small. Try again!" << endl;
    } else if (guess > num) {
      cout << "Your number is too big. Try again!" << endl;
    } else {
      cout << "You've done it! You guessed the number " << num << " in " << k
           << " guesses!";
      break;
    }
  }
  return 0;
}