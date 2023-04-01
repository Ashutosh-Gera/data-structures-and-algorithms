#include <iostream>
using namespace std;
#include <assert.h>

class Node{
    public:

    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};


void print(Node* head){
    Node* tmp = head;

    while (tmp != NULL){
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

//Function to take Input as a linked list; it keeps creating a linked list and extending it until a -1 is achieved!
// Not good because time complexity is O(n^2)
Node* takeInput(){
    
    int data;
    cin >> data;
    Node* head = NULL;

    while (data != -1){
        Node* newNode = new Node(data);

        if (head == NULL){
            head = newNode;
        }
        else{
            Node* tmp = head;
            while (tmp -> next != NULL){
                tmp = tmp -> next;
            }
            tmp -> next = newNode;
        }

        cin >> data;
    }
    return head;
}


//taking input in O(n) , BETTER!!!
Node* takeInput2(){
    
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;

    while (data != -1){
        Node* newNode = new Node(data);

        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }

        cin >> data;
    }
    return head;
}


//function to insert a node at ith position
Node* insertNode(Node* head, int i, int data){
    Node* newNode = new Node(data);
    int pos = 0;
    Node* tmp = head;
    if (i == 0){
        newNode -> next = head;
        return newNode;
    }
    while (tmp != NULL && pos < i - 1){
        pos++;
        tmp = tmp -> next;
    }
    if (tmp != NULL){
        newNode -> next = tmp -> next;
        tmp -> next = newNode;
    }
    return head;
}


Node* deleteNode(Node* head, int pos)
{
    if (pos == 0)
    {
        Node* tmp = head;
        head = head -> next;
        delete tmp;
        return head;
    }

    int count = 0;
    Node* tmp = head;
    while (tmp -> next != NULL && count < pos - 1)
    {
        count++;
        tmp = tmp -> next;
    }
    if (tmp -> next != NULL)
    {
        Node* tmp2 = tmp -> next;
        tmp -> next = tmp2 -> next;
        delete tmp2;
    }
    return head;
}


Node* insertNodeRec(Node *head, int i, int data) {
	// Write your code here
   
    if (i == 0)
    {
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return head;
    }

    if (head == NULL) return head;  

    Node* ans = insertNode(head->next, i-1, data);
    
    head -> next = ans;
    return head;
}


Node *deleteNodeRec(Node *head, int pos) 
{
	//Write your code here
    if (head == NULL) return head;
    
    if (pos == 0)
    {
        Node* tmp = head;
        delete tmp;
        return head -> next;
    }
    
    head -> next = deleteNodeRec(head -> next, pos - 1);
    
    return head;
}

//reversal of LL but O(n^2)
Node* revLL(Node* head)
{
    if (head == NULL) return head;
    
    if (head -> next == NULL) return head;
    
    Node* ans = revLL(head -> next);
    
    Node* tmp = ans;
    
    while (tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }
    tmp -> next = head;
    head -> next = NULL;
    return ans;
}

//Better reversal but it uses extra space; iterative
Node* createReverse(Node* head)
{
    if (head == NULL || head -> next == NULL) return head;
    
    Node* currentNode = head;
    Node* prevNode = NULL;
    Node* newNode;
    
    while (currentNode != NULL)
    {
        newNode = new Node(currentNode -> data);
        newNode -> next = prevNode;
        prevNode = newNode;
        currentNode = currentNode -> next;
    }
    return newNode;
}


int len(Node* head)
{
    if (head == NULL) return 0;
    
    return 1 + len(head -> next);
}

//returns mid node of a singly ll
Node *midPoint2(Node *head)
{
    // Write your code here
    int length = len(head);
    Node* tmp = head;
    int midIdx = 0;
    while (tmp != NULL && midIdx < (length / 2) - 1)
    {
        tmp = tmp -> next;
        midIdx++;
    }
    if (length % 2 == 0) return tmp;
    else
    {
        if (tmp -> next == NULL) return tmp;
        return tmp -> next;
    }
}

//mid-point of ll without using len
Node *midPoint(Node *head)
{
    // Write your code here
    if (head == NULL || head -> next == NULL) return head;
    
    Node* slow = head;
    Node* fast = head -> next;
    
    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

//merging two sorted linked lists in O(n) space
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    //Initially doing it in O(n) space
    Node* head = NULL;
    Node* tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head == NULL)
        {
            if (head1 -> data <= head2 -> data)
            {
                Node* newNode = new Node(head1 -> data);
                head = newNode;
                tail = newNode;
                head1 = head1 -> next;
            }
            else
            {
                Node* newNode = new Node(head2 -> data);
                head = newNode;
                tail = newNode;
                head2 = head2 -> next;
            }
        }
        else
        {
            if (head1 -> data <= head2 -> data)
            {
                Node* newNode = new Node(head1 -> data);
                tail -> next = newNode;
                tail = tail -> next;
                head1 = head1 -> next;
            }
            else
            {
				Node* newNode = new Node(head2 -> data);
                tail -> next = newNode;
                tail = tail -> next;
                head2 = head2 -> next;
            }
        }
    }
    while (head1 != NULL)
    {
        if (head == NULL)
        {
            Node* newNode = new Node(head1 -> data);
            head = newNode;
            tail = newNode;
            head1 = head1 -> next;
        }
        else
        {
            Node* newNode = new Node(head1 -> data);
            tail -> next = newNode;
            tail = tail -> next;
            head1 = head1 -> next;
        }
    }
    while (head2 != NULL)
    {
        if (head == NULL)
        {
            Node* newNode = new Node(head2 -> data);
            head = newNode;
            tail = newNode;
            head2 = head2 -> next;
        }
        else
        {
            Node* newNode = new Node(head2 -> data);
            tail -> next = newNode;
            tail = tail -> next;
            head2 = head2 -> next;
        }
    }
    return head;
}

//merge in O(1) space
Node *merge(Node *head1, Node *head2)
{
    //Write your code here
    Node* head = NULL;
    Node* tail = NULL;
    
    while (head1 != NULL && head2 != NULL)
    {
        if (head == NULL)
        {
            if (head1 -> data <= head2 -> data)
            {
                head = head1;
                tail = head1;
                head1 = head1 -> next;
            }
            else
            {
                head = head2;
                tail = head2;
                head2 = head2 -> next;
            }
        }
        else
        {
            if (head1 -> data <= head2 -> data)
            {
                tail -> next = head1;
                tail = tail -> next;
                head1 = head1 -> next;
            }
            else
            {
                tail -> next = head2;
                tail = tail -> next;
                head2 = head2 -> next;
            }
        }
    }
    while (head1 != NULL)
    {
        if (head == NULL)
        {
            head = head1;
            tail = head1;
            head1 = head1 -> next;
        }
        else
        {
            tail -> next = head1;
            tail = tail -> next;
            head1 = head1 -> next;
        }
    }
    while (head2 != NULL)
    {
        if (head == NULL)
        {
            head = head2;
            tail = head2;
            head1 = head2 -> next;
        }
        else
        {
            tail -> next = head2;
            tail = tail -> next;
            head2 = head2 -> next;
        }
    }
    return head;
}

//mergesort a linked list
Node *mergeSort(Node *head)
{
	//Write your code here
    if (head == NULL || head -> next == NULL) return head;
    
    Node* mid = midPoint(head);
    Node* mid2 = mid -> next;
    
    mid -> next = NULL;
    Node* ans1 = mergeSort(head);
    Node* ans2 = mergeSort(mid2);
    return merge(ans1,ans2);
}


//to reverse a linked list recursively in O(n)
class Pair
{
  public:
    Node* head;
    Node* tail;
};

Pair revll(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    
    Pair smallAns = revll(head -> next);
    
    smallAns.tail -> next = head;
    head -> next = NULL;
    
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    return revll(head).head;
}

//Function to reverse a linked List in O(n) without OOPS
Node* reverseBest(Node* head)
{
    if (head == NULL || head -> next == NULL) return head;

    Node* smallAns = reverseBest(head -> next);
    Node* tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    return smallAns;
}

//Iterative reversal without extra space in O(n)
Node* revBest(Node* head)
{
    Node* prev = NULL;
    Node* cur = head;

    while (cur != NULL)
    {
        Node* nex = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = nex;
    }
    return prev;
}


int main(void)
{
    Node* head = takeInput2();
    //int i,data,pos;
    //cin >> i >> data;
    //head = insertNodeRec(head, i, data);
    //cin >> pos;
    //head = deleteNode(head,pos);
    head = revBest(head);
    print(head);
}
