#include <iostream>
#include <queue>
#include "treeNode.h"

using namespace std;


//BETTER
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the number of children of " << front -> data << endl;
        int numChild;
        cin >> numChild;

        for (int i = 1; i <= numChild; ++i) {
            int childData;
            cout << "Enter " << i << "th child of " << front -> data << endl;
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData); //cannot do static allocation, why?
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


TreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        TreeNode<int>* child = takeInput();
        root -> children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root) {
    if (root == NULL) return; //edge case

    cout << root -> data << ": ";
    for (int i = 0; i < (int) root -> children.size(); ++i) {
        cout << root -> children[i] -> data << ", ";
    }
    cout << endl;
    for (int i = 0; i < (int) root->children.size(); ++i) {
        printTree(root -> children[i]);
    }
}

void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << front -> data << ": ";
        for (int i = 0; i < (int) front->children.size(); ++i) {
            cout << front->children[i]->data << ", ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

int numNodes(TreeNode<int>* root) {
    if (root == NULL) return 0;

    int ans = 1;

    for (int i = 0; i < (int) root->children.size(); ++i) {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int height(TreeNode<int>* root) {
    if (root == NULL) return 0;

    int ans = 1;
    int add = 0;

    for (int i = 0; i < (int) root->children.size(); ++i) {
        add = max(add, height(root->children[i]));
    }
    ans += add;
    return ans;
}

void printAtLevelK(TreeNode<int>* root, int k) {
    if (root == NULL) return;

    if (k == 0) {
        cout << root -> data << endl;
        return;
    }

    for (int i = 0; i < (int) root->children.size() ; ++i) {
        printAtLevelK(root->children[i], k - 1);
    }
}

int numLeafNodes(TreeNode<int>* root) {
    if (root == NULL) return 0;

    if ((int) root -> children.size() == 0) return 1;

    int ans = 0;
    for (int i = 0; i < (int) root->children.size(); ++i) {
        ans += numLeafNodes(root->children[i]);
    }
    return ans;
}

void preOrder(TreeNode<int>* root) {
    if (root == NULL) return;

    cout << root -> data << " ";
    for (int i = 0; i < (int) root->children.size(); ++i) {
        preOrder(root -> children[i]);
    }
}

void postOrder(TreeNode<int>* root) {
    if (root == NULL) return;

    for (int i = 0; i < (int) root->children.size(); ++i) {
        postOrder(root -> children[i]);
    }
    cout << root -> data << " ";
}

//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);

    // root -> children.push_back(node1);
    // root -> children.push_back(node2);
    TreeNode<int>* root = takeInputLevelWise();

    printLevelWise(root);
    cout << numNodes(root) << " " << root->numNodes() << endl;
    cout << height(root) << " " << root->height() << endl;
    printAtLevelK(root, 1);
    cout << numLeafNodes(root) << " " << root->numLeafNodes() << endl;
    preOrder(root); cout << endl; root->preOrder();
    cout << endl;
    postOrder(root); cout << endl; root->postOrder();

    delete root;
}