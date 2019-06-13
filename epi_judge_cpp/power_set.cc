#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

void helper (const vector<int>& input_set, int dec_pointer, vector<int> * selected, vector<vector<int>>* power_set) {
 if(dec_pointer == input_set.size()) {
   power_set->emplace_back(*selected);
   return;
 }
 selected->push_back(input_set[dec_pointer]);
 helper(input_set,dec_pointer+1,selected,power_set);
 selected->pop_back();
 helper(input_set,dec_pointer+1,selected,power_set);
}

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
  vector<vector<int>> power_set;
  helper(input_set,0,new vector<int>,&power_set);
  // TODO - you fill in here.
  return power_set;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"input_set"};
  return GenericTestMain(
      args, "power_set.cc", "power_set.tsv", &GeneratePowerSet,
      &UnorderedComparator<vector<vector<int>>>, param_names);
}
