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

int captcha2(std::string str) {
  int len = str.size();
  if (len<2) return 0;
  if (len%2) return 0; // never odd

  int sum = 0;
  std::string lh (str, 0, len/2);
  std::string th (str, len/2);
  //std::cout << lh << std::endl << th;
  for (int i=0; i<len/2; i++) {
    char c1 = lh[i];
    char c2 = th[i];
    //std::cout << c1 << ' ' << c2 << std::endl;
    if (c1==c2) sum+=2*(c1-'0');
  }
  return sum;
}

int main(int argc, char *argv[argc])
{
  std::cout << captcha2(argv[1]) << std::endl;
  return 0;
}
