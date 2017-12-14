#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[argc])
{
  bool PART2 = stoi(argv[1]);
  bool PRINT_TAPE = 0;
  if (argv[2]) { PRINT_TAPE = 1;}
  
  ifstream infile("input");
  int x;
  vector <int> tape;
  while (infile >> x) {
    tape.push_back(x);
  }

  // debug
  // tape = {0,3,0,1,-3};
  
  int maxP = tape.size();
  int minP = 0;
  int pointer = 0;
  int count = 0;
  while (  (pointer >= minP)
        && (pointer < maxP)
        ) {
    int next = pointer + tape[pointer];
    if (PART2)
      tape[pointer] = tape[pointer]>2 ? tape[pointer]-1 : tape[pointer]+1;
    else 
      tape[pointer]++;

    if (PRINT_TAPE) { cout << pointer << "\n"; }

    ++count;
    pointer = next;
  }
  cout << "count: " << count << endl;
  return 0;
}
