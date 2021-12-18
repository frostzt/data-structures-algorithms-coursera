#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(int n, vector<int> a, vector<int> b) {
  long long result = 0;

  if (n == 1) {
    result = a.at(0) * b.at(0);
    return result;
  }

  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(n, a, b) << std::endl;
}
