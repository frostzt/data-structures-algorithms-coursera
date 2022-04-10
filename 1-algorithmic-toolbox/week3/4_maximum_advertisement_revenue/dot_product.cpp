#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(int n, vector<long long> a, vector<long long> b) {
  long long result = 0;
  int size = (int)a.size();

  if (n == 1) {
    result = a.at(0) * b.at(0);
    return result;
  }

  // Sort the vectors in descending order
  std::sort(a.begin(), a.end(), std::greater<int>());
  std::sort(b.begin(), b.end(), std::greater<int>());

  for (int i = 0; i < size; i++) {
    result = result + (a.at(i) * b.at(i));
  }

  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(n, a, b) << std::endl;
}
