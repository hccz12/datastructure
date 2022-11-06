//leetcode139
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string>();
        for (auto word : wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
//208
class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;
    TrieNode() : isWord(false), children(26, nullptr) {
    }
    ~TrieNode() {
        for (auto& c : children)
            delete c;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* p = root;
        for (char a : word) {
            int i = a - 'a';
            if (!p->children[i])
                p->children[i] = new TrieNode();
            p = p->children[i];
        }
        p->isWord = true;
    }
    bool search(string word) {
        TrieNode* p = root;
        for (char a : word) {
            int i = a - 'a';
            if (!p->children[i])
                return false;
            p = p->children[i];
        }
        return p->isWord;
    }
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (char a : prefix) {
            int i = a - 'a';
            if (!p->children[i])
                return false;
            p = p->children[i];
        }
        return true;
    }
private:
    TrieNode* root;
};
//572
class Solution {
public:
    bool  check(TreeNode* r, TreeNode* s)
    {
        if (!r && !s) return  true;
        if ((!r && s) || (r && !s) || (r->val != s->val)) return false;
        return check(r->left, s->left) && check(r->right, s->right);
    }
    bool dfs(TreeNode* r, TreeNode* s)
    {
        if (!r) return false;

        return check(r, s) || dfs(r->left, s) || dfs(r->right, s);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};
//128
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() < 1) return nums.size();  
        vector<int>dp(nums.size() + 1, 0);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        int mx = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)  
            {
                dp[i] = dp[i - 1] + 1;

            }
            else if (nums[i] == nums[i - 1])
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = 1;  
            }
            mx = max(dp[i], mx);  

        }
        return mx;
    }
};
//561
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};
//274
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>()); // Ωµ–Ú≈≈–Ú
        int i = 1, j = citations.size();
        while (i <= j) {
            int h = i + (j - i) / 2;
            if (citations[h - 1] >= h) i = h + 1;
            else j = h - 1;
        }
        return j;
    }
};
//264
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        for (long long a = 1; a <= INT_MAX; a = a * 2)
            for (long long b = a; b <= INT_MAX; b = b * 3)
                for (long long c = b; c <= INT_MAX; c = c * 5)
                    v.push_back(c);
        sort(v.begin(), v.end());
        return v.at(n - 1);
    }
};