#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int FindMaximumSubarray(const vector<int>& a) {
  int max_so_far = 0;
  int max_till_here = 0;

  int i = 0;
  for(i=0;i<a.size();i++) {
    max_till_here = max_till_here + a[i];
    if(max_so_far < max_till_here) {
      max_so_far = max_till_here;
    }
    if(max_till_here < 0) {
      max_till_here = 0;
    }
  }
  // TODO - you fill in here.
  return max_so_far;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "max_sum_subarray.cc", "max_sum_subarray.tsv",
                         &FindMaximumSubarray, DefaultComparator{},
                         param_names);
}
