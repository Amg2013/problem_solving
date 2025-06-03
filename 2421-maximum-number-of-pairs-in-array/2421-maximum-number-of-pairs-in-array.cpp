class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int freq[101] = {0};
        for(int i = 0, n = nums.size(); i < n; ++i) ++freq[nums[i]];
        int pair = 0, left = 0;
        for(int i = 0; i < 101; ++i){
            pair += freq[i] / 2;
            left += freq[i] & 1;
        }
        return {pair , left};
    }
};
