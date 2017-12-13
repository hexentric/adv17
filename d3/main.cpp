#include <cmath>
#include <iostream>
#include <string>

int part1(int input) {
  // the bottom right diagonal is the odd's squared, find the next largest
  // FIXME - not checking for the case where sq is exactly an odd
  int sq = sqrt(input);
  int osq = (sq%2) ? sq+2 : sq+1;
  int esq = osq-1; // "even square" aka lenght - 1 (used to traverse layer)
    
  // Unwrap the layer and find min distance to an X/Y axis crossing aka Midpoints
  int min_dist = osq;
  for (int i=0; i!=4; i++) {
    int midpoint = pow(osq,2) // bottom right corner
                   - esq/2 // half the side to bottom midpoint
                   - esq*i;// visit all midpoints
    int dist = std::abs(input-midpoint);
    if (dist < min_dist) min_dist = dist;
  }

  // distance from a midpoint is only part of the total distance.
  // also need to include the lenght along X/Y axis, ie number of layers.
  // number of layers is esq/2, it just is :D

  return min_dist + esq/2;
  
}

int main(int argc, char *argv[argc])
{
  int x = std::stoi(argv[1], nullptr);
  std::cout << part1(x) << std::endl;
  return 0;
}
