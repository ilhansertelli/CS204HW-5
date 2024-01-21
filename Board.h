// Ilhan Sertelli

#include <string>
using namespace std;

#ifndef TAKEHOME5_BOARD_H
#define TAKEHOME5_BOARD_H

struct Node{
    string owner;
    Node* next;
    Node () {
        owner = "None"; next = NULL;
    };
    Node (string o, Node * p) {
        owner = o; next = p;
    };
};

class Board {
public:
    Board();
    Board(const int & slot); // Parametric Constructor
    Board(const Board & board);
    ~Board(); // Destructor
    void display() const;
    Node * firstNode() const;
    string who_owns(const Node * ptr) const;
    Board & operator=(const Board & rhs);
private:
    Node * first; // Points the first slot
};

#endif