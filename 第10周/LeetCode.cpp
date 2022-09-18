//88
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j;
        int t;
        int i;
        for (int s = 0; s < n; s++) {
            nums1[m + s] = nums2[s];
        }
        for (i = 0; i < m + n - 1; i++) {
            t = nums1[i + 1];
            for (j = i + 1; j >= 0 && t < nums1[j - 1]; j--) {
                nums1[j] = nums1[j - 1];
            }
            nums1[j] = t;
        }
    }
};
//169
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0;
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            if (n == 0) {
                ans = nums[i];
                n = 0;
            }
            if (nums[i] == ans)
                n++;
            else
                n--;
        }
        return ans;
    }
};
//15
class Solution {
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int p = rand() % (r - l + 1) + l;
        swap(nums[l], nums[p]);
        int num = nums[l];
        while (l < r) {
            while (l < r && nums[r] >= num) --r;
            nums[l] = nums[r];
            while (l < r && nums[l] <= num) ++l;
            nums[r] = nums[l];
        }
        nums[l] = num;

        quickSort(nums, l, l - 1);
        quickSort(nums, l + 1, r);
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n - 1);

        vector<vector<int>> res;
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue; // ШЅжи
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    res.push_back({ nums[i], nums[l], nums[r] });
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
                else if (nums[i] + nums[l] + nums[r] > 0) {
                    --r;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
                else {
                    ++l;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                }
            }
        }
        return res;
    }
};
