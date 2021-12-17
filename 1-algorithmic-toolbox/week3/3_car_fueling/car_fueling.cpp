#include <iostream>
#include <vector>

using std::vector;

int compute_min_refills(int dest, int tank, vector<int> &stops) {
  int size = (int)stops.size() - 1;
  int currTank = tank;
  int refills = 0;
  int currPos = 0;

  while (currPos != size) {
    // Check if the next position is reachable with the current tank capacity
    if (stops.at(currPos + 1) - stops.at(currPos) <= currTank) {
      currPos++;
      currTank = currTank - (stops.at(currPos) - stops.at(currPos - 1));
    } else {
      refills++;
      currTank = tank;
    }
  }

  return refills;
}

int main() {
  int d = 0;
  std::cin >> d;
  int m = 0;
  std::cin >> m;
  int n = 0;
  std::cin >> n;

  int i = 0;
  vector<int> stops(n + 2);
  stops[0] = 0;
  for (i = 1; i <= n; i++) {
    std::cin >> stops.at(i);
  }
  stops[n + 1] = d;

  std::cout << compute_min_refills(d, m, stops) << "\n";

  return 0;
}
