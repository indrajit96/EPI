#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;

bool IsPal(const string& prefix) {
  for (int i = 0, j = prefix.size() - 1; i < j; ++i, --j) {
    if (prefix[i] != prefix[j]) {
      return false;
    }
  }
  return true;
}

void driver(const string& input, int dec_pointer , vector<string>* selected , vector<vector<string>>* result) {
  if(dec_pointer == input.size()) {
    result->emplace_back(*selected);
    return;
  }
  for(int i = dec_pointer + 1 ; i<= input.size(); ++i) {
    string tmp = input.substr(dec_pointer, i-dec_pointer);
    if(IsPal(tmp)) {
      selected->emplace_back(tmp);
      driver(input,i,selected,result);
      selected->pop_back();
    }
  }
}

vector<vector<string>> PalindromeDecompositions(const string& input) {
  vector<vector<string>> result;
  driver(input,0,new vector<string>, &result);
  return result;
}
bool Comp(vector<vector<string>> expected, vector<vector<string>> result) {
  std::sort(begin(expected), end(expected));
  std::sort(begin(result), end(result));
  return expected == result;
};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"input"};
  return GenericTestMain(args, "enumerate_palindromic_decompositions.cc",
                         "enumerate_palindromic_decompositions.tsv",
                         &PalindromeDecompositions, &Comp, param_names);
}
