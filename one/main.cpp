#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main ()
{
  int current = 50;
  int password = 0;
  
  ifstream file("test_final.txt");
  string str;
  
  while (getline(file, str))
  {
    char direction = str[0];
    int ticks = stoi(str.substr(1)); 

    if (direction == 'R') {
      password += (current + ticks) / 100;
    }
    else {
      int current_TR = (100 - current) % 100;
      password += (current_TR + ticks) / 100;
    }

    int delta = (direction == 'R') ? ticks : -ticks;
    current = ((current + delta) % 100 + 100) % 100;
  }

  cout << "Password: " << password << endl;
  return password;
}


