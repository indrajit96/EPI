#include <string>
#include <vector>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;
void driver(int left_needed, int right_needed, const string& selected, vector<string> *result) {
  if((left_needed == 0) && (right_needed == 0)) {
    result->emplace_back(selected);
    return;
  }
  if(left_needed > 0) {
    driver(left_needed - 1, right_needed, selected + '(' , result);
    //able to add a left
  }
  if(right_needed > left_needed) {
    driver(left_needed , right_needed - 1, selected + ')' , result);
  }
}
vector<string> GenerateBalancedParentheses(int num_pairs) {
  // TODO - you fill in here.
  vector<string> result;
  driver(num_pairs , num_pairs , "" , &result);
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_pairs"};
  return GenericTestMain(args, "enumerate_balanced_parentheses.cc",
                         "enumerate_balanced_parentheses.tsv",
                         &GenerateBalancedParentheses,
                         &UnorderedComparator<vector<string>>, param_names);
}
