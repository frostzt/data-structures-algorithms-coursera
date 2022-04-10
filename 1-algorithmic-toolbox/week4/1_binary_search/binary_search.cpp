#include <cassert>
#include <iostream>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int start = 0;
  int end = (int)a.size() - 1;

  while (start <= end) {
    int idx = (end + start) / 2;

    if (a[idx] == x) {
      return idx;
    } else if (a[idx] > x) {
      end = idx - 1;
    } else {
      start = idx + 1;
    }
  }

  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    // replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
