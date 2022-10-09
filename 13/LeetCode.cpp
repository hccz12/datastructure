//387
class Solution {
public:
    int firstUniqChar(string s) {
        int data[26] = { 0 };
        for (int i = 0; i < s.length(); i++) {
            data[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (data[s[i] - 'a'] == 1)
                return i;
        }
        return-1;

    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
            if (map[num] >= 2) return true;
        }
        return false;
    }
};
//
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        vector<int> data;
        for (auto& it : count) {
            if (it.second > nums.size() / 3)
                data.push_back(it.first);
        }
        return data;
    }
};