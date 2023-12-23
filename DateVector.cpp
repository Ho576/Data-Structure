#include "DateVector.h"
using namespace std;


dateVector::dateVector(int cap) : Dcapacity(cap), n(0) {
    martyrs = new Date[Dcapacity];
}

dateVector::~dateVector() {
    if (martyrs != NULL)
        delete[] martyrs;
    martyrs = NULL;
}
void dateVector::resize() {
    Dcapacity *= 2;
    Date* b = new Date[Dcapacity];
    for (int i = 0; i < n; i++)
        b[i] = martyrs[i];
    delete[] martyrs;
    martyrs = b;
    b = NULL;
}


void dateVector::add(string name) {

    int index = find(name);
    if (index == -1)
    {
        if (n >= Dcapacity)
            resize();
        martyrs[n].name = name;
        martyrs[n++].count = 1;
        return;
    }
    martyrs[index].count++;

}

int dateVector::find(string name) {
    int i;
    for (i = 0; i < n; ++i) {
        if (martyrs[i].name== name)
            return i;
    }
    return -1;
}

string& dateVector::get(int index) {
    if (index >= 0 && index < n)
        return martyrs[index].name;
    exit(1);
}



bool dateVector::empty() {
    return n <= 0;
}
int dateVector::size() const {
    return n;
}

string dateVector::getMinCountDate() const {
    if (n == 0) {
       
        return "";
    }

    int minCount = martyrs[0].count;
    int minIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (martyrs[i].count < minCount) {
            minCount = martyrs[i].count;
            minIndex = i;
        }
    }

    return martyrs[minIndex].name;
}