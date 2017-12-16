#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int Checksum(vector<int> line)
{
  auto max = max_element(line.begin(), line.end());
  auto min = min_element(line.begin(), line.end());
  return (*max - *min);
}

int main(int argc, char *argv[argc])
{

  vector <vector <int>> spreadsheet;
  
  ifstream input("input");
  string line;
  while (getline(input,line))
  {
    int val;
    vector<int> row;
    istringstream iss(line);
    while (iss >> val) { row.push_back(val); }
    spreadsheet.push_back(row);
  }

  int checksum = 0;
  for (auto &r : spreadsheet)
  {
    for (auto & e : r)
    {
      cout << e << "\t";
    }
    int chk = Checksum(r);
    checksum+=chk;
    cout << chk << "/" << checksum << endl;
  }
  cout << "checksum is " << checksum << endl;
  return 0;
}
