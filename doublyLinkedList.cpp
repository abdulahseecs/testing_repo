#include <iostream>
using namespace std;

class Node {
 public:
    Node* next;
    Node* prev;
    int data;   
};

class DLL {
 public:
    Node* head;
    Node* last;
    Node* loc;
    Node* ploc;
    
    void destroyList() {
        while (head != last)
        {
            Node* temp = head;
            head = head-> next;
            delete temp;
        }
        delete last;
        head = nullptr;
        last = nullptr;
    }

    void printListReverse() {
        if (last == nullptr) {
            cout << "Nohing to print" << endl;
            return;
        }
        Node* temp = last;
        while (temp != nullptr) {
            cout << temp-> data << " ";
            temp = temp-> prev;
        }
        cout << endl;
    }

    void search(int value) {
        loc = nullptr; ploc = nullptr;
        if (head == loc) {
            cout << "List is empty" << endl;
            return;
        }
        loc = head;
        while (loc != nullptr && loc-> data < value) {
            ploc = loc;
            loc = loc -> next;
        }

        if (loc == nullptr) {
            return;
        }

        if (loc-> data != value) {
            loc = nullptr;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void delElement(int value) {
        search(value);
        if (loc != nullptr) {
            if (ploc == nullptr) {
                if (loc == last) {
                    head = nullptr;
                    last = nullptr;
                }else {
                    loc-> next -> prev = nullptr;  
                    head = loc-> next; 
                }
            }else {
                if (loc == last) {
                    ploc-> next = nullptr;
                    last = ploc;
                }else {
                    ploc-> next = loc-> next;
                    loc->next->prev = ploc;
                }
            }
            delete loc;
        }else {
            cout << "Nothing to delete" << endl;
        }
    }

    void insertAtPos(int value) {
        Node* newNode = new Node();
        newNode -> data = value;

        if(isEmpty()) {
            head = newNode;
            last = newNode;
            return;
        }

        search(value);

        if (loc == nullptr) {
            if (ploc == nullptr) {
                newNode-> next = head;  // ploc -> node
                head-> prev = newNode;  // ploc -> newNode -> node
                head = newNode;
            }else {
                if (ploc == last) {
                    ploc -> next = newNode;
                    newNode-> prev = ploc;
                    last = newNode;
                }else {
                    newNode-> next = ploc-> next;
                    ploc-> next-> prev = newNode;
                    ploc -> next = newNode;
                    newNode-> prev = ploc;
                }
            }
        }
    }

// 1 > 3 -> 5 -> 7            null <- 1 <- 3 <- 5 <- 7
};

int main() {
    DLL* dll = new DLL();

    dll-> insertAtPos(2);
    dll -> insertAtPos(1);
    dll-> insertAtPos(4);
    dll-> insertAtPos(3);
    dll-> insertAtPos(5);

    dll->printListReverse();
    cout << "Head is " << dll->head-> data << endl;
    cout << "Last is " << dll->last-> data << endl;

    dll->delElement(1);
    dll->printListReverse();
    cout << "Head is " << dll->head-> data << endl;
    cout << "Last is " << dll->last-> data << endl;
    dll->delElement(4);
    dll->printListReverse();
    cout << "Head is " << dll->head-> data << endl;
    cout << "Last is " << dll->last-> data << endl;
    dll->delElement(5);
    dll->printListReverse();
    cout << "Head is " << dll->head-> data << endl;
    cout << "Last is " << dll->last-> data << endl;
    dll->delElement(2);
    dll->printListReverse();
    cout << "Head is " << dll->head-> data << endl;
    cout << "Last is " << dll->last-> data << endl;
    dll->delElement(3);
    dll->printListReverse();
    
    // dll->search(12);
    // if (dll-> loc != nullptr) {
    //     cout << dll->loc-> data << endl;
    // }else {
    //     cout << "0" << endl;
    // }
    // if (dll-> ploc != nullptr) {
    //     cout << dll->ploc-> data << endl;
    // }else {
    //     cout << "0" << endl;
    // }
    // dll->destroyList();
    // dll->printListReverse();

    delete dll;

    return 0;
}