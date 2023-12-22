// Data Structure mini project 2

#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include "DoublyCircularLinkedList.h"
#include "MyVector.h"
#include "LinkedStack.h"

using namespace std;

void mainFunctions();

int main()
{
	mainFunctions();
}



void displayMenu(DoublyCircularLinkedList& data);

void mainFunctions() {


    //opin file
    ifstream inputFile("btselem.csv");
    // Check if the file is open 
    if (!inputFile.is_open()) {
        cout << "Unable to open the file." << endl;
    }
    //read data from file
    DoublyCircularLinkedList myData;
    string line;
    getline(inputFile, line);
    //add data to DCLL
    while (getline(inputFile, line)) {
        istringstream param(line);
        string name, age, eventLocation, dateOfDeath, gender;
        if (getline(param, name, ',') &&
            getline(param, age, ',') &&
            getline(param, eventLocation, ',') &&
            getline(param, dateOfDeath, ',') &&
            getline(param, gender, ',')) {
            Martyr martyr(name, age, eventLocation, dateOfDeath, gender);
            myData.updateNodedata(martyr);
        }
        else {
            cout << "Error parsing line: " << line << endl;
        }
    }

    //sort the data
    myData.sortListByName();

    //display the menu
     displayMenu(myData);

    // Close the file
    inputFile.close();
   
}


void handleLocationMenu(DoublyCircularLinkedList& data);
void searchForALocationRecord(Node*& SelectedLocation);
void handleStatisticsReport(Node*& SelectedLocation);
void handleMartyrsMenu(Node*& SelectedLocation);
void saveChangesToFile(DoublyCircularLinkedList& data);



void displayMenu(DoublyCircularLinkedList& data) {

        handleLocationMenu(data);
        saveChangesToFile(data);
        cout << "Thank you for use our program" << endl;
}

void handleLocationMenu(DoublyCircularLinkedList& data) {
    int option;
    do {
        cout << "Location Menu:" << endl;
        cout << "1. Insert new location record" << endl;
        cout << "2. Update an existing location" << endl;
        cout << "3. Delete an existing location" << endl;
        cout << "4. Search for a location record" << endl;
        cout << "5. exit " << endl;

        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1: 
        {
            string Location;
            cout << "Enter a new Location name : ";
            cin.ignore();
            getline(cin, Location);
            if (data.findNode(Location))
            {
                cout << "The Location is already exist" << endl;
            }
            else {
                
                data.insertAtBeginning(Location);
            }
            
                break;
        }
        case 2:
        {
            string Location;
            cout << "Enter the Location name : " ;
            cin.ignore();
            getline(cin, Location);
            if (!data.findNode(Location))
            {
                cout << "Dose not found the Location" << endl;
            }
            else {
                string Location2;
                cout << "Enter a new Location name : " << endl;
                cin.ignore();
                getline(cin, Location2);

                data.updateNode(Location,Location2);
            }

            break;
        }
        case 3:
        {
            string Location;
            cout << "Enter the Location name : " ;
            cin.ignore();
            getline(cin, Location);
            if (!data.findNode(Location))
            {
                cout << "Dose not found the Location" << endl;
            }
            else {

                data.deleteNode(Location);
            }

            break;
        }
        case 4:
        {
            string Location;
            cout << "Enter the Location name : ";
            cin.ignore();
            getline(cin, Location);
            if (!data.findNode(Location))
            {
                cout << "Dose not found the Location" << endl;
            }
            else {
                Node* SelectedLocation = data.findNode(Location);
                searchForALocationRecord(SelectedLocation);
            }
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (option != 5);
}
void searchForALocationRecord(Node* & SelectedLocation) {
    char option;

    cout << "a.Martyrs Menu" << endl;
    cout << "b.Statistics Report" << endl;


    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
    case 'a':
        handleMartyrsMenu(SelectedLocation);
        break;

    case 'b':
        handleStatisticsReport(SelectedLocation);
        break;
    default:
        cout << "Invalid option. Please try again." << endl;
        break;
    }
}
void handleMartyrsMenu(Node*& SelectedLocation) {
    int option;

    cout << "Martyrs Menu :" << endl;
    cout << "1. Insert a new martyr record" << endl;
    cout << "2. Update a martyr record" << endl;
    cout << "3. Delete a martyr record" << endl;
    cout << "4. Search for a martyr by name and display information" << endl;

    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
    case 1: 
    {
        string name, age, dateOfDeath, gender;
        cout << "Enter The Name" << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter The Name" << endl;
        cin.ignore();
        getline(cin, age);
        cout << "Enter The Name" << endl;
        cin.ignore();
        getline(cin, dateOfDeath);
        cout << "Enter The Name" << endl;
        cin.ignore();
        getline(cin, gender);
        cout << "Enter The Name" << endl;
        cin.ignore();
        getline(cin, name);

        SelectedLocation->addNew(name, age, dateOfDeath, gender);

        break;
    }
    case 2:
    {
        string name1,name2;
        cout << "Enter The Name" << endl;
        cin.ignore();
        getline(cin, name1);
        cout << "Enter The new Name" << endl;
        cin.ignore();
        getline(cin, name2);
        if (SelectedLocation->update(name1, name2))
            cout << "Name updated" << endl;
        else cout << "Name not found" << endl;


        break;
    }
    case 3:
    {
        string name;
        cout << "Enter The Name" << endl;
        cin.ignore();
        getline(cin, name);
        if (SelectedLocation->deletee(name))
            cout << "Name deleted" << endl;
        else cout << "Name not found" << endl;


        break;
    }
    case 4:
    {
        Martyr martyr(SelectedLocation->get());
        cout << "Name: " << martyr.getName()
            << ", Age: " << martyr.getAge()
            << ", Location: " << martyr.getLocation()
            << ", Date of Death: " << martyr.getDateOfDeath()
            << ", Gender: " << martyr.getGender() << endl;
        break;
    }
        
    default:
        cout << "Invalid option. Please try again." << endl;
        break;
    }
}
void handleStatisticsReport(Node*& SelectedLocation) {
    char option;

    cout << "Statistics Report:" << endl;
    cout << "a. Number of martyrs in the selected location" << endl;
    cout << "b. Print Martyrs' full information in that location" << endl;
    cout << "c. Traverse the stack and print Martyrs' full information" << endl;
    cout << "d. Report the date with the minimum number of martyrs" << endl;

    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
    case 'a':
    {
        SelectedLocation->numberofMartyrs();
        break;
    }
    case 'b':
    {
        SelectedLocation->display();
        break;
    }
        
    case 'c':
    {
        SelectedLocation->displayTravers();
        break;
    }
    case 'd':
    {
        cout << 'd' << endl;
        break;
    }
    default:
        cout << "Invalid option. Please try again." << endl;
        break;
    }
}

void saveChangesToFile(DoublyCircularLinkedList & data) {
    char option;
    do {
        cout << "Do you want to save the changes to the file?" << endl;
        cout << "a. Yes" << endl;
        cout << "b. No" << endl;


        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 'a': {
            ofstream outputFile("output.txt");
            data.display(outputFile);
            outputFile.close();
            return;
        }

        case 'b':
            cout << "Exit the program without changing the file" << endl;
            return;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (option != 'a' && option != 'b');
}



