// Ilhan Sertelli

#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

Board::Board() {
    first = NULL;
}

// Parametric Constructor Implementation
Board::Board(const int & slot) {
    first = new Node;
    Node * ptr = first;
    for (int i = 0; i < slot - 1; i++) {
        ptr->next = new Node; // Creating the board including "slot" amounts of slots
        ptr = ptr->next;
    }
    ptr->next = first; // Making the board circular
}

// Deep Copy Constructor
Board::Board(const Board & board) {
    Node * ptr;
    ptr = board.first;
    int count = 1;

    // Counting the amount of slots of the template board
    while (ptr->next != board.first) {
        ptr = ptr->next;
        count++;
    }

    first = new Node; // Creating the first slot
    ptr = first;
    // Creating the rest of the template board
    for (int i = 1; i < count; i++) {
        ptr->next = new Node;
        ptr = ptr->next;
    }
    ptr->next = first; // Making the copy board circular
}

Board & Board::operator =(const Board & rhs) {
    Node * ptr = this->first;

    // Changing the status of the lhs list from circular to linear
    while (ptr->next != this->first) {
        ptr = ptr->next;
        if (ptr->next == this->first) {
            ptr->next = NULL;
            break;
        }
    }
    ptr = this->first;
    // Destructing the lhs list
    while (ptr != NULL) {
        Node * temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
    ptr = rhs.first;
    this->first = new Node;
    Node * temp = this->first;
    // Copying the rhs list and assigning it to the lhs list
    while (ptr->next != rhs.first) {
        temp->next = new Node;
        temp->next->owner = ptr->owner;
        temp->next->next = NULL;
        temp = temp->next;
        ptr = ptr->next;
        if (ptr->next == rhs.first) {
            temp->next = this->first;
        }
    }
    return *this;
}

// Destructor Implementation
Board::~Board() {
    Node * ptr;
    ptr = first;

    // Changing the status of the list from circular to linear
    while (ptr->next != first) {
        ptr = ptr->next;
        if (ptr->next == first) { // Done in here
            ptr->next = NULL;
            ptr = first;
            break;
        }
    }
    ptr = first;
    // Deallocating the slots one by one
    while (ptr != NULL) {
        Node * temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
}
// Just returning the first slot
Node* Board::firstNode() const {
    return first;
}

void Board::display() const {
    Node * ptr = first;
    string slotName; // String of the slots
    int count = 0;

    do {
        if (ptr->next != first) { // Meaning that the pointer does not show the last slot before returning to the beginning of the board
            if (ptr->owner == "None")
                slotName += (ptr->owner + "->");
            else
                slotName += (ptr->owner + " ->");
            count += 6; // Each slot except the last slot should consist of a string of a length of 6
        }
        else { // Meaning that the pointer shows the last slot
            if (ptr->owner == "None")
                slotName += ptr->owner;
            else
                slotName += (ptr->owner + " ");
            count += 4; // The last slot should consist of a string of a length of 4
        }
        ptr = ptr->next;
    } while (ptr != first); // Iterate as long as the pointer does not show the first slot again

    cout << slotName << endl;

    // Printing the second line
    for (int i = 0; i < count; i++) {
        if (i == 0)
            cout << "^";
        else if (i == count - 1)
            cout << "|" << endl;
        else
            cout << " ";
    }
    // Printing the last line
    for (int j = 0; j < count; j++) {
        if (j == 0)
            cout << "|";
        else if (j == count - 1)
            cout << "v" << endl;
        else if (j % 6 == 5)
            cout << "<";
        else
            cout << "-";
    }
}
// Just returning the owner of the slot
string Board::who_owns(const Node *ptr) const {
    return ptr->owner;
}