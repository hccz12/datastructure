//最小堆
#include<iostream>
using namespace std;

class MinHeap
{
public:
	MinHeap(int size);
	~MinHeap();
	void Insert(int e);
	void Delete();
	void swap(int& a, int& b) { int temp = a; a = b; b = temp; }
	int Getsize() { return n - 1; }
	void printHeap();
	friend void sort(MinHeap& minheap, int* res, int n);

private:
	int* p;
	int n;
	int size;

MinHeap::MinHeap(int size)
{
	this->size = size;
	p = new int[size + 1];
	if (p == nullptr) { cout << "内存分配失败！" << endl; exit(-1); }
	n = 1;
}

MinHeap::~MinHeap()
{
	if (p != nullptr) delete[] p;
}
void MinHeap::Insert(int number)
{
	if (n > size) {
		cout << "内存不足，请重新分配空间" << endl;
		return;
	}
	p[n] = number;
	int par = n;
	while (par / 2)
	{
		if (p[par] < p[par / 2])
			swap(p[par], p[par / 2]);
		par /= 2;
	}
	n++;
}
void MinHeap::Delete()
{
	int lc = 1;
	int num = Getsize();
	p[lc] = p[num];
	p[num] = 0;
	while (2 * lc <= num - 1)
	{
		if (p[lc] > p[2 * lc])
			swap(p[lc], p[2 * lc]);
		if (2 * lc + 1 <= num - 1 && p[lc] > p[2 * lc + 1])
			swap(p[lc], p[2 * lc + 1]);
		lc *= 2;
	}
	n--;
}

void MinHeap::printHeap()
{
	cout << "开始打印：";
	for (int i = 1; i < n; ++i)
		cout << p[i] << " ";
	cout << endl;
}
void sort(MinHeap& minheap, int res[], int n)
{
	//res = new int[minheap.count - 1];
	int index = minheap.n;
	for (int i = 0; i < n; i++)
	{
		int curCount = 1;
		int num = index - 1;
		res[i] = minheap.p[curCount];
		minheap.p[curCount] = minheap.p[num];
		while (2 * curCount <= num - 1)
		{
			if (minheap.p[curCount] > minheap.p[2 * curCount])
				swap(minheap.p[curCount], minheap.p[2 * curCount]);
			if (2 * curCount + 1 <= num - 1 && minheap.p[curCount] > minheap.p[2 * curCount + 1])
				swap(minheap.p[curCount], minheap.p[2 * curCount + 1]);
			curCount *= 2;
		}
		index--;
	}
}

int main()
{
	MinHeap myheap(20);
	int sample[] = { 12,11,23,2,4,5,3,8,9,10 };
	for (int i = 0; i < sizeof(sample) / sizeof(int); i++)
		myheap.Insert(sample[i]);
	cout << "最小堆元素总数：" << myheap.Getsize() << endl;
	myheap.printHeap();
	myheap.Delete();
	cout << "删除根节点！" << endl;
	myheap.printHeap();
	int res[9] = { 0 };
	sort(myheap, res, 9);
	cout << sizeof(res) / sizeof(int) << endl;
	for (int i = 0; i < sizeof(res) / sizeof(int); i++)
		cout << res[i] << " ";
	return 0;
}
//703
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > q;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int i = 0; i < int(nums.size()); i++) {
            add(nums[i]);
        }
    }

    int add(int val) {
        q.push(val);
        if (q.size() > K) {
            q.pop();
        }
        return q.top();
    }
};
//1046
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int s : stones) {
            q.push(s);
        }

        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a > b) {
                q.push(a - b);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};
//215
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int n = nums.size();
        build_maxHeap(nums);
        for (int i = 0; i < k - 1; i++)
        {
            swap(nums[0], nums[n - 1 - i]);
            adjust_down(nums, 0, n - 1 - i - 1);
        }
        return nums[0];
    }


    void build_maxHeap(vector<int>& nums)
    {
        int n = nums.size();
        for (int r = n / 2; r> =0; r--)
            adjust_down(nums, r, n - 1);
    }

    void adjust_down(vector<int>& nums, int r, int h)
    {
        if (r > h)
            return;
        int t = nums[r];
        int child = 2 * r + 1;
        while (child <= h)
        {
            if (child + 1 <= h && nums[child] < nums[child + 1])
                child++;
            if (t > nums[child])
                break;
            nums[r] = nums[child];
            r = child;
            child = 2 * r + 1;
        }
        nums[r] = t;
    }
};

