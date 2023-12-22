#include "LinkedStack.h"
using namespace std;
//LinkedStackNode
LSNode::LSNode(const Martyr& item) 
	: data(item), next(NULL) {}


//LinkedStack
LinkedStack::LinkedStack() : top(NULL),n(0) {}
LinkedStack::LinkedStack(const LinkedStack& obj) : top(obj.top), n(obj.n){}

LinkedStack& LinkedStack:: operator=(const LinkedStack& obj)
{
    top = obj.top;
    n = obj.n;

    return *this;

}

LinkedStack::~LinkedStack() {
    while (!isEmpty()) {
        pop();
    }
}

bool LinkedStack::isEmpty() const {
    return top == NULL;
}

void LinkedStack::sortpush(const Martyr& item) {
    LSNode* newNode = new LSNode(item);

    // If the stack is empty or the new node's date is earlier than the top node's date
    if (isEmpty() || item.getDateOfDeath() <= top->data.getDateOfDeath()) {
        newNode->next = top;
        top = newNode;
        n++;
    }
    else {
        LSNode* current = top;
        LSNode* prev = nullptr;

        // Traverse the stack to find the correct position for the new node
        while (current != nullptr && item.getDateOfDeath() > current->data.getDateOfDeath()) {
            prev = current;
            current = current->next;
        }

        // Insert the new node in its correct position
        prev->next = newNode;
        newNode->next = current;
        n++;
    }
}
void LinkedStack::push(const Martyr& item) {
    LSNode* newNode = new LSNode(item);
    newNode->next = top;
    top = newNode;
    n++;
}


void LinkedStack::pop() {
    if (!isEmpty()) {
        LSNode* temp = top;
        top = top->next;
        delete temp;
        n--;
    }
}

Martyr LinkedStack::topValue() const {
    if (!isEmpty()) {
        return top->data;
    }
    // Handle the case when the stack is empty (throw an exception or handle it in another way)
    // For simplicity, we'll return a default-constructed Martyr here.
    return Martyr();
}

void LinkedStack::traverse()  {
    if (isEmpty()) {
        return;
    }

    LinkedStack current;

    while (top)
    {
        current.push(topValue());
        pop();
    }
    current.displayStack();
    while (current.top)
    {
        push(current.topValue());
        current.pop();
    }
    cout << endl;
}

void LinkedStack::displayStack() const {
    LSNode* current = top;

    while (current != nullptr) {
        cout << "Name: " << current->data.getName()
            << ", Age: " << current->data.getAge()
            << ", Location: " << current->data.getLocation()
            << ", Date of Death: " << current->data.getDateOfDeath()
            << ", Gender: " << current->data.getGender() << endl;

        current = current->next;
    }

    cout << endl;
}
void LinkedStack::sort() {
    if (isEmpty()) {
        return;
    }

    LinkedStack* current= new LinkedStack;
    while (top)
    {
        (* current).push(topValue());
        pop();
    }
    *this = *current;
    current = NULL;

}
bool LinkedStack::sUpdate(string theName, string newName) {
    bool x = 0;
    if (isEmpty()) {
        return false;
    }

    LinkedStack current;

    while (top)
    {
        if (top->data.getName() == theName) {
            x = 1;
            top->data.setName(newName);
        }
        else {
            current.push(topValue());
            pop();
        }
    }
    while (current.top)
    {
        push(current.topValue());
        current.pop();
    }
    return x;
}

bool LinkedStack::sUpdateLocation(string location) {
    bool x = 0;
    if (isEmpty()) {
        return false;
    }

    LinkedStack current;

    while (top)
    {
            top->data.setLocation(location);
            current.push(topValue());
            pop();
    }
    while (current.top)
    {
        push(current.topValue());
        current.pop();
    }
    return x;
}
bool LinkedStack::sDelete(string paramName) {
    bool x = 0;
    if (isEmpty()) {
        return false;
    }

    LinkedStack current;

    while (top)
    {
        if (top->data.getName() == paramName) {
            x = 1;
            pop();
        }
        else {
            current.push(topValue());
            pop();
        }
    }
    while (current.top)
    {
        push(current.topValue());
        current.pop();
    }
    return x;
}
void LinkedStack::sSwap(LinkedStack& other) {
   swap(top, other.top);
   swap(n, other.n);
}

