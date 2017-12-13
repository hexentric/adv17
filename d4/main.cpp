#include <boost/algorithm/string.hpp>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
using namespace boost;

bool isValid (const string& passPhrase,
              bool noAnagrams
             ) {
  vector<string> fields;
  boost::split( fields, passPhrase, boost::is_any_of(" "));
  map<string,size_t> wordCounts;
  for (auto &el : fields) {
    if (noAnagrams) {
      string sorted = el;
      std::sort(sorted.begin(), sorted.end());
      ++wordCounts[sorted];
    }
    else {
      ++wordCounts[el];
    }
  }
  for (const auto &wc : wordCounts) {
    if (wc.second > 1) { return 0; }
  }
  return 1;
}



int main(int argc, char *argv[argc])
{
  //string test = "sayndz zfxlkl attjtww cti sokkmty brx fhh suelqbp";
  //cout << isValid(test) << endl;
  //
  //test = "xmuf znkhaes pggrlp zia znkhaes znkhaes";
  //cout << isValid(test) << endl;
  //
  //string test = "abcde xyz ecdab";
  //cout << isValid(test) << endl;
  
  ifstream infile("input");
  string line;
  int validCount = 0;
  int noAnagramsCount = 0;
  while (getline(infile, line)) {
    validCount += isValid( line, 0);
    noAnagramsCount += isValid( line, 1);
  }
  cout << "part1: " << validCount << endl;
  cout << "part2: " << noAnagramsCount << endl;
  return 0;
}
