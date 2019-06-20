#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Item {
  int weight, value;
};

int OptimumSubjectToCapacity(const vector<Item>& items, int capacity) {
  // TODO - you fill in here.
  int size;
  size = items.size();
  int result[size][capacity+1];
  int i,j;
  for(i=0;i<size;i++) {
    result[i][0] = 0;
  }
  for(i=0;i<=capacity;i++) {
    if(i>= items[0].weight)
      result[0][i] = items[0].value;
    else
      result[0][i] = 0;
  }
  for(i=1;i<size;i++) {
    for(j=1;j<=capacity;j++) {
      int new_val = 0;
      if(items[i].weight <= j)
        new_val = items[i].value + result[i-1][j-items[i].weight];
      result[i][j] = std::max(new_val,result[i][j-1]);
      result[i][j] = std::max(result[i][j],result[i-1][j]);
    }
  }
  return result[size-1][capacity];
}
template <>
struct SerializationTraits<Item> : UserSerTraits<Item, int, int> {};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"items", "capacity"};
  return GenericTestMain(args, "knapsack.cc", "knapsack.tsv",
                         &OptimumSubjectToCapacity, DefaultComparator{},
                         param_names);
}
