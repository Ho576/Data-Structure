#include "MyVector.h"
using namespace std;


MyVector::MyVector(int cap) : capacity(cap), n(0) {
    martyr = new Martyr[capacity];
}

MyVector::MyVector(const MyVector& obj) : capacity(obj.capacity), n(obj.n) {
martyr = new Martyr[capacity];
    for (int i = 0; i < n; i++)
        martyr[i] = obj.martyr[i];
}

MyVector::~MyVector() {
    if (martyr != NULL)
        delete[] martyr;
    martyr = NULL;
}

MyVector & MyVector :: operator=(const MyVector& obj) {
    if (this != &obj) {
        if (martyr != NULL) {
            delete[] martyr;
            martyr = NULL;
        }

        capacity = obj.capacity;
        n = obj.n;
        martyr = new Martyr[capacity];
        for (int i = 0; i < n; i++)
            martyr[i] = obj.martyr[i];
    }
    return *this;
}



void MyVector::resize() {
    capacity *= 2;
    Martyr* b = new Martyr[capacity];
    for (int i = 0; i < n; i++)
        b[i] = martyr[i];
    delete[] martyr;
    martyr = b;
    b = NULL;
}


void MyVector::add(Martyr obj) {
    if (n >= capacity)
        resize();
    martyr[n++] = obj;
    
}

int MyVector::find(string name) {
    int i;
    for (i = 0; i < n; ++i) {
        if (martyr[i].getName() == name)
            return i;
    }
    return -1;
}

Martyr& MyVector::get(int index) {
    if (index >= 0 && index < n)
        return martyr[index];
    exit(1);
}


void MyVector::removeAll() {
    n = 0;
}


void MyVector::clear() {
    removeAll();
}

bool MyVector::remove(int index) {
    if (index < 0 || index >= n)
        return false;
    for (int i = index; i < n - 1; i++)
        martyr[i] = martyr[i + 1];
    n--;
    return true;
}


Martyr MyVector::operator[](int i) {
    return martyr[i];
}


bool MyVector::empty() {
    return n <= 0;
}
int MyVector::size() const {
    return n;
}
//void MyVector::sort() {
//
//}

bool MyVector::vUpdate(string theName, string newName) {
    if (empty())
    {
        return 0;
    }
    int index = find(theName);
    if (index == -1)
    {
        return 0;
    }
    get(index).setName(newName);
    return 1;
}
bool MyVector::vUpdateLocation(string location) {
    if (empty())
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        martyr[i].setLocation(location);
    }
    return 1;
}
bool MyVector::vDelete(string paramName) {
    if (empty())
    {
        return 0;
    }
    int index = find(paramName);
    if (index == -1)
    {
        return 0;
    }
    remove(index);
    return 1;
}

void MyVector :: sort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (martyr[j] > martyr[j + 1]) {
                Martyr temp = martyr[j];
                martyr[j] = martyr[j + 1];
                martyr[j + 1] = temp;
            }
        }
    }
}
void MyVector::vSwap(MyVector& other) {
    swap(capacity, other.capacity);
    swap(n, other.n);
    swap(martyr, other.martyr);
}








Martyr MyVector::back() {
    if (empty()) {
        exit(1);
    }
    return martyr[n - 1];
}
void MyVector::pushBack(Martyr x) {
    add(x);
}
void MyVector::popBack() {
    if (empty()) {
        exit(1);
    }
    remove(n - 1);
}




//a= martyer
//Martyr* MyVector::begin() {
//    return a;
//}
//
//
//Martyr* MyVector::end() {
//    return a + n;
//}
//
//
//const Martyr* MyVector::begin() const {
//    return a;
//}
//
//
//const Martyr* MyVector::end() const {
//    return a + n;
//}

//bool MyVector::operator==(const MyVector& v1) {
//    if (size() == v1.size()) {
//        for (int i = 0; i < v1.size(); i++) {
//            if (a[i] != v1.a[i])
//                return false;
//        }
//        return true;
//    }
//    return false;
//}
//MyVector MyVector::operator*(const MyVector& obj) {
//    MyVector result(n < obj.n ? obj.n : n);
//    for (int i = 0; i < n && i < obj.n; i++) {
//        result.add(a[i] * obj.a[i]);
//    }
//    for (int i = n; i < obj.n; i++) {
//        result.add(obj.a[i]);
//    }
//    for (int i = obj.n; i < n; i++) {
//        result.add(a[i]);
//    }
//    return result;
//}
//MyVector MyVector::operator+(const MyVector& obj) {
//    MyVector result(n + obj.n);
//    int i;
//    for (i = 0; i < n; i++)
//        result.add(a[i]);
//    for (int j = 0; j < obj.n; j++)
//        result.add(obj.a[j]);
//    return result;
//}
