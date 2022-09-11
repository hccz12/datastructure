//最大堆
#include <iostream>
using namespace std;
template<class T>
class MaxHeap
{
private:
	T *data;
	int size;
	int capacity;
	void siftup(int k) {
		while (k > 0 && data[parient(k)] < data[k]) {
			swap(data, k, parient(k));
			k = parient(k);
		}
	}
	void siftdown(int n) {
		while (leftchild(n) < Getsize()) {
			int j = leftchild(n);
			if (j + 1 < Getsize() && data[j + 1] > data[j]) {
				j = rightchild(n);
			}
			if (data[n] > data[j]) {
				break;
			}
			swap(data, n, j);
			n = j;
		}
	}
public:
	MaxHeap(T arr[], int size) {
		this->size = size;
		capacity = 2 * size;
		data = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = arr[i];
		}
		for (int i = parient(size -1); i >= 0; i--)
		{
			siftdown(i);

		}
	}
	~MaxHeap();
	int Getsize(){
		return size;
	};
	bool isEmpty(){
		return size == 0;
	}
	void swap(T data[], int i, int k) {
		T temp = data[i];
		data[i] = data[k];
		data[k] = temp;
	}
	int parient(int index) {
		if (index == 0)
			cout<<"该堆为空" << endl;
		return(index - 1) / 2;
			
	}
	int leftchild(int index) {
		return index * 2 + 1;
	}
	int rightchild(int index) {
		return index * 2 + 2;
	}
	void add(T e) {
		data[size + 1] = e;
		size++;
		siftup(Getsize() - 1);
	}
	T FindMax() {
		if (Getsize() == 0)
			cout << "查找出错，堆为空!" << endl;
		return data[0];
	}
	T extractMax() {
		T ret = FindMax();
		swap(data, 0, Getsize() - 1);
		siftdown(0);
		return ret;
	}
	

	void input()
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";

		}
		cout << endl;

	}
};
template<class T>
class heapsort {
	void sort(T data[]) {
		MaxHeap<T> heap;
		int n = sizeof(data) / sizeof(data[0]);
		for (int i = 0; i < n; i++) {
			heap.add(data[i]);
		}
		for (int i = n - 1; i >= 0; i--) {
			data[i] = heap.extractMax();
		}
	}
	void sort2(T data[]) {
		int n = sizeof(data) / sizeof(data[0]);
		if (n <= 1)return;
		for (int i = (n - 2) / 2; i >= 0; i--) {
			siftdown(data,i,n);
		}
		for (int i = n - 1; i >= 0; i++) {
			swap(data, 0, i);
			siftdown(data, 0, i);
		}
	}
	void siftdown(T data[],int k,int n) {
		while( 2*k+1<n) {
			int j = 2 * k + 1;
			if (j + 1 < n && data[j + 1] > data[j]) {
				j ++;
			}
			if (data[k] > data[j]) {
				break;
			}
			swap(data, k, j);
			k = j;
		}
	}
};
int main() {
	int arr[7] = { 34,56,72,11,57,23,41 };
	MaxHeap<int> maxheap(arr,7);
	maxheap.add(6);
	maxheap.extractMax();
	heapsort<int> hsort;
	hsort.sort2();
	return 0;
}

