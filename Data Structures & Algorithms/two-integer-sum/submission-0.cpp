class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i != j && nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
        return {0,0};
    }
};

/*
nums = [3,4,5,6] target = 7

x + y = 7
x = 7 - y

x = 7 - 3 = 4
x = 7 - 4 = 3
x = 7 - 5 = 2
x = 7 - 6 = 1

<4,0>
<3,1>
<2,2>
<1,3>


-------
Input: nums = [4,5,6], target = 10

x + y = 10
x = 10 - y

x = 10 - 4 = 6
x = 10 - 5 = 5
x = 10 - 6 = 4

-----
*/