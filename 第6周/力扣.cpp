//颜色分类
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++; i++;
            }
            else if (nums[i] == 1) {
                ++i;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            }
        }
    }
};       
//最小k个数、最小的k个数
class Solution {
public:
    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int partition2(vector<int>& arr, int l, int r) {
        int p = l + (rand() % (r - l + 1));
        swap(arr, l, p);
        int j = r, i = l + 1;
        while (true) {
            while (i <= j && arr[i] < arr[l])
                i++;
            while (j >= i && arr[j] > arr[l])
                j--;
            if (i >= j) break;
            swap(arr, i, j);
            i++;
            j--;
        }
        swap(arr, l, j);
        return j;
    }
    void quickSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        int p = partition2(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size() - 1);
        return vector<int>(arr.begin(), arr.begin() + k);
    }  
};
//第k大元素
class Solution {
public:
    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int partition2(vector<int>& arr, int l, int r) {
        int p = l + (rand() % (r - l + 1));
        swap(arr, l, p);
        int j = r, i = l + 1;
        while (true) {
            while (i <= j && arr[i] < arr[l])
                i++;
            while (j >= i && arr[j] > arr[l])
                j--;
            if (i >= j) break;
            swap(arr, i, j);
            i++;
            j--;
        }
        swap(arr, l, j);
        return j;
    }
    void quickSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        int p = partition2(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
};
