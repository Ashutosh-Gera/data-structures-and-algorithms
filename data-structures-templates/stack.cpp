#include <iostream>
#include <stack>
#include "StackUsingArray.h"
#include "stackUsingLL.h"

int main(void) {
    
    stack<int> s;
    Stack<int> s2;
    StackUsingArray<int> s3;

    s.push(10);     
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    s2.push(10);
    s2.push(20);
    s2.push(30);
    s2.push(40);
    s2.push(50);
    s2.push(60);

    s3.push(10);
    s3.push(20);
    s3.push(30);
    s3.push(40);
    s3.push(50);
    s3.push(60);

    cout << s.top() << " " << s2.top() << " " << s3.top() << endl;
    s.pop(); s2.pop(); s3.pop();
    cout << s.top() << " " << s2.top() << " " << s3.top() << endl;
    cout << s.size() << " " << s2.size() << " " << s3.size() << endl;
    cout << s.empty() << " " << s2.empty() << " "<< s3.isEmpty() << endl;

    // everything working properly :D
    
}