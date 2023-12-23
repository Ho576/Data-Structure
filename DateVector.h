// DateVector.h

#include <iostream>
#include "Martyr.h"
class Date {
public:
    string name;
    int count;
    
};



class dateVector {
private:
    Date* martyrs;
    int Dcapacity;
    int n;
    void resize();

public:
    dateVector(int cap = 5);
    ~dateVector();

    void add(string name);
    int find(string name);
    string& get(int index);

    bool empty();
    int size() const;

    string getMinCountDate() const;


};



