#include <iostream>
using namespace std;

class UnionFind {
private:
    int parent[];
    int count;
    int rank[];

public:
    UnionFind(int count) {
        parent.resize(count);
        rank.resize(count);
        this->count = count;
        for (int i = 0; i < count; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int p) {
        assert(p >= 0 && p < count);
        if (p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
    void unionElement(int p, int q) {
        int pRoot = find(p), qRoot = find(q);
        if (pRoot == qRoot)
            return;
        if (rank[pRoot] < rank[qRoot])
            parent[pRoot] = qRoot;
        else if (rank[qRoot] < rank[pRoot])
            parent[qRoot] = pRoot;
        else {
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
};