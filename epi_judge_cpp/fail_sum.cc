



void driver(vector<vector<int> > *result,vector<int> &A, int B, vector<int> * selected, int pointer) {
    if(pointer == A.size()) {
        vector<int> tmp;
        tmp = *selected;
        int sum =0;
        for(int i = 0; i< selected->size(); i++)
            sum = sum + tmp[i];
        if(sum == B)
            result->emplace_back(*selected);
        return;
    }
    selected->push_back(A[pointer]);
    driver(result, A, B, selected, pointer + 1);
    selected->pop_back();
    driver(result, A, B, selected, pointer + 1);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > result;
    std::sort(A.begin(),A.end());
    driver(&result,A,B, new vector<int>,0);
    std::sort(result.begin(), result.end());
    auto it = std::unique(result.begin(), result.end());
    result.resize( std::distance(result.begin(),it) );

//    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
