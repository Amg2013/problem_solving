class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int l= s.size();

        for (int i =0;i<l/2;i++)
        {
            if (s[i]!=s[l-1-i])
            {
             return false;
            }
        }
        return true;
    }
};