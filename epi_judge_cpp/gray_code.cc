#include <algorithm>
#include <string>
#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
#include <set>
using std::vector;

bool DiffersByOneBit(int x, int y) {
  int bit_difference = x ^ y;
  return bit_difference && !(bit_difference & (bit_difference - 1));
}

bool driver(int num_bits,vector<int> *result,std::set<int> *current_set) {
  if(result->size() == (1 << num_bits)) {
    return DiffersByOneBit(result->front(),result->back());
  }

  int prev;
  int elem_to_add;
  for(int i=0;i<num_bits;i++) {
    prev = result->back();
    elem_to_add = (prev ^ (1 << i));
    if(!current_set->count(elem_to_add)) {
      result->emplace_back(elem_to_add);
      current_set->emplace(elem_to_add);
      if(driver(num_bits,result,current_set))
        return true;
      result->pop_back();
      current_set->erase(elem_to_add);
    }
  }
  return false;
}

vector<int> GrayCode(int num_bits) {
  vector<int> result({0});
  std::set<int> current_set({0});
  driver(num_bits,&result,&current_set);
  // TODO - you fill in here.
  return result;
}

void GrayCodeWrapper(TimedExecutor& executor, int num_bits) {
  vector<int> result = executor.Run([&] { return GrayCode(num_bits); });

  int expected_size = (1 << num_bits);
  if (result.size() != expected_size) {
    throw TestFailure("Length mismatch: expected " +
                      std::to_string(expected_size) + ", got " +
                      std::to_string(result.size()));
  }
  for (size_t i = 1; i < result.size(); i++)
    if (!DiffersByOneBit(result[i - 1], result[i])) {
      if (result[i - 1] == result[i]) {
        throw TestFailure("Two adjacent entries are equal");
      } else {
        throw TestFailure("Two adjacent entries differ by more than 1 bit");
      }
    }

  std::sort(begin(result), end(result));
  auto uniq = std::unique(begin(result), end(result));
  if (uniq != end(result)) {
    throw TestFailure("Not all entries are distinct: found " +
                      std::to_string(std::distance(uniq, end(result))) +
                      " duplicates");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "num_bits"};
  return GenericTestMain(args, "gray_code.cc", "gray_code.tsv",
                         &GrayCodeWrapper, DefaultComparator{}, param_names);
}
