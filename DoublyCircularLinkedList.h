#include "MyVector.h"
#include "LinkedStack.h"
class Node {
public:
    string Location;
    MyVector dataSortName;
    LinkedStack dataSortDate;
    Node* next;
    Node* prev;

    Node(string paramLocation="");
    Node(Martyr paramMartyr , string paramLocation = "");
    ~Node();

    void addNew(string Name = "", string Age = "", string DateOfDeth = "", string gender = "");
    bool update(string theName = "",string newName = "");
    bool deletee(string Name = "");
    Martyr& get(string Name = "");

    int numberofMartyrs() { return dataSortName.size(); }
    void display();
    void displayTravers() { dataSortDate.sort(); dataSortDate.traverse(); }

    string dateWithMinMartyrs();


};

class DoublyCircularLinkedList {
private:
    Node* head;
    int n;
public:
    DoublyCircularLinkedList();
    ~DoublyCircularLinkedList();

    int size()const;
    bool empty()const;
    void insertAtBeginning(Martyr& paramMartyr, string paramLocation);
    void insertAtBeginning(string paramLocation);
    void insertAtEnd(Martyr& paramMartyr, string paramLocation);
    void deleteNode(string LocName);
    void display(ofstream& file);
    void removeAll();

    Node* findNode(string LocName);
    bool updateNode(string oldLocName, string newLocName);
    void updateNodedata(Martyr& paramMartyr);

    void sortListByName();
       
};


