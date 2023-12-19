#include <iostream>
using namespace std;


class BankData {
    public:
        int money;
        string name;

};

struct list {
    
    struct node* head;
    
};

struct node {

    BankData* data;
    struct node* next;
    
};

void generateMember(int moneyVal, string nameVal, struct list* theList) {
    
    //generates object pointer
    BankData* ptr = new BankData();
    
    if(ptr==NULL) {
        cout << "Bank member could not be created" << endl;
        return;
    }

    ptr->money = moneyVal;
    ptr->name = nameVal;
    
    struct node* newNode = new struct node;
    
    if(newNode==NULL) {
        delete ptr;
        cout << "Node member could not be created" << endl;
        return;
    }
    
    if(theList->head == NULL) {
        
        theList->head = newNode;
        newNode->data = ptr;
        newNode->next = NULL;
        cout << "Node member created!" << endl;
        return;
        
    }

    struct node* nodePtr = theList->head;
    
    while(nodePtr->next != NULL) {
        nodePtr = nodePtr->next;
    }
    
    //assigning new object to node 
    nodePtr->next = newNode;
    newNode->data = ptr;
    newNode->next = NULL;
    cout << "Node member created!" << endl;
    return;
}

void travelList(struct list* theList) {
    
    if(theList->head == NULL) {
        cout << "No ative members in this branch" << endl;
        return;
    }
    
    struct node* ptr = theList->head;
    
    while(ptr != NULL) {
        cout << ptr->data->name << endl;
        cout << ptr->data->money << endl;
        cout << "\n";
        ptr = ptr->next;
    }
    return;
}

int main() {

    //creating a list struct 
    struct list List;
    List.head = NULL;

    while(1) {
    
        int userInput;
        cout << "2 for looking at linked list, 1 for entering new member, 3 to quit";
        cin >> userInput; 
        
        if(userInput == 1) {
            int moneyValue;
            string nameValue;
            cout << "Enter user name: ";
            cin >> nameValue;
            cout << "Enter user money amount: ";
            cin >> moneyValue;
            generateMember(moneyValue, nameValue, &List);    
        }
        else if(userInput == 2) {
            travelList(&List);
        }
        else if(userInput == 3) {
            break;
        }
        else {
            continue;
        }

    }
    
    return 0;
    
}
