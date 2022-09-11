//最大堆
#include <iostream>
using namespace std;
template<class T>
class MaxHeap
{
private:
	T* data;
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
		for (int i = parient(size - 1); i >= 0; i--)
		{
			siftdown(i);

		}
	}
	int Getsize() {
		return size;
	};
	bool isEmpty() {
		return size == 0;
	}
	void swap(T data[], int i, int k) {
		T temp = data[i];
		data[i] = data[k];
		data[k] = temp;
	}
	int parient(int index) {
		if (index == 0)
			cout << "该堆为空" << endl;
		return(index - 1) / 2;

	}
	int leftchild(int index) {
		return index * 2 + 1;
	}
	int rightchild(int index) {
		return index * 2 + 2;
	}
	void add(T e) {
		size++;
		data[size-1] = e;
		
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
		size--;
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
class PrioritQueue {
	MaxHeap<T> heap;
public:
	PrioritQueue(T data[],int size) {
		heap = new MaxHeap<T>(data,size);
	}
	int Getsize() {
		return heap.Getsize();
	}
	bool isEmpty() {
		return heap.isEmpty();
	}
	T GetFirst() {
		return heap.FindMax();
	}
	void enqueue(T e){
		return heap.add(e);
	}
	void dequeue() {
		 heap.extractMax();
	}
	void input() {
		return heap.input();
	}
};
int main() {
	int arr[5] = { 34,11,78,5,41 };
	PrioritQueue<int> que(arr,5);
	que.enqueue(37);
	que.input();
	que.GetFirst();
	que.dequeue();


	return 0;
}

