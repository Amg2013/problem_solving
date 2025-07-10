class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {

            for(int j = i+1; j < nums.size(); j++) { 

                 // j = i + 1 to avoid duplicate & self-pairing

                if(nums[i] + nums[j] == target) {
                    return {i, j};  // return a vector with the indices
                }
            }
        }
        return {}; // return empty vector if no pair found
    }
};
