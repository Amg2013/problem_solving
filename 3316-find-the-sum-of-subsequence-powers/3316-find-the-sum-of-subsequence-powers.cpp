int mod = 1000000007;

long long dp[2][2][51][51];

//memoization soln (exactDiff used to check if minFound, i.e. minDiff present in subsequence)
long long helper(int i, int k, bool exactDiff, bool minFound, vector<int> &nums, int &minDiff){ //returns no. of subsequences with minDiff
    if (k == 0){ return minFound; }
    if (i == nums.size()){ return 0; }

    if (dp[exactDiff][minFound][i][k] == -1){ //just need to update exactDiff properly
        long long skip = helper(i + 1, k, (exactDiff && i + 1 < nums.size() && nums[i] == nums[i + 1]), minFound, nums, minDiff);

        int j = upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + minDiff - 1) - nums.begin();
        long long pick = helper(j, k - 1, (j < nums.size() && nums[j] - nums[i] == minDiff), (minFound || exactDiff), nums, minDiff);

        dp[exactDiff][minFound][i][k] = (skip + pick)%mod;
    }

    return dp[exactDiff][minFound][i][k];
}


class Solution {
public:
// devied the nums into lenght of k 
// in each subset take the abs form diff
/// sum them 
// return the reslut 

int sumOfPowers(vector<int> &nums, int k){
    sort(nums.begin(), nums.end());

    long long sop = 0;
    unordered_set<int> done; //stores minDiff already checked
    for (int i = 0; i < nums.size(); ++i){
        for (int j = i + 1; j < nums.size(); ++j){
            int minDiff = nums[j] - nums[i];
            if (done.find(minDiff) != done.end()){ continue; }
            done.insert(minDiff);

            //updating sop with no. of subsequences with curr minDiff
            memset(dp, -1, sizeof(dp));
            sop = (sop + (1ll*minDiff*helper(0, k, 0, 0, nums, minDiff))%mod)%mod;
        }
    }

    return sop;
}  };