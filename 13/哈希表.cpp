#include<iostream>
#include <map>
using namespace std;
template<class K, class V>
class HashTable {
private:
    map<K, V> mapdata;
    int size;
public:
    int Getsize() {
        return size;
    }
    HashTable() {;
        size = 0;
    }
    void add(K key, V value) {
        if (mapdata.count(key) != 0) {
            mapdata.insert({ key, value });
        }
        else
            mapdata.insert({ key, value });
        size++;
    }
    void remove(K key) {
        if (mapdata.count(key) != 0) {
            mapdata.umap(key);
            size--;
        }
        else
            cout << "该元素不存在！" << endl;

    }
    void get(K key, V value) {
        mapdata[key] = value;
    }
    void print() {
        for (auto node : mapdata) {
            cout << node.first << ": " << node.second << endl;
        }

    }

};
int main() {
    HashTable<int, int> hash1;
    hash1.add(7, 2);
    hash1.add(3, 23);
    hash1.add(6, 22);
    hash1.add(1, 5);
    hash1.add(4, 11);
    hash1.print();
    hash1.remove(7);
    hash1.print();
    return 0;
}
