#include "Stack.h"

Stack::Stack(int paramcap)
    :capacity(paramcap),n(0)
{
    martyr = new Martyr[capacity];
}
Stack::~Stack()
{
    if (martyr) delete[]martyr;
    martyr = NULL;
}
bool Stack::empty() { return n <= -1; }
void Stack::pop() {
    if (empty()) return;
    n--;
}
void Stack::push(const string& item) {
    if (n >= capacity) return;
    n++;
    martyr[n] = item;

}
Martyr Stack::top() {
    if (empty())
    {
        exit(1);
    }
    return martyr[n - 1];
}
bool Stack::traverse() {
    if (empty()) return false;
    Martyr* z = new Martyr[n];
    for (int i = 0; i < n; i++) {
        z[i] = martyr[n - i - 1];
    }
    for (int i = 0; i < n; i++) {
        martyr[i] = z[i];
    }
    delete[]z;
    return true;
}

bool Stack::findElement(const string& searchName) {
    for (int i = 0; i < n; ++i) {
        if (martyr[i].getName() == searchName) {
            return true;
        }
    }
    return false;
}
