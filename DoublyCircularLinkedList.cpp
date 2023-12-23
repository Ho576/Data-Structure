#include "DoublyCircularLinkedList.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include<string>
#include <fstream>

#include "DateVector.h"

using namespace std;

// Function to convert a string to lowercase
void toLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return tolower(c); });
}



//display
void displayData(MyVector& obj);
void displayDataOnFile(MyVector& obj,ofstream& file);



//Node
Node::Node(string paramLocation)
{
    dataSortDate = LinkedStack();
    dataSortName=MyVector();
    Location = paramLocation;
}
Node::Node(Martyr paramMartyr, string paramLocation)
{
    dataSortDate.push(paramMartyr);
    dataSortName.add(paramMartyr);
    Location = paramLocation;
}
Node::~Node() {}

void Node::addNew(string Name , string Age , string DateOfDeth , string gender )
{
    dataSortDate.push(Martyr(Name, Age, Location, DateOfDeth, gender));
    dataSortName.add(Martyr(Name, Age, Location, DateOfDeth, gender));
    dataSortName.sort();
}

bool Node::update(string theName, string newName) {
    if (!dataSortDate.sUpdate(theName, newName))return 0;
    dataSortName.vUpdate(theName, newName);
    return 1;
}
bool Node::deletee(string Name) {
    if (!dataSortDate.sDelete(Name)) return 0;
    
    dataSortName.vDelete(Name);
    return 1;
}
Martyr& Node::get(string Name) {
    return  dataSortName.get(dataSortName.find(Name));
}
void Node::display() {
    displayData(dataSortName);
}



//DCLL

DoublyCircularLinkedList::DoublyCircularLinkedList() {
    head = NULL;
    n = 0;
}

DoublyCircularLinkedList::~DoublyCircularLinkedList() {
    removeAll();
}

int DoublyCircularLinkedList::size()const { return n; }
bool DoublyCircularLinkedList::empty()const { return n <= 0; }

void DoublyCircularLinkedList::removeAll()
{
    while (head) {
        Node* temp = head->next;
        delete head;
        head = temp;
        if (head != NULL) {
            if(head->prev) head->prev = NULL;
        }
    }
}

void DoublyCircularLinkedList::insertAtBeginning(Martyr& paramMartyr, string paramLocation) {
    Node* newNode = new Node(paramMartyr, paramLocation);
    if (head == nullptr) {
        head = newNode;
        head->next = head->prev = head;
    }
    else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}
void DoublyCircularLinkedList::insertAtBeginning(string paramLocation) {
    Node* newNode = new Node(paramLocation);
    if (head == nullptr) {
        head = newNode;
        head->next = head->prev = head;
    }
    else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyCircularLinkedList::insertAtEnd(Martyr& paramMartyr, string paramLocation) {
    Node* newNode = new Node(paramMartyr, paramLocation);
    if (head == NULL) {
        head = newNode;
        head->next = head->prev = head;
    }
    else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

void DoublyCircularLinkedList::deleteNode(string LocName) {
    if (head == NULL) {
        exit(1);
    }

    Node* current = head;
    do {
        if (current->Location == LocName) {
            if (current == head) {
                head = head->next;
            }
            current->dataSortDate.~LinkedStack();
            current->dataSortName.~MyVector();
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return;
        }

        current = current->next;
    } while (current != head);
}

void DoublyCircularLinkedList::display(ofstream & file) {
    if (head == NULL) {
        file << "List is empty.\n";
        return;
    }

    Node* current = head;
    do {
        file << current->Location;
        file << endl;
        displayDataOnFile(current->dataSortName,file);
        file << endl;
        current = current->next;
    } while (current != head);
    file << endl;
}

Node* DoublyCircularLinkedList::findNode(string LocName) {
    if (head == NULL) {
        return NULL;
    }

    Node* current = head;
    do {
        if (current->Location == LocName) {
            return current;
        }

        current = current->next;
    } while (current != head);

    return NULL; // Location not found
}

bool DoublyCircularLinkedList::updateNode(string oldLocName, string newLocName) {
    Node* nodeToUpdate = findNode(oldLocName);

    if (nodeToUpdate == NULL) {
        return false; // Node not found
    }
    nodeToUpdate->Location = newLocName;
    nodeToUpdate->dataSortDate.sUpdateLocation(newLocName);
    nodeToUpdate->dataSortName.vUpdateLocation(newLocName);

    return true; // Node updated successfully
}

void DoublyCircularLinkedList::updateNodedata(Martyr& paramMartyr) {

    Node* nodeToUpdate = findNode(paramMartyr.getLocation());
    if (nodeToUpdate == NULL) {
        insertAtBeginning(paramMartyr, paramMartyr.getLocation());
    }
    else {
        nodeToUpdate->dataSortDate.push(paramMartyr);
        nodeToUpdate->dataSortName.add(paramMartyr);
    }
}

void DoublyCircularLinkedList::sortListByName() {
    if (head == NULL || head->next == head) {
        return; // Nothing to sort
    }

    Node* current = head;

    //sort the data
    do {
       // current->dataSortDate.sort();
        current->dataSortName.sort();
    } while (current != head);
    do {
        Node* minNode = current;
        Node* temp = current->next;
        do {
            string currentLocationLower = minNode->Location;
            string tempLocationLower = temp->Location;
            toLowerCase(currentLocationLower);
            toLowerCase(tempLocationLower);
            if (tempLocationLower < currentLocationLower) {
                minNode = temp;
            }
            temp = temp->next;
        } while (temp != head);

        // Swap data between current and minNode
        swap(current->Location, minNode->Location);
        current->dataSortName.vSwap(minNode->dataSortName);
        current->dataSortDate.sSwap(minNode->dataSortDate);

        current = current->next;
    } while (current->next != head);
}
void displayData(MyVector& obj)
{
    if (obj.size() <= 0) {
        cout << "No data" << endl;
    }
    for (int i = 0; i < obj.size(); i++)
    {
        cout << "Name: " << obj[i].getName()
            << ", Age: " << obj[i].getAge()
            << ", Location: " << obj[i].getLocation()
            << ", Date of Death: " << obj[i].getDateOfDeath()
            << ", Gender: " << obj[i].getGender() << endl;
    }

}
void displayDataOnFile(MyVector& obj,ofstream& file) {
    if (obj.size() <= 0) {
        file << "No data" << endl;
    }
    for (int i = 0; i < obj.size(); i++)
    {
        file << "Name: " << obj[i].getName()
            << ", Age: " << obj[i].getAge()
            << ", Location: " << obj[i].getLocation()
            << ", Date of Death: " << obj[i].getDateOfDeath()
            << ", Gender: " << obj[i].getGender() << endl;
    }
}





string Node::dateWithMinMartyrs() {

    dateVector min;
    for (int i = 0; i < dataSortName.size(); i++)
    {
        min.add(dataSortName[i].getDateOfDeath());
    }
    string minDate= min.getMinCountDate();
    min.~dateVector();
    return minDate;

}