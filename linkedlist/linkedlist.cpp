#include <iostream>
#include<string>
using namespace std;

class Node {
public:
  int redid;
  string name;
  Node *next;  //This variable is a pointer to another Node object, representing the next node in the linked list. This pointer is used to create a chain of linked nodes that can be traversed in sequence.

  Node(int redid, string name) {
    this->redid = redid;
    this->name= name;
    next = nullptr;
  }
};


class LinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  ~LinkedList() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  LinkedList(int redid = 0, string name = "") {
    if (redid != 0 && !name.empty()) {
        Node *newNode = new Node(redid, name);
        head = newNode;
        tail = newNode;
        length = 1;
    } else {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
}

  void printList() {
    Node *temp = head;
    if(temp== nullptr){
       cout<<endl<<"List is Empty!!!"<<endl;
    }
    while (temp != nullptr) {
      cout << temp->redid << " :  "<<temp->name<< endl;
      temp = temp->next;
    }
  }

  void getHead() {
    if (head == nullptr) {
      cout << "Head: nullptr" << endl;
    } else {
      cout << "Head: " << head->redid << " :  "<<head->name<< endl;
    }
  }

  void getTail() {
    if (tail == nullptr) {
      cout << "Tail: nullptr" << endl;
    } else {
      cout << "Tail: " << tail->redid << " :  "<<tail->name<< endl;
    }
  }

  int getLength() { 
    return length;
    }

  void append(int redid, string name) {
    Node *newNode = new Node(redid, name);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    length++;
  }

  void deleteLast() {
    if (length == 0)
      return;
    Node *temp = head;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      Node *pre = head;
      while (temp->next) {
        pre = temp;
        temp = temp->next;
      }
      tail = pre;
      tail->next = nullptr;
    }
    delete temp;
    length--;
  }

  void prepend(int redid, string name) {
    Node *newNode = new Node(redid, name);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
    length++;
  }

  void deleteFirst() {
    if (length == 0)
      return;
    Node *temp = head;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
    }
    delete temp;
    length--;
  }

  Node *get(int index) {
    if (index < 0 || index >= length)
      return nullptr;
    Node *temp = head;
    for (int i = 0; i < index; ++i) {
      temp = temp->next;
    }
    return temp;
  }

  bool set(int index, int redid, string name) {
    Node *temp = get(index);
    if (temp) {
      temp->redid = redid;
      temp->name = name;
      return true;
    }
    return false;
  }

  bool insert(int index, int redid, string name) {
    if (index < 0 || index > length)
      return false;
    if (index == 0) {
      prepend(redid, name);
      return true;
    }
    if (index == length) {
      append(redid, name);
      return true;
    }
    Node *newNode = new Node(redid, name);
    Node *temp = get(index - 1);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
  }

  void deleteNode(int index) {
    if (index < 0 || index >= length){
      cout<<endl<<"Index Not Found!!!"<<endl<<endl;
      return;
      }
    if (index == 0){
      cout<<endl<<"Record Deleted SUccessfully!!!"<<endl<<endl;
      return deleteFirst();}
    if (index == length - 1){
      cout<<endl<<"Record Deleted SUccessfully!!!"<<endl<<endl;
      return deleteLast();}

    Node *prev = get(index - 1);
    Node *temp = prev->next;

    prev->next = temp->next;
    delete temp;
    length--;
  }

void sortByName() {
    Node* current = head;
    Node* min;
    Node* temp;

    while (current != NULL) {
        min = current;

        // Find the minimum node in the remaining unsorted list
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (temp->name < min->name) {
                min = temp;
            }
        }

        // Swap the current node with the minimum node
        if (current != min) {
            swap(current->name, min->name);
            swap(current->redid, min->redid);
        }

        current = current->next;
    }
    cout<<endl<<"Data Sorted Successfully!!!"<<endl<<endl;
}


  void sortByREDID()
{
    Node* temp = head;
  
    // Traverse the List
    while (temp) {
        Node* min = temp;
        Node* r = temp->next;
  
        // Traverse the unsorted sublist
        while (r) {
            if (min->redid > r->redid)
                min = r;
            r = r->next;
        }
  
        // Swap Data
        string x = temp->name;
        int xr= temp->redid;

        temp->name = min->name;
        temp->redid= min->redid;

        min->name = x;
        min->redid= xr;

        temp = temp->next;
    }
    cout<<endl<<"Data Sorted Successfully!!!"<<endl<<endl;
}

  void reverse() {
    if (length == 0 || length == 1) {
      return;
    }
    Node *prev = nullptr;
    Node *current = head;
    Node *next = head->next;
    while (next != nullptr) {
      current->next = prev;
      prev = current;
      current = next;
      next = current->next;
    }
    current->next = prev;
    tail = head;
    head = current;
    cout<<endl<<"List Reversed Successfully!!!"<<endl<<endl;
    }
    
};

int main() {
    
    LinkedList linklist;
    int choice,index,size,redid;
    string name;

    do{
        cout<<endl;
        cout << "LINKED LIST PROGRAM" << endl;
        cout << "CHOOSE FROM THE FOLLOWING OPTIONS:" << endl;
        cout << "0. Print Linked List"  << endl;
        cout << "1. Make a Linked List" << endl;
        cout << "2. Add a Node to the beginning" << endl;
        cout << "3. Add a Node to the End" << endl;
        cout << "4. Add a Node at Index" << endl;
        cout << "5. Delete Node from the beginning" << endl;
        cout << "6. Delete Node from the End" << endl;
        cout << "7. Delete Node at Index" << endl;
        cout << "8. Sort by Name" << endl;
        cout << "9. Sort by REDID" << endl;
        cout << "10. Reverse LinkedList" << endl;
        cout << "11. Exit" << endl;
        cout<<endl;

        cout << "Enter Choice: ";
        cin >> choice;

        if(choice==0){
            linklist.printList();
            }
        else if(choice==1){
            cout<<"Linked List was created Successfully."<<endl;
            }
        else if(choice==2){
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter REDID: ";
            cin >> redid;
            linklist.prepend(redid, name);
            cout<<endl;
          }
        else if (choice ==3){
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter REDID: ";
            cin >> redid;
            linklist.append(redid, name);
          } 
        else if (choice ==4){
            cout << "Enter Index: ";
            cin >> index;
            while (index < 0 || index > linklist.getLength()) {
                cout << "Invalid Index" << endl;
                cout << "Enter Index: ";
                cin>>index;
            }
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter REDID: ";
            cin>>redid;
            linklist.insert(index, redid, name);
            cout<<endl;
            }
        else if (choice ==5){
            linklist.deleteFirst();
            cout<<endl;
          }
        else if (choice ==6){
            linklist.deleteLast();
            cout<<endl;
            }
        else if (choice ==7){
            cout << "Enter Index: ";
            cin >> index;
            while (index < 0 || index > linklist.getLength()) {
                cout << "Invalid Index" << endl;
                cout << "Enter Index: ";
                cin>>index;
            }
            linklist.deleteNode(index);
            cout<<endl;
          } 
        else if (choice ==8){
            linklist.sortByName();
            cout<<endl;
          } 
        else if (choice ==9){
            linklist.sortByREDID();
            cout<<endl;
          } 
        else if (choice ==10){
            linklist.reverse();
            cout<<endl;
          } 
        else if(choice==11){
          break;
        }
        else{
            cout<<endl<<"Please Enter Valid Choice !!!"<<endl;
        }
    }while(choice!=11);
    };