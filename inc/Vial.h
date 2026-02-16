#pragma once
#include <string>

using namespace std;

class Vial {
private:
    static const int SIZE = 4; // Maximum number of items in a vial
    char contents[SIZE];       // Array to store vial contents (characters)
    int filled;                // Number of filled slots in the vial
    int label;                 // Label for identifying the vial
public:
    Vial();
    Vial(const char arr[], int size, int filled); // Constructor from array
    Vial(char c1, char c2, char c3, char c4, int filled); // Constructor from 4 chars
    bool add(char content); // Add a character to the vial  
    void display() const;  // Display the vial's contents
    bool isComplete() const; // Check if all contents are the same and vial is full
    void setLabel(int label); // Set the vial's label
    bool transfer(Vial& destination); // Transfer top item to another vial
};