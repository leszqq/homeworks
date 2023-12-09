#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

map<string, string> season_to_adj{{"spring", "STL guru"},
                                  {"summer", "C++ expert"},
                                  {"autumn", "coding beast"},
                                  {"winter", "software design hero"}};

array<string, 3> endings{"eats UB for breakfast",
                         "finds errors quicker than the compiler",
                         "is not afraid of C++ error messages"};

void PrintWelcome() {
  cout << "Welcome to the fortune teller program!" << endl;
}

void ReadName(string &name) {
  cout << "Please enter your name:" << endl;
  cin >> name;
}

void ReadBornSeason(string &season) {
  do {
    cout << "Please enter the time of year when you were born:" << endl;
    cout << "(pick from 'spring', 'summer', 'autumn', 'winter')" << endl;
    cin >> season;
  } while (!season_to_adj.count(season));
}

void ReadAdjectives(vector<string> &adjectives) {
  string tmp;
  cout << "Please enter an adjective:" << endl;
  cin >> tmp;
  adjectives.push_back(tmp);
  cout << "Please enter another adjective:" << endl;
  cin >> tmp;
  adjectives.push_back(tmp);
}

int main() {

  string name, season;
  vector<string> adjectives;
  PrintWelcome();
  ReadName(name);
  ReadBornSeason(season);
  ReadAdjectives(adjectives);

  cout << endl << "Here is your description:" << endl;
  string adjective = adjectives.at(name.size() % adjectives.size());
  string noun = season_to_adj.at(season);
  string ending = endings.at(name.size() % endings.size());
  string fortune_telling =
      name + ", the " + adjective + " " + noun + " that " + ending;
  cout << fortune_telling << endl;
  return 0;
}
