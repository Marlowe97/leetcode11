class Solution {
public:
void nextPermutation(vector<int>& nums) 
    {
        if (nums.size() <= 1 )
            return;
        int lf = nums.size()-2, rt = nums.size()-1;
        while (lf >= 0 && nums[lf] >= nums[lf+1]) --lf;
        if (lf >= 0) {
            while (rt >= lf && nums[rt] <= nums[lf]) --rt;
            swap(nums, lf, rt);
        }
        ++ lf;
        sort(nums.begin()+lf, nums.end());
        return;
    }
private:
    void swap(vector<int> &nums, int lhs, int rhs)
    {
        int tmp = nums[lhs];
        nums[lhs] = nums[rhs];
        nums[rhs] = tmp;
        return;
    }
};