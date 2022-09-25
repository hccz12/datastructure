#include<iostream>
using namespace std;
struct Node{
    int beg;
    int end;
    int val;
    Node* left;
    Node* right;

    Node() {
        beg = end = val = 0;
        left = right = nullptr;
    }
};
template<class T>
class NumArray {
public:
    NumArray(T nums[]) {
        this->nums = nums;
        root = buildTree(nums, 0, nums.size() - 1);
        calcTree(root);
    }

    void update(int index, int val) {
        if (nums[index] == val) {
            return;
        }
        int diff = val - nums[index];
        nums[index] = val;
        updateTree(root, index, diff);
    }

    int sumRange(int left, int right) {
        return getValue(root, right) - getValue(root, left - 1);
    }

private:
    Node* buildTree(vector<int>& nums, int beg, int end) {
        if (beg > end) {
            return nullptr;
        }
        Node* p = new Node;
        p->beg = beg;
        p->end = end;
        if (beg == end) {
            p->val = nums[beg];
        }
        else {
            p->left = buildTree(nums, beg, (beg + end) / 2);
            p->right = buildTree(nums, (beg + end) / 2 + 1, end);
        }
        return p;
    }

    int calcTree(Node* p) {
        if (p == nullptr) {
            return 0;
        }
        p->val += calcTree(p->left) + calcTree(p->right);
        return p->val;
    }

    void updateTree(Node* p, int index, int diff) {
        if (p == nullptr) {
            return;
        }
        if (p->beg <= index && p->end >= index) {
            p->val += diff;
        }
        if (p->beg > index || p->end < index) {
            return;
        }
        updateTree(p->left, index, diff);
        updateTree(p->right, index, diff);
    }

    int getValue(Node* p, int index) {
        if (index < 0) {
            return 0;
        }
        if (index < p->beg) {
            return getValue(p->left, index);
        }
        else if (index > p->end) {
            return p->val + getValue(p->right, index);
        }
        else if (index == p->end) {
            return p->val;
        }
        else {
            int mid = (p->beg + p->end) / 2;
            if (index <= mid) {
                return getValue(p->left, index);
            }
            else {
                return p->left->val + getValue(p->right, index);
            }
        }
    }

    void freeTree(Node* p) {
        if (p == nullptr) {
            return;
        }
        freeTree(p->left);
        freeTree(p->right);
        delete p;
    }

private:
    Node* root;
    vector<int> nums;
};
//leetcode
private:
    vector<int>sum;
public:
    NumArray(vector<int>& nums) {
        if (nums.size()) sum.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            sum.push_back(sum[sum.size() - 1] + nums[i]);
        }
    }

    void update(int i, int val) {
        int t = i == 0 ? val - sum[i] : val - (sum[i] - sum[i - 1]);
        for (; i < sum.size(); i++)
        {
            sum[i] += t;
        }
    }

    int sumRange(int i, int j) {
        return i == 0 ? sum[j] : sum[j] - sum[i - 1];
    }
};
//303
class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        int l = nums.size();
        sum.resize(l + 1);
        sum[0] = 0;
        for (int i = 1; i < l; i++)
        {
            sum[i] += sum[i - 1] + nums[i - 1];
        }

    }

    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};
