#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int NumCombinationsForFinalScore(int final_score,
                                 const vector<int>& individual_play_scores) {
  vector<vector<int>> result(individual_play_scores.size(),vector<int>(final_score+1, 0));
  int with_score = 0;
  int without_score = 0;
  int i,j;

  for(i = 0; i<=final_score; i++) {
    if(individual_play_scores[0] <= i && (i%individual_play_scores[0] == 0))
      result[0][i] = 1;
    else
      result[0][i] = 0;
  }

  for(j= 0; j<individual_play_scores.size(); j++) {
    result[j][0] =1 ;
  }

  for(i =1; i<individual_play_scores.size(); i++) {
    for(j= 1; j<=final_score; j++) {
      without_score = result[i-1][j];
      if(j >= individual_play_scores[i])
        with_score = result[i][j-individual_play_scores[i]];
      else
        with_score = 0;
      result[i][j] = with_score + without_score;
//      printf("%d ",result[i][j]);
    }
//    printf("\n");
  }
  // TODO - you fill in here.
  return result.back().back();
//  return result[individual_play_scores.size()-1][final_score];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"final_score", "individual_play_scores"};
  return GenericTestMain(args, "number_of_score_combinations.cc",
                         "number_of_score_combinations.tsv",
                         &NumCombinationsForFinalScore, DefaultComparator{},
                         param_names);
}
