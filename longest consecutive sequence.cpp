class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s;

        // Store all numbers in the set
        for (int num : nums) {
            s.insert(num);
        }

        int longest = 0;

        for (int num : s) {

            // Check if this is the start of a sequence
            if (s.find(num - 1) == s.end()) {

                int current = num;
                int count = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
