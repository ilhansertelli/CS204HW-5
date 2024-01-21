// Ilhan Sertelli

#include <iostream>
#include "Player.h"
#include "Board.h"

using namespace std;

//Parametric Constructor
Player::Player(Board & board1, const string & playerName, const int & capital) : board(board1) {
    name = playerName;
    position = board.firstNode();
    balance = capital;
}


int Player::move(const int & steps) {
    bool check = false;
    for (int i = 0; i < steps; i++) {
        position = position->next;
        // Checking if the player passes through the starting slot
        if (position == board.firstNode()) {
            check = true;
        }
    }
    if (check) // Meaning that the player has passed through the starting slot
        return 1;
    else // Meaning that the player has not passed through the starting slot
        return 0;
}

// Just returning the current position
Node* Player::where_am_I() const {
    return position;
}

// Changing the balance between players
void Player::pay_to_player(Player & otherPlayer, const int & money) {
    otherPlayer.balance += money;
    balance -= money;
}

// Just returning the balance
int Player::get_balance() const {
    return balance;
}

// Adding the money to the total balance
void Player::deposit_money(const int & money) {
    balance += money;
}


void Player::buy_slot(const int & price) {
    position->owner = name; // Meaning that the player owns the current slot
    balance -= price; // Player pays the price of the slot
}

bool Player::is_bankrupt() const {
    if (balance < 0) // Meaning that the player lost the game due to money insufficiency
        return true;
    else // Meaning that the player still has enough money to continue the game
        return false;
}

void Player::display() const {
    int count = 0;
    string displayStr;
    Node * ptr;
    ptr = board.firstNode();

    // Counting the number of the slots of the board
    do {
        ptr = ptr->next;
        count++;
    } while (ptr != board.firstNode());

    ptr = board.firstNode();

    do {
        if (ptr->next == board.firstNode()) {
            if (ptr == position) { // Display the position of the player if the pointer shows the current position of the player
                cout << displayStr << name << " " << balance << endl;
                break;
            }
        }
        else {
            if (ptr == position) {
                cout << displayStr << name << " " << balance << endl;
                break;
            }
            else {
                displayStr += "      "; // As long as the pointer does not show the current position, add blank spaces to the main line string
            }
        }
        ptr = ptr->next;
    } while (ptr != board.firstNode()); // Iterate as long as the pointer does not complete iterating the entire board
}