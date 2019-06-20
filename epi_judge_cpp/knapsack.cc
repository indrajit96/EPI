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
  int result[size][size];
  int i,j;
  for(i=0;i<size;i++) {
    result[0][i] = 0;
    result[i][0] = 0;
    if(i>= items[0].weight)
      result[0][i] = items[0].weight;
  }
  for(i=0;i<size;i++) {
    if(1>= items[i].weight)
      result[i][0] = items[0].weight;
  }
  for(i=1;i<size;i++) {
    for(j=1;j<size;j++) {
      int new_val = 0;
      if(result[i-1][j] + items[i].weight
      result[i][j] = std::max(


  return 0;
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
