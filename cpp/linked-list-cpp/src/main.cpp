#include <iostream>
using namespace std;
#include <string>
#include <limits>
#include<cstdlib>
#include <chrono>
#include <thread>
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define YELLO "\033[1;33m"
#define RESET   "\033[0m"
// structure declaration 
struct Node;

// function declaration
void createList(Node *&head);
void displayList(Node *head);
void insertAtBeginner(Node *&head);
void insertAtPosition(Node *&head);
void insertAtEnd(Node *&head);
void search(Node *head);
void sorting(Node*& head);
void reverseList(Node *&head);
void DeleteAtBeginning(Node *&head);
void DeleteAtEnd(Node*& head);
void DeleteViaValue(Node *&head);
void MenuUI();
void freeList(Node *&head);
void SinglyLinkedList();

struct Node
{
    int data;
    Node* next;
};

void createList(Node*& head)
{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65,' ') << MAGENTA << "CREATE LINKED LIST" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    
    int value;
    while(true)
    {                
        cout << "Enter the value for creating List(press -1 to stop) : ";
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Please enter an integer only 😑" << endl;
            continue;
        }                
        if(value == -1) return;

        Node* newNode = new Node{value,nullptr};
        if(head == nullptr)
        {
            head = newNode;
            continue;
        }
        Node* tail = head;
        while(tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void displayList(Node* head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "DISPLAY LINKED LIST" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    if(head == nullptr) 
    {
        cout << "List is Empty. Nothing for Traversing!🤗😞" << endl;
        return;
    }
    Node* temp = head;
    cout << YELLO << string(160, '-') << RESET << endl;
    cout << YELLO << "LIST :-  " << RESET;
    while(temp != nullptr){
        cout << RED << temp->data << RESET;
        if(temp->next != nullptr){
            cout << GREEN << " -> " << RESET;
        }
        temp = temp->next;
    }
    cout << endl;
    cout << YELLO << string(160,'-') << RESET << endl;
    cout << endl;
}
void insertAtBeginner(Node*& head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "INSERT ELEMENT AT BEGINNING" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    int value;
    while(true)
    {
        cout << "Enter the value for creating List(press -1 to stop) : ";
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Please enter an integer only 😑" << endl;
            continue;
        }
        if(value == -1) break;
        Node* newNode = new Node{value,head};
        head = newNode;
    }
}

void insertAtPosition(Node*& head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "INSERT ELEMENT VIA POSITION" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    while(true)
    {

        int position;
        int value;
        cout << "Enter the value (press -1 to stop) : ";
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Please enter an integer only 😑" << endl;
            continue;
        }
        if(value == -1)  break;

        cout << "Enter the position : ";
        cin >> position;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Please enter an integer only 😑" << endl;
            continue;
        }
        if(position < 1)
        {
            cout << "Invalid Position🤦! Enter Value and  positve Position /'again'/" << endl;
            continue;
        }


        
        Node* newNode = new Node{value,nullptr};
        // insert at head;
        if(position == 1)
        {
            newNode->next = head;
            head = newNode;
            continue;
        }
        // insert at Last;
        Node* lastNode = head;
        int count = 1;
        while(lastNode != nullptr && lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
            count++;
        }
        
        if(position == count+1) 
        {
            lastNode->next = newNode;
            continue;
        }
        // insert at middle
        Node* current = head;
        for(int i = 1; (i < position-1 && current != nullptr); i++)
        {
            current = current->next;
        }
        if(current ==nullptr)
        {
            cout << "Invalid Position🤦! Enter Value and  positve Position 'again'" << endl;
            continue;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
}
void insertAtEnd(Node*& head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "INSERT ELEMENT AT END" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    int value;
    while(true)
    {
        cout << "Enter the value (press -1 to stop) : ";
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Please enter an integer only 😑" << endl;
            continue;
        }
        if(value == -1) break;
        Node* newNode = new Node{value,nullptr};
        if(head == nullptr) 
        {
            head = newNode;
            continue;
        }
        Node* tail = head;
        while(tail->next != nullptr) 
            tail = tail->next;
        tail->next = newNode;        
    }
}

void search(Node* head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "SEARCH ELEMENT IN LIST" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    while(true)
    {
        int target, size = 0;

        bool flag = false;
        Node* temp = head;
        while(temp != nullptr)
        {
            size++;
            temp = temp->next;
        }

        cout << "Enter the Value for Searching in List(Press -1 to stop) : ";
        cin >> target;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Please enter an integer only 😑" << endl;
            continue;
        }
        if(target == -1) break;
        temp = head;
        int pos = 1;
        if(head == nullptr) 
        {
            cout << "List Is Empty can't be search, Please Enter Value First!" << endl;
            break;
        }
        int* arr = new int[size];       
        int index = 0;
        while(temp != nullptr)
        {
            if(temp->data == target)
            {
                arr[index] = pos;
                flag = true;
                index++;
            }
            temp = temp->next;
            pos++;
        }
        if(!flag)
            cout << "Value '" << target << "' is not found!" << endl;
        else
        {    
            cout <<"value '" << target << "' is found at position :-> " ;
            for(int i = 0; i < index; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        delete[] arr;
        arr = nullptr;
    }
}

void sorting(Node*& head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "SORTING LIST" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    if(head == nullptr || head->next == nullptr)
    {
        cout << "In the List less then 2 element, can't be sort!" << endl;
        return;
    }
    bool swapped;
    do 
    {
        swapped = false;
        Node* temp = head;
        while(temp->next != nullptr)
        {
            if(temp->data > temp->next->data)
            {
                int x = temp->data;
                temp->data = temp->next->data;
                temp->next->data = x;
                swapped = true;
            }
            temp = temp->next;
        }
    } while(swapped);
    cout << GREEN << "LIST SORTED SUCCESSFULLY🥰😘" << RESET << endl;
}
void reverseList(Node*& head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "REVERSE LIST" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    if(head == nullptr || head->next == nullptr)
    {
        cout << "In the List less then 2 element, can't be reverse!" << endl;
        return;
    }
    Node* currentNode = head;
    Node* previousNode = nullptr;
    Node* nextNode = nullptr;
    while(currentNode != nullptr)
    {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    head = previousNode;
    cout << GREEN << "LIST REVERSED SUCCESSFULLY🥰😘" << RESET << endl;

}

void DeleteAtBeginning(Node*& head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "DELETE ELEMENT AT BEGINNING" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    int value;
    if(head == nullptr)
    {
        cout << "List is Empty, Nothing for Delete🤗😘!" << endl;
        return;
    }

    while(true)
    {
        cout << "Press 1 to delete first element (Press -1 to stop): ";
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Enter integer only (1 or -1) 😑" << endl;
            continue;
        }
        if(value != -1 && value != 1)
        {
            cout << "Invalid input! Please enter 1 or -1 only 😑" << endl;
            continue;
        }
        if(value == -1) return;
        Node* temp = head;
        cout << "Beginning element (" << head->data << ") deleted successfully!" << endl;
        head = temp->next;
        delete temp;
        if(head == nullptr)
        {
            cout << "List is now empty 🤷‍♂️" << endl;
            return;
        }
    }
}

void DeleteAtEnd(Node*& head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "DELETE ELEMENT AT END" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;
    int value;
    if(head == nullptr)
    {
        cout << "List is Empty, Nothing for Delete🤗😘!" << endl;
        return;
    }

    while(true)
    {
        cout << "Press 1 to delete Last element (Press -1 to stop): ";
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Enter integer only (1 or -1) 😑" << endl;
            continue;
        }
        if(value != -1 && value != 1)
        {
            cout << "Invalid input! Please enter 1 or -1 only 😑" << endl;
            continue;
        }
        if(value == -1) return;
        if(head->next == nullptr)
        {   
            cout << "Last element (" << head->data << ") deleted successfully!" << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr)
            temp = temp->next;

        cout << "Last element (" << temp->next->data << ") deleted successfully!" << endl;
        Node* del = temp->next;
        temp->next = nullptr;
        delete del;
    }
}

void DeleteViaValue(Node*& head)

{
    cout <<CYAN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "DELETE ELEMENT VIA VALUE" << RESET << endl;
    cout <<CYAN << string(160, '=') << RESET << endl;

    int value;
    while(true)
    {
        if(head == nullptr)
        {
            cout << "List is Empty, Nothing for Delete🤗😘!" << endl;
            return;
        }

        cout << "Give the value for deleting element(Press -1 to stop): ";
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Enter integer only😑" << endl;
            continue;
        }

        if(value == -1) return;
        // case1: head node  
        if(head->data == value)
        {   
            Node* del = head;
            head = del->next;
            cout << "Element (" << del->data << ") deleted successfully!" << endl;
            delete del;
            continue;
         }
        // case2: middle/last node
        Node* previous = head;
        Node* current = head->next;
        while(current != nullptr && current->data != value)
        {
           previous = current;
           current = current->next;
        }
        if(current == nullptr)
        {
           cout << "Value (" << value  << ")is not found in List!" << endl;
           continue;    
        }
        cout << "Element (" << current->data << ") deleted successfully!" << endl;
        previous->next = current->next;
        delete current;
    }
}

void MenuUI()
{
    cout << CYAN << "1. Create List\n";
    cout << "2. Insert at Beginning\n";
    cout << "3. Insert at Position\n";
    cout << "4. Insert at End\n";
    cout << "5. Display List\n";
    cout << "6. Search\n";
    cout << "7. Sort\n";
    cout << "8. Reverse\n";
    cout << "9. Delete at Beginning\n";
    cout << "10. Delete by Value\n";
    cout << "11. Delete at End\n";
    cout << "12. Exit\n" << RESET;
}

void freeList(Node*& head)
{
    while(head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


void SinglyLinkedList()
{
    enum Menu
{
    CREATE = 1, INSERT_BEGIN, INSERT_POS, INSERT_END,
    DISPLAY, SEARCH, SORT, REVERSE,
    DELETE_BEGIN, DELETE_VALUE, DELETE_END, EXIT
};
    system("clear");
	cout << string(160, '.') << endl;
    cout << CYAN << "Loading Program...\n" << RESET;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));  // 3 seconds

    cout << GREEN <<  string(160, '=') << RESET << "\n" << endl;
    cout << string(65, ' ') <<MAGENTA<< "Welcome To Singly Linked List" << RESET << string(65,' ') << endl;
    cout <<"\n\033[1;32m" <<  string(160, '=') << "\033[0m\n" << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    Node* head = nullptr;
    int choice;

    while(true)
    {
        MenuUI();
        cout << "Enter your choice: ";
        cin >> choice;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Please enter Integer only 😑" << endl;
            continue;
        }
        switch(choice)
        {
            case CREATE: createList(head); break;
            case INSERT_BEGIN: insertAtBeginner(head); break;
            case INSERT_POS: insertAtPosition(head); break;
            case INSERT_END: insertAtEnd(head); break;
            case DISPLAY: displayList(head); break;
            case SEARCH: search(head); break;
            case SORT: sorting(head);break;
            case REVERSE: reverseList(head);break;
            case DELETE_BEGIN: DeleteAtBeginning(head); break;
            case DELETE_END: DeleteAtEnd(head); break;
            case DELETE_VALUE: DeleteViaValue(head); break;
            case EXIT: 
            {
                freeList(head);
                cout << GREEN << "PROGRAM FINISHED SUCCESSFULLY✅🙏😉" << RESET << endl;
                return;
            }
            default: cout << RED << "Invalid choice!" << RESET << endl;
        }
    }
}

int main(){
    SinglyLinkedList();
}

