#include<iostream>
#include<queue>
using namespace std;
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
	Node * root;    
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
			node->right=insert(root->rchild, val);
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
	Node* GetLeftMax(Node* root) {
		while (root != nullptr) {
			root = root->rchild;
		}
	}

	
	Node* GetRightMin(Node* root) {
		while (root != nullptr) {
			root = root->lchild;
		}
		return root;
	}

	// 二叉查找树的删除操作
	Node* Remove(Node* node, T val) {
		if (node == NULL)         
			return NULL; 
		if (val<node->val) { 
			node->left = Remove(node->left, val);
			return node;  
		}
		else if (val > node->val) { 
			node->right = Remove(node->right, val); 
			return node; 
		}   
		else {//key==node->key        
			if(node->left==NULL){
				Node *rightNode=node->right;
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
			Node *successor=new Node(minimum(node->right));  
				size++;         
				successor->right=removeMin(node->right);    
				successor->left=node->left;         
				
				delete node;        
				size--;       
				return successor;
		}  
	}
	Node* minimum(Node* node) {
		if (node->left == NULL)
			return node;
		return minimum(node->left);
	}
	Node* maximum(Node* node) {
		if (node->right == NULL)
			return node;
		return maximum(node->right);
	}
	Node* removeMin(Node* node) {
		if (node->left == NULL) {
			rightNode = node->right;
			delete node;
			size--;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
	}
	Node* removeMax(Node * node) {
		if (node->right == NULL) {
			leftNode = node->left;
			delete node;
			size--;
			return leftNode;
		}
		node->right = removeMax(node->right);
		return node;
	}
	void preOrder(Node * node) {
		if (node != NULL) {
			cout << node->data<< endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void inOrder(Node * node) {
		if (node != NULL) {
			inOrder(node->left);
			cout << node->data << endl;
			inOrder(node->right);
		}
	}
	void postOrder(Node * node) {
		if (node != NULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->data << endl;
		}
	}
	void levelOrder() {
		queue<Node *>q;
		q.push(root);
		while (!q.empty()) {
			Node* node = q.front();
			q.pop();

			cout << node->data << endl;
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
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
	void preOrder() {
		preOrder(root);
	}
	void inOrder() {
		inOrder(root);
	}
	void postOrder() {
		postOrder(root);
	}
	//寻找最小的值
	Node* minimum() {
		if (size != 0)
		Node* minNode = minimum(root);
		return minNode->data;
	}
	//寻找最大的值
	Node maximum() {
		if(size!=0)
		Node* maxNode = maximum(root);
		return maxNode->data;
	}

	//从二叉树中删除最小值所在的节点
	void removeMin() {
		if (root!=nullptr)
			root= removeMin(root);
	}
	//从二叉树中删除最大值所在的节点
	void removeMax() {
		if (root!=nullptr)
			root= removeMax(root);
	}

	//从二叉树中删除值为val的节点
	void Remove(T val) {
		root=Remove(root, val);
	}
};

	int main() {
		int arr[] = {7,3,8,5,6,2};
		BST<int> bst;
		int n = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < n; i++) {
			bst.insert(arr[i]);
		}
		bst.Remove(5);
		bst.search(7);
		bst.preOrder();
		bst.removeMax();
		bst.minimum();
		return 0;
	}
