bool driver(vector<vector<int> > *result,vector<int> &A, int B, vector<int> * selected, int pointer, int sum) {
    if(pointer == A.size()) {
        return false;
    }
    if(sum == B ) {
        result->emplace_back(*selected);
        return true;
    }
    if( sum > B) {
        return false;
    }
    selected->emplace_back(A[pointer]);
    driver(result, A, B, selected, pointer + 1, sum + A[pointer]);
    selected->pop_back();
    driver(result, A, B, selected, pointer + 1, sum);
    return true;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > result;
    std::sort(A.begin(),A.end());
    driver(&result,A,B, new vector<int>,1,0);
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

