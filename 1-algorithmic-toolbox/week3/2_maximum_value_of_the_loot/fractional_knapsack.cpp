#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

/**
 * Item contains weight and value of a particular item
 */
class Item {
public:
  int weight;
  int value;
  double unitValue;
  Item(int weight_value, int value_value)
      : weight{weight_value}, value{value_value} {
    unitValue = (double)value / (double)weight;
  }

  Item() {}
};

/**
 * Takes two Item Object to compare
 */
bool compareItems(Item A, Item B) { return A.unitValue > B.unitValue; }

// clang-format off
double get_optimal_value(int capacity, vector<Item> items) {
  // clang-format on
  int size = items.size();
  double value = 0.0;

  std::sort(items.begin(), items.end(), compareItems);

  for (int i = 0; i < size; i++) {
    int currentValue = items.at(i).value;
    int currentWeight = items.at(i).weight;
    double currentUnitValue = items.at(i).unitValue;

    // If the bag can take the entire weight of the item
    if (currentWeight <= capacity) {
      value = value + (double)currentValue;
      capacity = capacity - currentWeight;
    } else if (currentWeight > capacity) { // can't take the entire weight
      double toTake = (double)(capacity)*currentUnitValue;
      // curw = 30 - 10 = 20
      value = value + toTake;
      capacity = capacity - currentWeight;
    }

    if (capacity == 0) {
      break;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<Item> items(n);
  for (int i = 0; i < n; i++) {
    int v, w;
    std::cin >> v >> w;
    items[i] = Item(w, v);
  }

  double optimal_value = get_optimal_value(capacity, items);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
