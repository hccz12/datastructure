//leetcode75  1
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int a[3] = { 0 };
		for (int num : nums) {
			a[num]++;
		}
		for (int i = 0; i < a[0]; i++) {
			nums[i] = 0;
		}
		for (int i = a[0]; i < a[0] + a[1]; i++) {
			nums[i] = 1;
		}
		for (int i = a[0] + a[1]; i < a[0] + a[1] + a[2]; i++) {
			nums[i] = 2;
		}
	}
};
//2
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int r = 3;
		int a[3] = { 0 };
		for (int num : nums) {
			a[num]++;
		}
		int index[3 + 1] = { 0 };
		for (int i = 0; i < r; i++) {
			index[i + 1] = index[i] + a[i];
		}
		for (int i = 0; i + 1 < 4; i++) {
			for (int j = index[i]; j < index[i + 1]; j++) {
				nums[j] = i;
			}
		}
	}
};