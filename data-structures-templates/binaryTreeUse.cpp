#include <iostream>
#include <queue>
#include "binaryTreeNode.h"

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter data:" << endl;
    cin >> rootData;
    
    if (rootData == -1) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;
    
    return root;
}

//BETTER
BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter data:" << endl;
    cin >> rootData;

    if (rootData == -1) return NULL; //only for convention


    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front -> data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout << "Enter right child of " << front -> data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printTreeLevelWise(BinaryTreeNode<int>* root) {
    if (root == NULL) return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << front -> data << ":";
        if (front -> left != NULL) {
            cout << "L" << front->left->data << ", ";
            pendingNodes.push(front->left);
        }
        if (front -> right != NULL) {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

void printTree(BinaryTreeNode<int>* root) {
    if (root == NULL) return;

    cout << root -> data << ":";
    if (root -> left != NULL) {
        cout << "L" << root->left->data;
    }
    if (root -> right != NULL) {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

int numNodes(BinaryTreeNode<int>* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 1;

    return 1 + numNodes(root->left) + numNodes(root->right);
}

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) return 0;

    if (root -> left == NULL && root->right == NULL) return 1;

    return 1 + max(height(root->left), height(root->right));
}

//root->left->right
void preOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root->right);
}

//left->root->right
void inOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//left->right->root
void postOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;

    postOrder(root -> left);
    postOrder(root->right);
    cout << root -> data << " ";
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main() {

    BinaryTreeNode<int>* root = takeInputLevelWise();
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    // root -> left = node1;
    // root -> right = node2;

    printTreeLevelWise(root);
    cout << numNodes(root) << endl;
    cout << height(root) << endl;
    preOrder(root); cout << endl;
    inOrder(root); cout << endl;
    postOrder(root); cout << endl;

    delete root;
}
