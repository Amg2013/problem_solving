// find the key for & if 
// 1 ... 3 ... 5 
// arry 2.....4....6
// get the next index of the key 
// get max mam of apperes of echae iteam 
// array that stor the max or apperance of each itmes 
// retern the max of thr array 

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        // Initialize count array (indices 0-1000) to track target frequencies
        int count[1001] = {0};
        int max_count = 0;   // Track highest frequency found
        int result = 0;      // Store the most frequent target
        
        // Iterate through array (stop before last element)
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) {
                int target = nums[i + 1];  // Get next element after key
                count[target]++;            // Increment target's count
                
                // Update result if current target has higher frequency
                if (count[target] > max_count) {
                    max_count = count[target];
                    result = target;
                }
            }
        }
        return result;
    }
};
