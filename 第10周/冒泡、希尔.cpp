#include <iostream>
using namespace std;
template<class T>
void swap(T data[], int i, int j) {
	T temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
template<class T>
class MPsort {
public:
	void sort(T data[],int n) {
		for (int i = 0; i <= n - 1;i++) {
			int t = 1;
			for (int j = i; j<n-i-1; j++)
				if (data[j] > data[j + 1])        
				{
					swap(data,j, j + 1);     
					t = 0;
				}
			if (t)
			break;
		}
	}

};
template<class T>
class XRsort {
public:
	void sort(T data[], int n) {
		int h = n / 2;
		while (h)
		{
			for (int start = 0; start < h; start++) {
				for (int i = start+h; i < n; i+=h)
				{
					T temp = data[i];
					int j = i;
					while (j-h>=0 && temp < data[j - h])
					{
						data[j] = data[j - h];
						j -= h;
					}

					data[j] = temp;
				}

				h = h / 2;
			}
		}
	}
	void sort2(T data[], int n) {
		int h = n / 2;
		while (h>=1)
		{
				for (int i =h; i < n; i ++)
				{
					T temp = data[i];
					int j = i;
					while (j - h >= 0 && temp < data[j - h])
					{
						data[j] = data[j - h];
						j -= h;
					}

					data[j] = temp;
				}

				h = h / 2;
		}
		
	}
	void sort3(T data[], int n) {
		int h = 1;
		while (h < n / 2) h = 3 * h + 1;
		while(h>=1)
		{
			for (int i = h; i < n; i++)
			{
				T temp = data[i];
				int j = i;
				while (j - h >= 0 && temp < data[j - h])
				{
					data[j] = data[j - h];
					j -= h;
				}

				data[j] = temp;
			}

			h = h / 3;
		}

	}
};
int main()
{
	MPsort<int> text;
	int arr[6] = { 7,1,2,9,5,3 };
	text.sort(arr, 6);
	for (int i = 0; i < 6; i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;
	XRsort<int> t;
	int arr2[9] = { 19,3,56,67,11,2,88,16,44 };
	int arr3[7] = { 12,34,55,1,8,9,22 };
	int arr4[5] = { 2,6,1,9,5 };
	t.sort(arr2, 9);
	for (int i = 0; i < 9; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;
	t.sort(arr3, 7);
	for (int i = 0; i < 7; i++) {
		cout << arr3[i] << " ";
	}
	cout << endl;
	t.sort(arr4, 5);
	for (int i = 0; i < 5; i++) {
		cout << arr4[i] << " ";
	}
	cout << endl;
	return 0;
}