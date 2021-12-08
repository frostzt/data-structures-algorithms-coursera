#include <iostream>

int get_change(int m) {
  int changes = 0;

  if (m >= 10) {
    changes = changes + (int)(m / 10);
    m = m - (int)(changes * 10);
  }

  if (m >= 5) {
    changes = changes + (int)(m / 5);
    m = m - ((int)(m / 5) * 5);
  }

  if (m >= 1) {
    changes = changes + m;
  }

  return changes;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
