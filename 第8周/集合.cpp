//链表实现集合
#include <iostream>
using namespace std;
typedef struct Vnode {
    int data;
    Vnode* next;
}*Node;

class Link {
private:
    Node  head;
    int size;

public:
    Link();
    ~Link();
    void Insert(int data);
    void Delete(int data);
    int GetElement(int num);
    bool ExistElement(int e);
    bool IsEmpty();
    void Print();
    
};

Link::Link() {
    head = NULL;
    this->size = 0;
}
void Link::Insert(int data) {
    Node n = new Vnode;
    Node p = head;

    n->data = data;
    if (p == NULL) {
        head = n;
        n->next = NULL;
        size++;
        return;
    }
    if (data < p->data) {
        n->next = head;
        head = n;
        size++;
        return;
    }
    else while (p->next != NULL) {
        if (data > p->next->data)
            p = p->next;
        else if (data == p->next->data) {
            delete n;
            return;
        }
        else if (data < p->next->data) {
            n->next = p->next;
            p->next = n;
            size++;
            return;
        }
    }

    p->next = n;
    n->next = NULL;
    size++;
    return;
}

void Link::Delete(int data) {
    Node p = head;
    Node n;
    if (p->data == data) {
       head = head->next;
        delete p;
    }
    else while (p->next != NULL) {
        if (data == p->next->data) {
            n = p->next;
            p->next = n->next;
            delete n;
            size--;
            return;
        }
    }
    return nullptr;
}

int Link::GetElement(int num) {
    Node n = head;
    int p = 1;
    while (n != NULL) {
        if (p != e) {
            n = n->next;
            p++;
        }
        else if (p == e) {
            return n->data;
        }
    }
    return NULL;
}

bool Link::ExistElement(int e) {
    Node n = head;
    while (n != NULL) {
        if (n->data == e) {
            return true;
        }
        else {
            n = n->next;
        }
    }
    return false;
}

bool Link::IsEmpty() {
    if (size == 0 && this->head == NULL)
        return true;
    else return false;
}

void Link::Print() {
    Node n = this->head;
    cout << "{";
    if (n != NULL) {
        cout << n->data;
        n = n->next;
    }
    else {
        cout << "}" << endl;
        return;
    }

    while (n != NULL) {
        cout << "," << n->data;
        n = n->next;
    }
    cout << "}" << endl;
    return;
}
Link::~Link() {
    Node n =head;
    while (head != NULL) {
        head ->next;
        delete n;
        n = head;
    }
}
//二分搜索树实现集合
template <class T>
class BST {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(T data) {
			this->data = data;
			this->left = this->right = NULL;
		}
	}
	Node* root;   
	int size;     
	Node* insert(Node* root, T val) {
		if (root == nullptr) {
			root = newNode(val);
			size++;
		}

		if (root->data == val) {
			return; 
		}
		else if (root->data > val) {
			node->left = insert(root->lchild, val);
		}
		else {
			node->right = insert(root->rchild, val);
		}
		return root;
	}
	bool search(Node* root, T val) {
		if (root == nullptr)
			return false;
		if (root->data == val)
			return true;
		else if (root->data > val) {
			search(root->lchild, val);
		}
		else {
			search(root->rchild, val);
		}
	}
	Node* Remove(Node* node, T val) {
		if (node == NULL)
			return NULL;
		if (val < node->val) {
			node->left = Remove(node->left, val);
			return node;
		}
		else if (val > node->val) {
			node->right = Remove(node->right, val);
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
			//node->left!=NULL && node->right!=NULL;    
			Node* successor = new Node(minimum(node->right));
			size++;
			successor->right = removeMin(node->right);
			successor->left = node->left;

			delete node;
			size--;
			return successor;
		}
	}
	
public:
	BST() {
		root = NULL;
		size = 0;
	}
	~BST() {};
	int getsize() {
		return size;
	}
	bool isEmpty() {
		return count == 0;
	}
	void insert(T val) {
		insert(root, val);
	}
    T search(T val) {
        return search(root, val);
    }
	void Remove(T val) {
		root = Remove(root, val);
	}
};

template <class T>
class Set {
public:
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    //增加操作
    virtual void add(T num) = 0;
    //删除操作
    virtual void remove(T num) = 0;
    //查找操作
    virtual bool contains(T num) = 0;
};
template <class T>
class BSTSet : public Set<T> {
private:
    BST<T> bst;
public:
    //增加操作
void add(T num) {
     bst.add(num);
 }
    //删除操作
 void remove(T num) {
     bst.remove(num);

 }
 bool contains(T num) {
     return bst.contains(num);
 }
 int getsize() {
     return bst.size();
 }
 bool isEmpty() {
     return bst.isEmpty();
 }
};



int main() {
    int k;
    Link c;
    while (cin >> k) {
        while (k--) {
            cin >> k;
            c.Insert(k);
        } 
    }
        c.Print();
        c.Insert(3);
        c.Insert(98);
        c.ExistElement(23);
        c.GetElement(2);
       
   
}
