//http://adventofcode.com/2017/day/1

#include <iostream>
#include <string>

int captcha(std::string str) {
  if (str.size()<2) return 0;

  char fc = str[0];
  char pc = fc;
  std::string cp (str,1);
  int sum = 0;
  for (char& c : cp) {
    if (c == pc) sum+=(pc-'0');
    pc = c;
  }
  if (pc == fc) sum+=(pc-'0');
  return sum;
}

int main(int argc, char *argv[argc])
{
  std::cout << captcha(argv[1]) << std::endl;
  return 0;
}
