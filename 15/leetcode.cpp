//1147
class Solution {
public:
    bool check(int s1, int s2, int d, string text)
    {
        for (int i = s1, j = s2 - d + 1; i <= s1 + d - 1; i++, j++)
            if (text[i] != text[j])return false;
        return true;
    }
    int dp[1010][1010];
    int longestDecomposition(string text) {
        int l, r;
        l = text.length() / 2;
        r = l;
        if (text.length() % 2 == 0)
            l--;
        else
        {
            l--, r++;
        }
        for (int i = 0; i < text.length(); i++)
            for (int j = i; j < text.length(); j++)//初始化
                dp[i][j] = 1;
        for (int i = l, j = r; i >= 0; i--, j++)
        {
            for (int d = 1; d <= (j - i + 1) / 2; d++)
            {
                if (check(i, j, d, text))构成回文串
                {
                    dp[i][j] = max(dp[i][j],dp[i + d][j - d] + 2); 比较
                }
            }
        }
        return dp[0][text.length() - 1];
    }
};
//1392
const int N = 1e5 + 10, P = 131;
typedef unsigned long long ULL;
class Solution {
public:
    ULL h[N] = { 0 }, p[N] = { 0 };
    ULL get(int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
    string longestPrefix(string s) {
        int n = s.size();
        p[0] = 1, h[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i - 1];
        }
        for (int i = n - 1; i; i--)
        {
            if (get(1, i) == get(n - i + 1, n))
                return s.substr(0, i);
        }
        return "";
    }
};
//187
class Solution {
    const int L = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        int n = s.length();
        for (int i = 0; i <= n - L; i++)
        {
            string sub = s.substr(i, L);
            if (++cnt[sub] == 2)
            {
                ans.push_back(sub);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return {};
        map<char, int> m = { {'A',0}, {'G',1}, {'C',2}, {'T',3} };
        unordered_map<int, int> c;
        int num = 0, i = 0, k = 10;
        while (i < k - 1)
        {
            num <<= 2;
            num |= m[s[i++]];
        }
        vector<string> ans;
        while (i < s.size())
        {
            num = (num << 2) & ~(3 << 2 * k);
            num |= m[s[i]];
            c[num]++;
            if (c[num] == 2)
                ans.push_back(s.substr(i - k + 1, 10));
            i++;
        }
        return ans;
    }
};
