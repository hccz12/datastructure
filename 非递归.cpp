//改定义
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
        int p = partition2(arr, l, r-1);//arr[l,r)
        quickSort(arr, l, p );
        quickSort(arr, p + 1, r);
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size() );
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
//最小k个数、最小的k个数非递归
class Solution {
public:
    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int partition2(vector<int>& arr,int l,int r) {
        int p = l + (rand() % (r - l ));
        swap(arr, l, p);
        int j = r-1, i = l + 1;
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
    void quickSort(vector<int>& arr,int k) {
        int l = 0, r = arr.size()-1 ;
        while (l < r) {
            int p = partition2(arr, l, r);
            if (k == p)
                return arr[p];
            if (k < p)
                r = p;
            else l = p + 1;
        }
       
        
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr,k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
//第k大元素非递归
class Solution {
public:
    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int partition2(vector<int>& arr, int l, int r) {
        int p = l + (rand() % (r - l ));
        swap(arr, l, p);
        int j = r-1, i = l + 1;
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
    void quickSort(vector<int>& arr, int k) {
        int l = 0, r = arr.size() ;
        while (l < r) {
            int p = partition2(arr, l, r);
            if (k == p)
                return arr[p];
            if (k < p)
                r = p - 1;
            else l = p + 1;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, k);
        return nums[nums.size() - k];
    }
};
//归并排序改定义
void InsertSort1(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; --j) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}
void mergeArr(int arr[], int temp[], int l, int mid, int r) {
    int i = l, j = mid, k = 0;
    while (i <mid && j < r) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    i = l;
    for (int e = 0; ((e < k) && (i <= r)); e++) {
        arr[i] = temp[e];
        i++;
    }

}

void sortArr(int arr[], int temp[], int l, int r) {
    int n = sizeof(arr) / sizeof(arr[0]);
    if (r-1>1) {
        if (r - l <= 15) {
            InsertSort1(arr, n);
        }
        int mid = (r + l) / 2;
        sortArr(arr, temp, l, mid);
        sortArr(arr, temp, mid, r);
        if (arr[mid] > arr[mid + 1])
            mergeArr(arr, temp, l, mid, r);
    }
}

void reversePairs(int arr[], int n) {
    int temp[10000] = {};
    memcpy(temp, arr, sizeof(arr));
    sortArr(arr, temp, 0, n );
}

int main() {

    int arr[] = { 5,4,6,3,1,2,8,7,10,57,26,99,9,12,87,45,33 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "排序前 " << endl;
    for (int j = 0; j < n; j++) {
        cout << arr[j] << "   ";
    }
    reversePairs(arr, n);
    cout << endl << "排序后 " << endl;
    for (int j = 0; j < n; j++) {
        cout << arr[j] << "   ";
    }
    return 0;
}

//leetcode875
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0;
        int r = piles.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (EatTime(piles, mid) <= h)
                r = mid;
            else l = mid + 1;
        }
        return l;
    }
    int EatTime(vector<int>& piles, int k) {
        int res = 0;
        for (int i = 0; i++; i < piles.size()) {
            res =res+ piles[i] / k ;
            if (piles[i] % k != 0)
                res++;
            else res = res;
        }
        return res;
    }
};
//leetcode374
class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n ;
        while (l <= r) 
        {
            int mid = l + (r - l) / 2;
            if (guess(mid) == 0)
                return mid;
            if (guess(mid) == -1)
               r = mid - 1; 
            if (guess(mid) == 1)
               l = mid + 1;
        }
        return -1;
    }
};
//leetcode35
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int  mid =l+ ( r-l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }
        return l;
    }
};
//leetcode852
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0; int r = arr.size()-1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid + 1]) {
                r = mid;
            }
            if (arr[mid] < arr[mid+1])
                l = mid + 1;
        }
        return l;
    }
};