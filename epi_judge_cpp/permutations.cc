#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

void helper(int i, vector<int> *A_ptr, vector<vector<int>> *result) {
  vector<int> &A = *A_ptr;
  if(i == A.size() -1) {
    result->emplace_back(A);
    return;
  }
  for(int j = i; j <A.size(); ++j) {
    std::swap(A[i],A[j]);
    helper(j+1,A_ptr,result);
    std::swap(A[i],A[j]);
  }
}

vector<vector<int>> Permutations(vector<int> A) {
  vector<vector<int>> result;
  helper(0,&A,&result);
  // TODO - you fill in here.
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "permutations.cc", "permutations.tsv", &Permutations,
      &UnorderedComparator<vector<vector<int>>>, param_names);
}
