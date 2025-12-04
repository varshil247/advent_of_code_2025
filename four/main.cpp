#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <queue>
using namespace std;

int main () 
{
  ifstream file("test_final.txt");
  string str_line;
  vector<string> graph;
  
  vector<pair<int,int>> directions = {
    {-1,0}, {-1,1}, {0,1}, {1,1},
    {1,0}, {1,-1}, {0,-1}, {-1,-1}
  };

  while (getline(file, str_line)) {
    graph.push_back(str_line);
  }

  int max_r = graph.size();
  int max_c = graph[0].length();
  int accessible = 0;
  int new_r, new_c;
  bool in_r, in_c, is_roll;
  
  for (int r = 0; r < max_r; r++) { 
    for (int c = 0; c < max_c; c++) {
      if (graph[r][c] == '@') {
        int rolls = 0;

        for (auto [dr,dc]: directions) {
          new_r = r + dr;
          new_c = c + dc;
          in_r = (0 <= new_r && new_r < max_r);
          in_c = (0 <= new_c && new_c < max_c);
          
          if (in_r && in_c && graph[new_r][new_c] == '@') {
            rolls ++;
          }
        }

        if (rolls < 4) {
          accessible++;
        }
      }
    }
  }
  
  cout << "Accessible: " << accessible << endl;
  return 0;
}
