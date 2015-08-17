#ifndef STATE_H
#define STATE_H
/*

    Author: Shiva Prasad K
    This Header File Contains the Class Definitions for 'State' Class.

    Variable Definitions:
    TarA        : int
     Stores target state to goto when the character received is 'a'.

    TarB        : int
     Stores target state to goto when the character received is 'b'.

    isActive    : bool
     Tells if the current state is active or not.

    isFinal     : bool
     Tells if the current state is a final state or not.

    Counter     : static int
     Holds the number of states currently in use.

    curActive   : static int
     Holds the state number of the state which is currently active.
*/
#include<iostream>
using namespace std;
class State
{
    private:
        // Private Variables
        int TarA;
        int TarB;

    public:
        // Constructor
        State();

        // Public Variables
        bool isActive;
        bool isFinal;
        static unsigned int Counter;
        static int curActive;

        // Member Functions
        void setTarA(int val);
        void setTarB(int val);

        static void incCounter();
        static void decCounter();
        static unsigned int GetCounter();

        bool getIsActive();
        bool getIsFinal();
        void setIsActive(bool val);

        static void addState();
        static void remState();
        static void listState();
        void dispState(int);
        int whoActive(State*  states);

        void configure();
        void process(char data, State* states);

};

#endif // STATE_H
