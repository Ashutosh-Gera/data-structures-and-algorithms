#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray{
    int *data;
    int capacity;
    int nextIndex;
//using dynamic array
    public:

    StackUsingArray()
    {
        capacity = 5;
        data = new int[capacity];
        nextIndex = 0;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(int n){
        if (nextIndex == capacity){
            int* newData = new int[2*capacity];
            for (int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
            /*cout << "Stack full" << endl;
            return;*/
        }
        data[nextIndex] = n;
        nextIndex++;
    }

    int pop(){
        if (nextIndex <= 0){
            cout << "Stack Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if (nextIndex <= 0){
            cout << "Stack Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main(){
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.size() << endl;
    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.top() << "\n" << s.size() << endl;
}