#include <iostream>
#include <climits>
using namespace std;


template <typename T>
class StackUsingArray{
    T *data; //array
    int capacity;
    int nextIndex;
//using dynamic array
    public:

    StackUsingArray()
    {
        capacity = 5;
        data = new T[capacity];
        nextIndex = 0;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(T n){
        if (nextIndex == capacity){
            T* newData = new T[2*capacity];
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

    T pop(){
        if (nextIndex <= 0){
            cout << "Stack Empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top(){
        if (nextIndex <= 0){
            cout << "Stack Empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};
