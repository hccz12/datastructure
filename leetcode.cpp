//17
class Solution {
	unordered_map<char, string> map;//����ÿ������ӳ�����ĸ
	vector<string> ret;//�������н�����
public:
	vector<string> letterCombinations(string digits)
	{
		if (digits.empty()) return ret;
		//����ÿ������ӳ�����ĸ
		map['2'] = "abc";
		map['3'] = "def";
		map['4'] = "ghi";
		map['5'] = "jkl";
		map['6'] = "mno";
		map['7'] = "pqrs";
		map['8'] = "tuv";
		map['9'] = "wxyz";

		//�����Ҫ����ĸ����
		int num = digits.size();
		string cur;
		dfs(digits, cur, num, 0);
		return ret;
	}
	//cur���ҵ�����ĸ�ȴ�������棬�ȵ���ĸ����������Ҫ�ĸ���ʱ����ѹ��������
	//index����¼�������˵�ǰ���ֵĵڼ����ַ�
	//num: �����Ҫ����ĸ����
	//n:��ǰ�õ��˵�һ������
	void dfs(string digits, string cur, int num, int n)
	{
		if (cur.size() == num)//�ҵ���һ�����н�
		{
			ret.push_back(cur);
			return;
		}
		//������ǰ����ʣ�����ĸ
		for (int i = 0; i < map[digits[n]].size(); i++)//ע������ÿһ�㣬���Ǵӵ�һ����ĸ��ʼ���б���
		{
			//�ѵ�ǰ���ֶ�Ӧ�ĵ�index����ĸ����cur������
			cur.push_back(map[digits[n]][i]);
			//����ʣ����ĸ
			dfs(digits, cur, num, n + 1);
			//����
			cur.pop_back();
		}
	}

};
//36
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int rows[9][9];
		int columns[9][9];
		int subboxes[3][3][9];

		memset(rows, 0, sizeof(rows));
		memset(columns, 0, sizeof(columns));
		memset(subboxes, 0, sizeof(subboxes));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char c = board[i][j];
				if (c != '.') {
					int index = c - '0' - 1;
					rows[i][index]++;
					columns[j][index]++;
					subboxes[i / 3][j / 3][index]++;
					if (rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1) {
						return false;
					}
				}
			}
		}
		return true;
	}
};
//912
class Solution {
	int partition(vector<int>& nums, int l, int r) {
		int pivot = nums[r];
		int i = l - 1;
		for (int j = l; j <= r - 1; ++j) {
			if (nums[j] <= pivot) {
				i = i + 1;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[i + 1], nums[r]);
		return i + 1;
	}
	int randomized_partition(vector<int>& nums, int l, int r) {
		int i = rand() % (r - l + 1) + l; // ���ѡһ����Ϊ���ǵ���Ԫ
		swap(nums[r], nums[i]);
		return partition(nums, l, r);
	}
	void randomized_quicksort(vector<int>& nums, int l, int r) {
		if (l < r) {
			int pos = randomized_partition(nums, l, r);
			randomized_quicksort(nums, l, pos - 1);
			randomized_quicksort(nums, pos + 1, r);
		}
	}
public:
	vector<int> sortArray(vector<int>& nums) {
		srand((unsigned)time(NULL));
		randomized_quicksort(nums, 0, (int)nums.size() - 1);
		return nums;
	}
};
//20
class Solution {
public:
	bool isValid(string s) {
		int n = s.size();
		if (n % 2 == 1) {
			return false;
		}

		unordered_map<char, char> pairs = {
			{')', '('},
			{']', '['},
			{'}', '{'}
		};
		stack<char> stk;
		for (char ch : s) {
			if (pairs.count(ch)) {
				if (stk.empty() || stk.top() != pairs[ch]) {
					return false;
				}
				stk.pop();
			}
			else {
				stk.push(ch);
			}
		}
		return stk.empty();
	}
};
//71
class Solution {
public:
	string simplifyPath(string path) {
		auto split = [](const string& s, char delim) -> vector<string> {
			vector<string> ans;
			string cur;
			for (char ch : s) {
				if (ch == delim) {
					ans.push_back(move(cur));
					cur.clear();
				}
				else {
					cur += ch;
				}
			}
			ans.push_back(move(cur));
			return ans;
		};

		vector<string> names = split(path, '/');
		vector<string> stack;
		for (string& name : names) {
			if (name == "..") {
				if (!stack.empty()) {
					stack.pop_back();
				}
			}
			else if (!name.empty() && name != ".") {
				stack.push_back(move(name));
			}
		}
		string ans;
		if (stack.empty()) {
			ans = "/";
		}
		else {
			for (string& name : stack) {
				ans += "/" + move(name);
			}
		}
		return ans;
	}
};
//56
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() == 0) {
			return {};
		}
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> merged;
		for (int i = 0; i < intervals.size(); ++i) {
			int L = intervals[i][0], R = intervals[i][1];
			if (!merged.size() || merged.back()[1] < L) {
				merged.push_back({ L, R });
			}
			else {
				merged.back()[1] = max(merged.back()[1], R);
			}
		}
		return merged;
	}
};
//75
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int ptr = 0;
		for (int i = 0; i < n; ++i) {
			if (nums[i] == 0) {
				swap(nums[i], nums[ptr]);
				++ptr;
			}
		}
		for (int i = ptr; i < n; ++i) {
			if (nums[i] == 1) {
				swap(nums[i], nums[ptr]);
				++ptr;
			}
		}
	}
};
//264
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n + 1);
		dp[1] = 1;
		int p2 = 1, p3 = 1, p5 = 1;
		//���г���������1�������ɸ�2��3��5�õ���
		for (int i = 2; i <= n; i++) {
			int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
			dp[i] = min(min(num2, num3), num5);
			//�Ѿ��˹��ľͽ�һ�����ظ����ˣ��������Զ�ȥ�أ�2*3��3*2һ������p2��p3��+1��
			if (dp[i] == num2) {
				p2++;
			}
			if (dp[i] == num3) {
				p3++;
			}
			if (dp[i] == num5) {
				p5++;
			}
		}
		return dp[n];
	}
};
