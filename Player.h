// Ilhan Sertelli

#include "Board.h"
using namespace std;

#ifndef TAKEHOME5_PLAYER_H
#define TAKEHOME5_PLAYER_H

class Player {
public:
    Player(Board &board1, const string &playerName, const int &capital); // Parametric Constructor
    int move(const int & steps);
    Node* where_am_I() const;
    void pay_to_player(Player & otherPlayer, const int & money); // Sus
    int get_balance() const;
    void deposit_money(const int & money);
    void buy_slot(const int & price);
    bool is_bankrupt() const;
    void display() const;
private:
    string name;
    int balance;
    Node * position;
    Board & board;
};

#endif