#ifndef FEEDER_H
#define FEEDER_H
/*

    Author: Shiva Prasad K
    This Header File Contains the Class Definitions for a
    child class 'Feeder' which inherits Publicly from a parent
    class 'State'.

    Variable Definitions:
    str[STR_MAX]        : int
     Used to store the input string.

*/
#include <State.h>
#include <string.h>
#define STR_MAX 20 // Change this if you want to input test strings larger than 20.
using namespace std;
class Feeder : public State
{
private:
    // Private Variables
    char str[STR_MAX];
public:
    // Member Functions
    Feeder();
    void feed(State*  states);
};

#endif // FEEDER_H
