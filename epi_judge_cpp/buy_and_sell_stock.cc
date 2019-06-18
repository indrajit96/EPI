#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

double maxSubArraySum(const vector<double>& prices)
{
    vector<double> my_prices;
    for (int i = 0; i < prices.size()-1; i++)
      my_prices.push_back(prices[i+1]-prices[i]);

    double max_so_far = 0, max_ending_here = 0;

    for (int i = 0; i < my_prices.size(); i++)
    {
        max_ending_here = max_ending_here + my_prices[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

double BuyAndSellStockOnce(const vector<double>& prices) {
  
  // TODO - you fill in here.
  return maxSubArraySum(prices);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
