#pragma once
#include "Martyr.h"
#include <iostream>
using namespace std;

class Stack {
private:
    Martyr* martyr;
    int n;
    int capacity;
public:
    Stack(int paramcap = 5);
    ~Stack();
    bool empty();
    void pop();
    void push(const string& item);
    Martyr top();
    bool traverse();
    bool findElement(const string& searchName);

};