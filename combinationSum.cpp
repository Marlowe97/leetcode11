class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > r;
        vector<int> one;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, target, r, one, 0);
        return r;
    }
private:
    void combinationSumHelper(vector<int> & candidates, int target, vector<vector<int> > & r, vector<int> & one, int start) {
        for(int i = start; i < candidates.size(); i++) {
            if( target == candidates[i] ) {
                one.push_back(candidates[i]);
                r.push_back(one);
                one.pop_back();
            } else if( target > candidates[i] ) {
                one.push_back(candidates[i]);
                combinationSumHelper(candidates, target - candidates[i], r, one, i);
                one.pop_back();
            }
        }
    }
};