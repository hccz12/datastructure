#include<iostream>
using namespace std;
template <class T>
class binarySearch {
	int search(T array[], int l, int r, T target) {
		if (l > r) return -1;
		int mid = l + (r - l) / 2;
		if (array[mid] == target)
			return mid;
		if (array[mid] < target)
			return search(array, mid + 1, r, target);
		else return search(array, l, mid - 1, target);
	}
public:
	int search(T array[], int target) {//递归实现
		int l = 0;
		int r = (sizeof(array) / sizeof(array[0])) - 1;
		return search(array, l, r, target);
	}
	int search1(T array[], int target) {//非递归实现
		int l = 0;
		int r = (sizeof(array) / sizeof(array[0])) - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (array[mid] == target)
				cout << mid << endl;
			if (array[mid] < target) {
				l = mid + 1;
			}
			else r = mid - 1;
		}
		return -1;
	}
	//>target的最小索引
	int upper(T array[], T target) {
		int l = 0;
		int r = sizeof(array) / sizeof(array[0]);
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (array[mid] < target)
				l = mid + 1;
			else
				r = mid;
		}
		return l;
	}
	//>target最小索引；==target最大索引
	int ceil(T array[], T target) {
		int u = upper(array, target);
		if (u - 1 > 0 && array[u - 1] == target)
			return u - 1;
		else return u;
	}
	//>=target最小索引
	int lower_ceil(T array[], T target) {
		int l = 0;
		int r = sizeof(array) / sizeof(array[0]);
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (array[mid] <= target)
				l = mid + 1;
			else
				r = mid;
		}
		return l;

	}
	//<target的最大索引
	int lower(T array[], T target) {
		int l = -1; int r = array.size() - 1;
		while (l < r) {
			int mid = l + (r - 1 + 1) / 2;
			if (array[mid] < target)
				l = mid;
			else r = mid - 1;
		}
		return l;
	}
	//==target最小索引，！=target,返回lower
	int lower_floor(T array[], T target) {
		int k = lower(array, target);
		if (k + 1 < array.size() && array[k + 1] == target)
			return k + 1;
		else return k;
	}
	//<=target最大索引
	int upper_floor(T array[], T target) {
		int l = -1; int r = array.size() - 1;
		while (l < r) {
			int mid = l + (r - 1 + 1) / 2;
			if (array[mid] <= target)
				l = mid;
			else r = mid - 1;
		}
		return l;
	}
};
	int main() {
		binarySearch<int> b;
		int arr[] = { 1,4,7,8,12,34,45,76,99 };
		b.search(arr, 12);
		b.search1(arr, 56);
		b.upper(arr, 8);
		b.ceil(arr, 23);
		return 0;
	}