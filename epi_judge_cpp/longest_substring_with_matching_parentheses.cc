#include <string>
#include <vector>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;

int LongestMatchingParentheses(const string& s) {
  vector<int> dp;
  dp.emplace_back(0);
  int i = 1;
  int val = 0;
  int result = 0;
  for(i=1;i<s.size();i++) {
    if(s[i] == '(') {
      dp.emplace_back(0);
    }
    else {
      if(s[i-1] == '(')
        val = 2 + dp[i-2];
      else
        val = 2 + dp[i-1] + dp[i- dp[i-1] - 2];
      dp.emplace_back(val);
      if(val > result)
        result = val;
    }
  }
  // TODO - you fill in here.
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "longest_substring_with_matching_parentheses.cc",
                         "longest_substring_with_matching_parentheses.tsv",
                         &LongestMatchingParentheses, DefaultComparator{},
                         param_names);
}
