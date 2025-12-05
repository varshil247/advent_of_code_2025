#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <chrono>
#include <thread>

#define RESET             "\033[0m"
#define CLEAR_SCREEN      "\033[2J\033[1;1H"

using namespace std;
const int MS_DELAY = 75;
const string ROLL = "🧻";
const string YELLOW = "🟨";
const string ORANGE = "🟧";
const string RED = "🟥";
const string BLACK = "⬛";

void print_graph(vector<string> graph) {
  cout << CLEAR_SCREEN;
  for (string line: graph) {
    for (char c: line) {
      if (c == '@')       {cout << ROLL;}
      else if (c == '3')  {cout << YELLOW;}
      else if (c == '2')  {cout << ORANGE;}
      else if (c == '1')  {cout << RED;}
      else if (c == '.')  {cout << BLACK;}
    }
    cout << endl;
  }
  cout << endl;
}

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
  
  vector<string> new_graph = graph;
  int max_r = graph.size();
  int max_c = graph[0].length();
  int totalAccessible = 0;
  
  while (true) {
    int accessible = 0;
    graph = new_graph;

    for (int r = 0; r < max_r; r++) { 
      for (int c = 0; c < max_c; c++) {
        char node = graph[r][c];
        
        if (node == '@') {
          int rolls = 0;
          for (auto [dr,dc]: directions) {
            int new_r = r + dr;
            int new_c = c + dc;
            bool in_r = (0 <= new_r && new_r < max_r);
            bool in_c = (0 <= new_c && new_c < max_c); 
            if (in_r && in_c) {
              if (graph[new_r][new_c] == '@') {
                rolls ++;
              }
            }
          }
          if (rolls < 4) {
            new_graph[r][c] = '3';
            accessible++;
          }
        }

        else if (node == '1') {
          graph[r][c] = '.';
        }

        else if (!(node == '.')) {
          new_graph[r][c] = ((node - '0') - 1) + '0';
        }
      }
    }
    
    if (accessible == 0) {break;}
    totalAccessible += accessible;
    graph = new_graph;
    print_graph(new_graph);
    this_thread::sleep_for(chrono::milliseconds(MS_DELAY));
  }
  cout << "Total Accessible: " << totalAccessible << endl;
  return 0;
}
