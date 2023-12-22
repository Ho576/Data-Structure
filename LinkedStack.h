#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <iostream>
#include "Martyr.h"

using namespace std;
class LSNode {
public:
    Martyr data;
    LSNode* next;

    LSNode(const Martyr& item);
};

class LinkedStack {
private:
    LSNode* top;
    int n;

public:
    LinkedStack();
    LinkedStack(const LinkedStack&obj);
    ~LinkedStack();

    LinkedStack& operator=(const LinkedStack& obj);

    bool isEmpty() const;
    void push(const Martyr& item);
    void sortpush(const Martyr& item);
    void sort();
    void pop();
    Martyr topValue() const;
    void traverse() ;
    void displayStack() const;
    bool sUpdate(string theName, string newName);
    bool sUpdateLocation(string location);
    bool sDelete(string paramName);
    void sSwap(LinkedStack& other);

};
#endif // LINKEDSTACK_H
