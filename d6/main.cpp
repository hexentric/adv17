#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef vector <int> bank_t;

bank_t rebalance (const bank_t & in)
{
  bank_t::iterator itr;
  bank_t banks = in;
  itr = max_element(banks.begin(), banks.end());
  int blocks = *itr;
  *itr = 0;
  
  while (blocks > 0) {
    ++itr;
    if (itr == banks.end())
      itr = banks.begin();
    ++(*itr); // incr bank count
    --blocks;
  }
  return banks;
}

void printBanks(bank_t banks,
                string suffix
               )
{
  for (auto & i : banks)
    cout << i << "\t";
  cout << suffix << endl;
}  

int main(int argc, char *argv[argc])
{
  vector <int> banks = {11,11,13,7,0,15,5,5,4,4,1,1,7,1,15,11};
  //banks = {0, 2, 7, 0};
  printBanks(banks,"start");

  // faster (by how much) to use unordered_map if i defined a hash function
  map<bank_t,size_t> history;
  int count = 0;
  while (1)
  {
    ++count;
    banks = rebalance(banks);
    printBanks(banks,to_string(count));

    if (!history.count(banks))
      history[banks] = 1;
    else
      break;
  }
  cout << "iterations to infinite loop " << count << endl;
  return 0;
}
