#include <fstream>
#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
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
*/


// 234234234234278
// 2
// 2 3 -> 3 is bigger, pop 2, you can now only remove 2 # remove case
// 3
// 3 4 -> 4 is bigger, pop 3, you can now only remove 1
// 4
// 4 2 -> 2 is smaller
// 4 2 3 -> 3 is bigger, pop 2, you can now only remove 0
// 4 3 .... ans # keep case

int main ()
{
  long long total_joltage = 0;

  ifstream file("test_final.txt");
  string str_line;
  
  while (getline(file, str_line)) {
    int str_line_len = str_line.length();  
    int removable = str_line_len - 12;
    vector<char> joltage;

    for (char curr_char: str_line) {
      while (!joltage.empty() && removable > 0 && joltage.back() < curr_char) {
        joltage.pop_back();
        removable--;
      }
      joltage.push_back(curr_char); 
    }

    while (!joltage.empty() && removable > 0) {
      joltage.pop_back();
      removable--;
    }
    
    string max_joltage_string(joltage.begin(), joltage.end());
    cout << max_joltage_string << endl;
    total_joltage += stoll(max_joltage_string);
  } 
  cout << endl <<"Total Joltage: " << total_joltage << endl;
  return 0;
}
