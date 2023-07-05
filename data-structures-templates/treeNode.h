#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
    public:

    T data;
    vector<TreeNode<T>*> children; // ismei <T> agar na bhi likhe toh compiler will assume that

    //constructor
    TreeNode(T data) {
        this -> data = data;
    }

    //destructor
    ~TreeNode() {
        for (int i = 0; i < (int) this->children.size(); ++i) {
            delete this->children[i];
        }
    }

    int height(TreeNode<T>* root) {
        if (root == NULL) return 0;

        int ans = 1;
        int add = 0;

        for (int i = 0; i < (int) root->children.size(); ++i) {
            add = max(add, height(root->children[i]));
        }
        ans += add;
        return ans;
    }

    int height() {
        return height(this);
    }
    
    int numNodes(TreeNode<T>* root) {
        if (root == NULL) return 0;

        int ans = 1;

        for (int i = 0; i < (int) root->children.size(); ++i) {
            ans += numNodes(root->children[i]);
        }
        return ans;
    }

    int numNodes() {
        return numNodes(this);
    }

    int numLeafNodes(TreeNode<T>* root) {
        if (root == NULL) return 0;

        if ((int) root -> children.size() == 0) return 1;

        int ans = 0;
        for (int i = 0; i < (int) root->children.size(); ++i) {
            ans += numLeafNodes(root->children[i]);
        }
        return ans;
    }

    int numLeafNodes() {
        return numLeafNodes(this);
    }

    void preOrder(TreeNode<T>* root) {
        if (root == NULL) return;

        cout << root -> data << " ";
        for (int i = 0; i < (int) root->children.size(); ++i) {
            preOrder(root -> children[i]);
        }
    }

    void preOrder() {
        return preOrder(this);
    }

    void postOrder(TreeNode<T>* root) {
        if (root == NULL) return;

        for (int i = 0; i < (int) root->children.size(); ++i) {
            postOrder(root -> children[i]);
        }
        cout << root -> data << " ";
    }

    void postOrder() {
        return postOrder(this);
    }
};