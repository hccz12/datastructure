#include <iostream>
#include<ctime>
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
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int partition(int arr[], int l, int r) {
	int p =l+( rand() % (r-l+1));
	swap(arr, l, p);
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < arr[l]) {
			j++;
			swap(arr, i, j);
		}
			
	}
	swap(arr, l, j);
	return j;
}
int partition2(int arr[], int l, int r) {
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
void qulicksort(int arr[], int l, int r) {
	if (l >= r) return;
	if (r - l <= 15) {
		InsertSort1(arr, r-l+1);
	}
	int p = partition(arr, l, r);
	qulicksort(arr, l, p - 1);
	qulicksort(arr, p + 1, r);
}

void qulicksort(int arr[], int n) {
	qulicksort(arr, 0, n-1);
}
void qulicksort2(int arr[], int l, int r) {
	if (l >= r) return;
	if (r - l <= 15) {
		InsertSort1(arr, r - l + 1);
	}
	int p = partition2(arr, l, r);
	qulicksort(arr, l, p - 1);
	qulicksort(arr, p + 1, r);
}

void qulicksort2(int arr[], int n) {
	qulicksort2(arr, 0, n - 1);
}
void qulicksort3(int arr[], int l, int r) {
	if (l >= r) return;
	if (r - l <= 15) {
		InsertSort1(arr, r - l + 1);
	}
	int p = l + (rand() % (r - l + 1));
	swap(arr, l, p);
	//arr[l+1,lt],arr[lt+1,i-1],arr[gt,r]
	int lt = l, i = l + 1, gt = r + 1;
	while (i < gt) {
		if (arr[i] < arr[l]) {
			lt++;
			swap(arr, i, lt);
			i++;
		}
		else if (arr[i] > arr[l]) {
			gt--;
			swap(arr, i, gt);
		}
		else {
			i++;
		}
	}
	swap(arr, l, lt);
	qulicksort3(arr, l, lt - 1);
	qulicksort3(arr, gt, r);
}

void qulicksort3(int arr[], int n) {
	qulicksort3(arr, 0, n - 1);
}
int main() 
{

	int arr[] = { 5,4,6,3,1,2,8,7,10,57,26,99,9,12,87,45,33 };
	int arr2[] = { 78,14,34,5,89,91,100,33,54,1,7,55,31,29,30 };
	int arr3[] = { 8,24,31,57,9,11,99,36,24,14,78,95,39,29,30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "排序前 " << endl;
	for (int j = 0; j < n; j++) {
		cout << arr[j] << "   ";
	}
	cout << endl;
	qulicksort(arr, n);
	cout << endl << "快速排序后 " << endl;
	for (int j = 0; j < n; j++) {
		cout << arr[j] << "   ";
	}
	cout << endl;
	int k = sizeof(arr2) / sizeof(arr2[0]);
	cout << "排序前 " << endl;
	for (int j = 0; j < k; j++) {
		cout << arr2[j] << "   ";
	}
	cout << endl;
	qulicksort2(arr2, k);
	cout << endl << "双路快速排序后 " << endl;
	for (int j = 0; j < k; j++) {
		cout << arr2[j] << "   ";
	}
	cout << endl;
	int z = sizeof(arr3) / sizeof(arr3[0]);
	cout << "排序前 " << endl;
	for (int j = 0; j < z; j++) {
		cout << arr3[j] << "   ";
	}
	cout << endl;
	qulicksort3(arr3, z);
	cout << endl << "三路快速排序后 " << endl;
	for (int j = 0; j < z; j++) {
		cout << arr3[j] << "   ";
	}
	cout << endl;
	return 0;
}
