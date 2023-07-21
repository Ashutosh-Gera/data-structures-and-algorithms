#include <iostream>
#include <queue>
#include <algorithm>
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

//O(n)
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


// Given the pre order and inorder traversal of a tree, construct the unique binary tree
BinaryTreeNode<int>* treeConstruct(vector<int>& preOrderVec, vector<int>& inOrderVec, int preStart, int preEnd, int inStart, int inEnd) {
    
    if (preEnd < preStart) return NULL;
    if (inEnd < inStart) return NULL;
    
    int rootData = preOrderVec[preStart]; //first elem of preOrder is the root
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    int leftPreStart = preStart + 1;
    int leftInStart = inStart;
    int rootIdx = -1;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inOrderVec[i] == rootData) {
            rootIdx = i;
            break;
        }
    }
    int leftInEnd = rootIdx - 1;
    int leftPreEnd = leftPreStart + leftInEnd - leftInStart; // leftPreEnd - leftPreStart = leftInEnd - leftInStart

    int rightPreStart = leftPreEnd + 1;
    int rightPreEnd = preEnd;

    int rightInStart = rootIdx + 1;
    int rightInEnd = inEnd;

    root->left = treeConstruct(preOrderVec, inOrderVec, leftPreStart, leftPreEnd, leftInStart, leftInEnd);
    root->right = treeConstruct(preOrderVec, inOrderVec, rightPreStart, rightPreEnd, rightInStart, rightInEnd);
    return root;
} //ok tested

//Given the postOrder & inOrder traversal, construct the binary tree
BinaryTreeNode<int>* buildTree(vector<int>& postOrderVec, vector<int>& inOrderVec, int postStart, int postEnd, int inStart, int inEnd) {
    if (postEnd < postStart) return NULL;
    if (inEnd < inStart) return NULL;
    
    int rootData = postOrderVec[postEnd]; //last elem of postOrder is the root
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    int leftPostStart = postStart;
    int leftInStart = inStart;
    int rootIdx = -1;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inOrderVec[i] == rootData) {
            rootIdx = i;
            break;
        }
    }
    int leftInEnd = rootIdx - 1;
    int leftPostEnd = leftPostStart + leftInEnd - leftInStart; // leftPostEnd - leftPostStart = leftInEnd - leftInStart

    int rightPostEnd = postEnd - 1;
    int rightPostStart = leftPostEnd + 1;

    int rightInStart = rootIdx + 1;
    int rightInEnd = inEnd;


    root->left = buildTree(postOrderVec, inOrderVec, leftPostStart, leftPostEnd, leftInStart, leftInEnd);
    root->right = buildTree(postOrderVec, inOrderVec, rightPostStart, rightPostEnd, rightInStart, rightInEnd);
    return root;
} //ok tested

//this has time complexity O(n*h) h-> height of tree; n-> num of nodes of tree
int diameter(BinaryTreeNode<int>* root) {
    if (root == NULL) return 0;

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right); //doing redundant work!!!!

    return max({option1, option2, option3});
}


//Better diameter function ; works in O(n)
pair<int,int> heightDiameter(BinaryTreeNode<int>* root) {
    if (root == NULL) return {0,0};

    //first = height ; second = diameter
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);

    pair<int,int> ans;
    ans.first = 1 + max(leftAns.first, rightAns.first);
    ans.second = max({leftAns.first + rightAns.first, leftAns.second, rightAns.second});
    return ans;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main() {

    // int n;

    // cin >> n;
    // vector<int> postOrderVec(n);
    // vector<int> inOrderVec(n);
    // for (int i = 0; i < n; ++i) {
    //     cin >> postOrderVec[i];
    // }
    // for (int i = 0; i < n; ++i) {
    //     cin >> inOrderVec[i];
    // }

    // BinaryTreeNode<int>* root = buildTree(postOrderVec, inOrderVec, 0, n-1, 0, n-1);
    BinaryTreeNode<int>* root = takeInputLevelWise();
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    // root -> left = node1;
    // root -> right = node2;

    printTreeLevelWise(root);
    cout << numNodes(root) << endl;
    cout << height(root) << endl;
    cout << diameter(root) << endl;
    cout << heightDiameter(root).first << " " << heightDiameter(root).second << endl;
    // preOrder(root); cout << endl;
    // inOrder(root); cout << endl;
    // postOrder(root); cout << endl;

    delete root;
}
