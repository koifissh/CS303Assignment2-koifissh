#include <iostream>
#include "linkedlist.h"
#include <iostream>
#include "Professional.h"
#include "NonProfessional.h"
#include "Employee.h"
#include <string>

using namespace std;

int main() {

    LinkedList<string> list;
    int inputIndex;
    string inputUser;
    string inputString;
    string itemInput;

    int age;
    double salary;
    string name = "";
    string professionInput;
    int hours;

    while(inputUser != "Q") {
        cout << endl;
        cout << "Select a number to perform the corresponding function" << endl;
        cout << "1. Push_front" << endl
            << "2. Push_back" << endl
            << "3. Pop_front" << endl
            << "4. Pop_back" << endl
            << "5. Peek Front item" << endl
            << "6. Peek Back item" << endl
            << "7. Check if Empty" << endl
            << "8. Remove an index" << endl
            << "9. Find an item" << endl
            << "0. Insert an item" << endl
        << "Z. Create An Employee" << endl;
        cout << "Enter an input: ";
        cin >> inputUser;
        
       switch(toupper(inputUser[0])) {
        case '1':
            list.push_front();
            list.display();
            break;

        case '2':
            list.push_back();
            list.display();
            break;

        case '3':
            list.pop_front();
            list.display();
            break;

        case '4':
            list.pop_back();
            list.display();
            break;

        case '5':
            cout << list.front() << endl;
            break;

        case '6':
            cout << list.back() << endl;
            break;

        case '7':
            cout << "Is list empty?: " << list.empty() << endl;
            break;

        case '8':
            cout << "Enter an index you wish to remove: ";
            cin >> inputIndex;
            if (cin.fail()) {
                cout << "There was an error in the input" << endl;
                cin.clear();
                cin.ignore();
                break;
            }             
            cout << list.remove(inputIndex) << endl;
            list.display();
            break;

        case '9':
            cout << "What item are you searching for? ";
            cout << list.find(list.ask()) << endl;
            list.display();
            break;

        case '0':
            cout << "Enter an index you wish to add at: ";
            cin >> inputIndex;
            if (cin.fail()) {
                cout << "There was an error in the input" << endl;
                cin.clear();
                cin.ignore();
                break;
            }
            list.insert(inputUser, inputIndex);
            list.display();
            break;
        case 'Z':
            
            cout << "What is the name of the employee: ";
            cin.ignore();
            getline(cin, name);
            
            
            cout << "What is the age of the employee: " << endl;
            cin >> age;
            if (cin.fail()) {
                cout << "There was an error in the input" << endl;
                cin.clear();
                cin.ignore();
                break;
            }
             

            cout << "Is the employee professional or non-professional? P or N" << endl;
            cin >> professionInput;
           
            if (professionInput[0] == 'P') {
                cout << "What is the monthly salary: " << endl;
                cin >> salary;

                Professional PEmployee(name, age, salary);
                PEmployee.print();
            }
            if (professionInput[0] == 'N') {
                cout << "What is the hourly rate: " << endl;
                cin >> salary;
                cout << "How many hours worked a week: " << endl;
                cin >> hours;
                Nonprofessional NEmployee(name, age, salary, hours);
                NEmployee.print();
            }
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
}