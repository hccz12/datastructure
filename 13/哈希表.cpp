#include<iostream>
using namespace std;
#include <map>
template<class K,class V>
class HashTable {
private:
    map<K, V> mapdata;
    int M;
    int size;
public:
    int Getsize() {
        return size;
    }
    HashTable(int M) {
        this->M = M;
        size = 0;
        mapdata = new <K, V> map[M];
    }
    HashTable() {
        this->M = 97;
        size = 0;
        mapdata = new <K, V> map[97];
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
    void print{
    auto iter = mapdata.begin();
    while (iter != mapdata.end()) {
        cout << iter->frist << "," << iter->second << endl;
        ++iter;
    }
    }
};
int main(){
    HashTable<int, int> hash1;
    hash1.add(7, 2);
    hash1.add(3, 23);
    hash1.add(6, 22);
    hash1.add(1, 5);
    hash1.add(4, 11);
    hash1.print();
    hash1.remove(7);
    return 0;
}
