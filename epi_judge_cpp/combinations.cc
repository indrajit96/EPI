#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

void helper (int size, int dec_pointer, vector<int> * selected, vector<vector<int>>* power_set, int limit) {

 if(selected->size() == limit) {
   power_set->emplace_back(*selected);
   return;
 }
 if(dec_pointer > size) {
   return;
 }
 selected->push_back(dec_pointer);
 helper(size,dec_pointer+1,selected,power_set,limit);
 selected->pop_back();
 helper(size,dec_pointer+1,selected,power_set,limit);
}


vector<vector<int>> Combinations(int n, int k) {
  vector<vector<int>> power_set;
  helper(n,1,new vector<int>,&power_set,k);
 // TODO - you fill in here.
  return power_set;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  return GenericTestMain(
      args, "combinations.cc", "combinations.tsv", &Combinations,
      &UnorderedComparator<std::vector<std::vector<int>>>, param_names);
}
