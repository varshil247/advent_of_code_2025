#include <fstream>
#include <iostream>
#include <climits>
#include <string>
using namespace std;

int main ()
{
  int total_joltage = 0;

  ifstream file("test_final.txt");
  string str_line;
  
  while (getline(file, str_line)){
    int str_line_len = str_line.length();
    int max_joltage = INT_MIN;

    for (int i = 0; i < str_line_len; i++) {
      char char_i = str_line[i];

      for (int j = i+1; j < str_line_len; j++) {
        char char_j = str_line[j];
        string joltage_string;
        joltage_string += char_i;
        joltage_string += char_j;
        int current_joltage = stoi(joltage_string);

        if (current_joltage > max_joltage) {
          max_joltage = current_joltage;
        }
      }
    }
    cout << "Max Joltage: " << max_joltage << endl;
    total_joltage += max_joltage;
  }
  
  cout << "Total Joltage: " << total_joltage << endl;
  return 0;
}
