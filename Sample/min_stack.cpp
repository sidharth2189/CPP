/*

MIN STACK

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

#include <iostream>
using namespace std; 

class Node {
    public:
    int data;
    Node* next;
    
    Node (int x)
    {
        this->data = x;
        next = NULL;
    }
};

class MinStack {
public:
    Node* top_node;
    /** initialize your data structure here. */
    MinStack(){
        top_node = NULL;
    }
    
    void push(int x) {
        Node* n = new Node(x);
        if (top_node == NULL) {top_node = n;}
        else
        {
            n->next = top_node;
            top_node = n;
        }
    }
    
    void pop() {
        if (top_node != NULL)
        {
            Node* temp = top_node;
            top_node = top_node->next;
            delete temp;
        }
    }
    
    int top() {
        if (top_node == NULL){return -1;}
        else {return top_node->data;}
    }
    
    int getMin() {
        int minimum = -1;
        if (top_node != NULL)
        {
            Node *min = top_node;
            int val;
            minimum = min->data;
            while (min != NULL)
            {
                val = min->data;
                if (minimum >= val) {minimum = val;}
                min = min->next;
            }
        }
        return minimum;
    }
};

int main()
{
    int display;
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);

    display = minStack->getMin();   // Returns -3.
    cout << "Min value:" << " ";
    cout << display << endl;

    minStack->pop();

    display = minStack->top();      // Returns 0.
    cout << "Top element:" << " ";
    cout << display << endl;

    display = minStack->getMin();   // Returns -2.
    cout << "Min value:" << " ";
    cout << display << endl;
}