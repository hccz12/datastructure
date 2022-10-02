#include <iostream>
using namespace std;

template <typename T>
struct AVLTreeNode
{
    T key;                  
    int height;             
    AVLTreeNode* leftChild; 
    AVLTreeNode* rightNode; 
    AVLTreeNode(T value, AVLTreeNode* l, AVLTreeNode* r) : key(value), height(0), leftChild(l), rightNode(r) {}
};

template <typename T>
class AVLTree
{
public:
    AVLTree() : root(NULL) {}
    ~AVLTree() {};

public:
    void inOrder() { inOrder(root); }
    int height() { return height(root); }
    AVLTreeNode<T>* search(T key) { return search(root, key); }
    T minimum()
    {
        AVLTreeNode<T>* p = minimum(m_root);
        if (p != NULL)
            return p->m_key;
        return (T)NULL;
    }
    T maximum()
    {
        AVLTreeNode<T>* p = maximum(m_root);
        if (p != NULL)
            return p->m_key;
        return (T)NULL;
    }
    void insert(T key) { insert(root, key); }
    void remove(T key)
    {
        AVLTreeNode<T>* z = search(root, key);
        if (z != NULL)
            m_root = remove(root, z);
    }

private:
    void inOrder(AVLTreeNode<T>* node)
    {
        if (node == NULL)
            return;
        inOrder(node->leftChild);
        cout << node->key << " ";
        inOrder(node->rightNode);
    }
    int height(AVLTreeNode<T>* node)
    {
        return node != NULL ? node->height : 0;
    }

    AVLTreeNode<T>* search(AVLTreeNode<T>* node, T key)
    {
        if (node == NULL || node->key == key)
            return node;
        if (key < node->key)
            return search(node->leftChild, key);
        else
            return search(node->rightNode, key);
    }
    AVLTreeNode<T>* minimum(AVLTreeNode<T>* node)
    {
        if (node == NULL)
            return NULL;
        while (node->leftChild != NULL)
        {
            node = node->leftChild;
        }
        return node;
    }

    AVLTreeNode<T>* maximum(AVLTreeNode<T>* node)
    {
        if (node == NULL)
            return NULL;
        while (node->rightNode != NULL)
        {
            node = node->rightNode;
        }
        return node;
    }

    AVLTreeNode<T>* insert(AVLTreeNode<T>*& node, T key)
    {
        if (node == NULL)
        {
            node = new AVLTreeNode<T>(key, NULL, NULL);
        }
        else if (key < node->key) 
        {
            node->m_leftChild = insert(node->leftChild, key);
            if (height(node->leftChild) - height(node->rightNode) == 2)
            {
                if (key < node->leftChild->key)
                    node = leftLeftRotation(node);
                else
                    node = leftRightRotation(node);
            }
        }
        else if (key > node->key) 
        {
            node->m_rightNode = insert(node->rightNode, key);
            if (height(node->rightNode) - height(node->leftChild) == 2)
            {
                if (key > node->rightNode->key)
                    node = rightRightRotation(node);
                else
                    node = rightLeftRotation(node);
            }
        }
        else
        {
            cout << "添加失败，不能添加相同的结点" << endl;
        }
        node->height = max(height(node->leftChild), height(node->rightNode)) + 1;
        return node;
    }

    AVLTreeNode<T>* remove(AVLTreeNode<T>*& node, AVLTreeNode<T>* z)
    {
        if (node == NULL || z == NULL)
            return NULL;

        if (z->key < node->key) 
        {
            node->meftChild = remove(node->leftChild, z);
            if (height(node->rightNode) - height(node->meftChild) == 2)
            {
                AVLTreeNode<T>* r = node->rightNode;
                if (height(r->leftChild) > height(r->rightNode))
                    node = rightLeftRotation(node);
                else
                    node = rightRightRotation(node);
            }
        }
        else if (z->key > node->key) 
        {
            node->rightNode = remove(node->rightNode, z);
            if (height(node->leftChild) - height(node->rightNode) == 2)
            {
                AVLTreeNode<T>* l = node->leftChild;
                if (height(l->rightNode) > height(l->leftChild))
                    node = leftRightRotation(node);
                else
                    node = leftLeftRotation(node);
            }
        }
        else 
        {
            if ((node->leftChild != NULL) && (node->rightNode != NULL))
            {
                if (height(node->leftChild) > height(node->rightNode))
                {
                    if (height(node->leftChild) > height(node->rightNode))
                    {
                        AVLTreeNode<T>* max = maximum(node->leftChild);
                        node->key = max->key;
                        node->leftChild = remove(node->leftChild, max);
                    }
                    else
                    {
                        AVLTreeNode<T>* min = minimum(node->rightNode);
                        node->key = min->key;
                        node->rightNode = remove(node->rightNode, min);
                    }
                }
            }
            else
            {
                AVLTreeNode<T>* tmp = node;
                node = node->leftChild != NULL ? node->leftChild : node->rightNode;
                delete tmp;
            }
        }
        return node;
    }

private:
    AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>*& k2)
    {
        AVLTreeNode<T>* k1 = k2->leftChild;
        k2->m_leftChild = k1->rightNode;
        k1->rightNode = k2;
        k2->height = max(height(k2->leftChild), height(k2->rightNode)) + 1;
        k1->height = max(height(k1->leftChild), k2->height) + 1;
        return k1;
    }
    AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>*& k1)
    {
        AVLTreeNode<T>* k2 = k1->rightNode;
        k1->rightNode = k2->leftChild;
        k2->leftChild = k1;

        k1->height =max(height(k1-lef>tChild), height(k1->rightNode)) + 1;
        k2->height =max(height(k2->rightNode), k1->height) + 1;
        return k2;
    }
    AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>*& k3)
    {
        k3->leftChild = rightRightRotation(k3->leftChild);
        return leftLeftRotation(k3);
    }

    AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>*& k1)
    {
        k1->rightNode = leftLeftRotation(k1->rightNode);
        return rightRightRotation(k1);
    }

private:
    AVLTreeNode<T>* root; 
};

int main()
{
    AVLTree<int> tree;
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    tree.insert(16);
    tree.insert(15);
    tree.insert(14);
    tree.insert(13);
    tree.insert(12);
    tree.insert(11);
    tree.insert(10);
    tree.insert(8);
    tree.insert(9);
    tree.inOrder();
    cout << endl;
    tree.remove(8);

    return 0;
}
