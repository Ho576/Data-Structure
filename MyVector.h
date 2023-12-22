// MyVector.h
#pragma once
#include <iostream>
#include "Martyr.h"

class MyVector {
private:
    Martyr* martyr;
    int capacity;
    int n;
    void resize();

public:
    MyVector(int cap = 5);
    MyVector(const MyVector& obj);
    ~MyVector();
    MyVector& operator=(const MyVector& obj);

    void add(Martyr obj);
    int find(string name);
    Martyr& get(int index);
    bool remove(int index);
    void removeAll();
    void clear();

    Martyr operator[](int i);
    bool empty();
    int size() const;
    Martyr back();


    void sort();
    void vSwap( MyVector& other);
    bool vUpdate(string theName, string newName);
    bool vUpdateLocation(string location);
    bool vDelete(string paramName);

    void pushBack(Martyr x);
    void popBack();

    //MyVector operator+(const MyVector& obj);
    //bool operator==(const MyVector& v1);
    //MyVector operator*(const MyVector& obj);
    //Martyr* begin();
    //Martyr* end();
    //const Martyr* begin() const;
    //const Martyr* end() const;
};
