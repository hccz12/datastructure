#include <iostream>
using namespace std;
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
	int res = 0;
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r) {
		if (arr[i] < arr[j]) {
			temp[k] = arr[i];
			i++;
		}
		else {
			temp[k] = arr[j];
			j++;
			res += mid - i + 1;
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
	cout << "逆序对数为" << res << endl;

}

void sortArr(int arr[], int temp[], int l, int r) {
	int n = sizeof(arr) / sizeof(arr[0]);
	if (l < r) {
		if (r - l <= 15) {
			InsertSort1(arr, n);
		}
		int mid = (r + l) / 2;
		sortArr(arr, temp, l, mid);
		sortArr(arr, temp, mid + 1, r);
		if (arr[mid] > arr[mid + 1])
			mergeArr(arr, temp, l, mid, r);
	}
}

void reversePairs(int arr[], int n) {
	int temp[10000] = {};
	memcpy(temp, arr, sizeof(arr));
	sortArr(arr, temp, 0, n - 1);
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
