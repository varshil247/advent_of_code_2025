#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

vector<string> split (const string &str, const char delim)
{
  vector<string> result;
  stringstream ss (str);
  string item;

  while (getline (ss, item, delim)) {result.push_back(item);}
  return result;
}

/*
int main ()
{
  long long invalid_ids = 0;
  
  ifstream file("test_final.txt");
  string str;
  getline(file, str); 
  vector<string> ranges = split(str, ',');

  for (string range: ranges)
  {
    vector<string> range_ids = split(range, '-');
    long long start_id = stol(range_ids.at(0));
    long long end_id = stol(range_ids.at(1));
    cout << endl << start_id << " " << end_id << endl;

    for (long long i = start_id; i <= end_id; i++)
    {
      string id_string = to_string(i);
      int id_string_len = id_string.length();
      string front = id_string.substr(0, id_string_len/2);
      string back = id_string.substr((id_string_len/2));
      
      if (front == back) {invalid_ids += i;}
      cout << id_string << " " << front << " " << back << " " << (front==back) << endl;
    }
  }

  cout << invalid_ids << endl;
  return 0;
}
*/

bool is_invalid (string &id_string) {
  string t = id_string + id_string;
  size_t pos = t.find(id_string, 1);
  return (pos != string::npos) && (pos < id_string.size());
}

int main ()
{
  long long invalid_ids = 0;
  
  ifstream file("test_final.txt");
  string str;
  getline(file, str); 
  vector<string> ranges = split(str, ',');

  for (string range: ranges) {
    vector<string> range_ids = split(range, '-');
    long long start_id = stol(range_ids.at(0));
    long long end_id = stol(range_ids.at(1));
    cout << endl << start_id << " " << end_id << endl;
    
    for (long long id = start_id; id <= end_id; id++) {
      string id_string = to_string(id);
      if (is_invalid(id_string)) {
        invalid_ids += id;
      }
    }
  }

  cout << invalid_ids << endl;
  return 0;
}
