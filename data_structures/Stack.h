#ifndef STACK_H
#define STACK_H

#include <iostream>

#define NULL_VALUE -99999

template <class T>
class Stack
{
public:
    Stack (int);   // create a stack with given capacity
    ~Stack();
    void push(T);  // push at the end
    void pop();    // pop from the end
    T peek();      // return the last item
    int size() { return top+1; }

private:
    T * arr;
    int capacity;
    int top;
};

template <class T>
Stack<T>::Stack(int capacity) {
    this->capacity = capacity;
    top = -1;
    arr = new T[capacity];
}

template <class T>
Stack<T>::~Stack() {
    if (arr) delete[] arr;
    arr = NULL;
}

template <class T>
void Stack<T>::push(T value) {
    if (size() >= capacity) {
        std::cout << "Stack is full." << std::endl;
        return ;
    }

    top++;
    arr[top] = value;
}

template <class T>
void Stack<T>::pop() {
    if (size() <= 0) {
        std::cout << "Stack is empty." << std::endl;
        return ;
    }
    top--;
}

template <class T>
T Stack<T>::peek() {
    if (size() <= 0)
        return NULL_VALUE;
    return arr[top];
}

#endif  // STACK_H
