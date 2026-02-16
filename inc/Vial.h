#pragma once
#include <string>

using namespace std;

class Vial {
private:
    
    char contents[4];       // Array to store vial contents (characters)
    int filled;                // Number of filled slots in the vial
    int label;                 // Label for identifying the vial
public:
     static const int SIZE = 4;  // Maximum size
     
    // Constructors
    Vial();
    Vial(char arr[], int size, int filledAmount);
    Vial(char c1, char c2, char c3, char c4, int filledAmount);

    // Adds a character to top of vial
    bool add(char content);

    // Displays vial on screen
    void display() const;

    // Checks if vial is complete (all same character)
    bool isComplete() const;

    // Sets label number
    void setLabel(int newLabel);

    // Transfers top element to another vial
    bool transfer(Vial& destination);

    // Helper function
    int getFilled() const;
};