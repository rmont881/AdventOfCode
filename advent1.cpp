#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string line;
  ifstream myfile ("advent1.txt");

  int sum = 0;
  int cur = -1;
  int prev = -1;
  int first = -1;

  if(myfile.is_open()) {
    while (getline(myfile,line)) {
      for(char& c : line) {
        cur = c - 48;
        if(cur == prev) {
          sum = sum + cur;
        }
        prev = cur;

        if(first == -1) {
          first = cur;
        }
      }
      if(first == cur) {
        sum = sum + cur;
      }
      cout << sum << '\n';
      break; //Only parse one line.
    }
    myfile.close();
  } else {
    cout << "Unable to open file.";
  }

  return 0;
}
