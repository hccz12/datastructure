#include <iostream>
#include <string>
#include <queue>
using namespace std;
template <class Key, class Value>
class BSTMap {
public:
    BST() {
        root = NULL;
        size = 0;
    }

    ~BST() {}

    int getsize() {
        return size;
    }

    bool isEmpty() {
        return size== 0;
    }

    void Insert(Key key, Value value) {
        root = Insert(root, key, value);
    }

    Value* Search(Key key) {
        return Search(root, key);
    }
    void setvalue(Key key, Value value) {
        setvalue(root, key,  value);
    }
    void removeMin() {
        if (root)
            root = removeMin(root);
    }
    void removeMax() {
        if (root)
            root = removeMax(root);
    }
    void Remove(Key key) {
        root = Remove(root, key);
    }
private:
    Node* Insert(Node* node, Key key, Value value) {
        if (node == NULL) {
            size++;
            return new Node(key, value);
        }
        if (key == node->key)
            node->key = key;
        else if (key < node->key)
            node->left = Insert(node->left, key, value);
        else
            node->right = Insert(node->right, key, value);

        return node;
    }
    bool contain(Node* node, Key key) {
        if (node == NULL)
            return false;
        if (key == node->key)
            return true;
        else if (key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }
    Value* Search(Node* node, Key key) {
        if (node == NULL)
            return NULL;

        if (key == node->value)
            return node->value;
        else if (key < node->key)
            return Search(node->left, key);
        else
            return Search(node->right, key);
    }
    Node* removeMin(Node* node) {
        if (node->left == NULL) {
            Node* rightNode = node->right;
            delete node;
            size--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }
    Node* removeMax(Node* node) {
        if (node->right == NULL) {
            Node* leftNode = node->left;
            delete node;
            size--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }
    Node* Remove(Node* node, Key key) {
        if (node == NULL)
            return NULL;
        if (key < node->key) {
            node->left = Remove(node->left, key);
            return node;
        }
        else if (key > node->key) {
            node->right = Remove(node->right, key);
            return node;
        }
        else {//key==node->key
            if (node->left == NULL) {
                Node* rightNode = node->right;
                delete node;
                size--;
                return rightNode;
            }
            if (node->right == NULL) {
                Node* leftNode = node->left;
                delete node;
                size--;
                return leftNode;
            }
            Node* successor = new Node(minimum(node->right));
            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            return successor;
        }

    }
    void setvalue(Node* node,Key key, Value value) {
        if (node == NULL)
            return NULL;
        if (key == node->value)
            node->value = value;
    }
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
        Node(Node* node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node* root;
    int size;
};
template <class Key, class V>
class MapNode {
public:
    MapNode() {
        this->key = key;
        this->value = value;
        this->next = next;
    }
public:
    K key;
    V value;
    MapNode<K, V>* next;
    
};
template <class K, class V>
class Map {
public:
    virtual int getsize() = 0;
    virtual bool isEmpty() = 0;
    //增加操作
    virtual void add(K key, V value) = 0;
    //删除操作
    virtual V remove(K key) = 0;
    //修改操作
    virtual void set(K key, V value) = 0;
    //查找操作
    virtual bool contains(K key) = 0;
    virtual V get(K key) = 0;
};
template <class K, class V>
class LinkedListMap : public Map<K, V> {
public:
    LinkedListMap() {
        head->key = NULL;
        head->value = NULL;
        head->next = NULL;
        size = 0;
    }
    int getsize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
private:
    MapNode<K, V> head;
    int size;
void add(K key, V value) {
    MapNode<K, V>* pre = head;
    MapNode<K, V>* node = pre->next;
    while (node) {
        if (key != node->key) {
            MapNode<K, V>* p = new MapNode<K, V>(key, value, head->next);
            head->next = p;
            size++;
        }
    }
}
V remove(K key) {
     MapNode<K, V>* pre = head;
     MapNode<K, V>* node = pre->next;
     while (node) {
         if (key == node->key) {
              pre->next = node->next;
              V res = node->value;
              delete node;
              size--;
              return res;
         }
           pre = node;
           node = node->next;
     }
        cout << "映射中不包含" << key << '!' << endl;
        return NULL;
    }
void set(K key, V value) {
    MapNode<K, V>* node = head->next;
    while (node) {
    if (key == node->key) {
        node->value = value;
        return;
    }
    node = node->next;
    }
        cout << "映射中不包含" << key << '!' << endl;
    }
bool contains(K key) {
    MapNode<K, V>* node = head->next;
    while (node) {
        if (key == node->key) {
            return true;
        }
        node = node->next;
    }
    return false;
}
V get(K key) {
    MapNode<K, V>* node = head->next;
    while (node) {
        if (key == node->key) {
            return node->value;
        }
        node = node->next;
    }
    cout << "映射中不包含" << key << '!' << endl;
    return NULL;
}
};
int main() {
    BSTMap<int,char> bst;
    char value[] = { 'a','c','q','r','w','s','t'};
    for (int i = 0; i < 7; i++) {
        bst.Insert(i, value[i]);
    }
        bst.Search(5);
        bst.Remove(0);
        bst.setvalue(6, 'y');
        LinkedListMap<int, char>link;
        for (int i = 0; i < 7; i++) {
            link.add(i, value[i]);
        }
        link.remove(4);
        link.contains(2);
        link.set(3, 'l');
        link.get(5);
    return 0;
}


