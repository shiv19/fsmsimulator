/*
    Title   : Finite State Machine(FSM) Simulator!
    Author  : Shiva Prasad K
    Desc    : Using this program the user can make Simple FSM which accepts the letters 'a' or 'b',
              and perform respective actions.
    Version : v1.0 [Beta]

    ======================================================================================
    Long Description:
        In theory of computation, a branch of theoretical computer science, a deterministic
        finite automaton (DFA), also known as deterministic finite state machine, is a finite state machine
        that accepts/rejects finite strings of symbols and only produces a unique computation (or run)
        of the automaton for each input string.

        This program was made to allow the student to create and simulate their own FSM.

    ======================================================================================
    Instructions:

                 In order to simulate an FSM,
                   >> You have to first create a sketch of the FSM on paper,
                  Now using the program,
                   >> Create required number of states 1 by 1,
                   >> Configure each of the states.
                   >> Run FSM by providing the input string of 'a's and 'b's in any order.

                   How to Configure a state?
               Ans: From the menu, choose configure. Select the state.
                   Answer each question with either 0 or 1.

                   Note: You should only have 1 active state in an FSM,
                   This program was made to solve deterministic FSM only!.

    ======================================================================================

    A Simple Example of Finite State Machine:

    >>  An FSM to accept input strings with a's & b's having only Odd number of a's.

        For an FSM that accepts input strings with a's & b's having only Odd number of a's,
        we will need 2 states. Let's say that the 2 states are q0 and q1.

        q0 will be the initial state.
        q1 will be the final state.

        q0 upon 'a' gives q1
        q0 upon 'b' gives q0
        q1 upon 'a' gives q0
        q1 upon 'b' gives q1

        So, on creating such states in our FSM Simulator, we get the following result.

        OUTPUT:

        Hello and Welcome to the FSM Simulator!

        MENU
        1.Add State             2.Configure State       3.List State
        4.Remove Prev State     5.Display State         6.Run FSM
        7.Clear Screen          8.Help                  9.Exit
        Enter Choice: 1

        A new state q0 has been added!

        MENU
        1.Add State             2.Configure State       3.List State
        4.Remove Prev State     5.Display State         6.Run FSM
        7.Clear Screen          8.Help                  9.Exit
        Enter Choice: 1

        A new state q1 has been added!

        MENU
        1.Add State             2.Configure State       3.List State
        4.Remove Prev State     5.Display State         6.Run FSM
        7.Clear Screen          8.Help                  9.Exit
        Enter Choice: 2

        0. q0
        1. q1
        Enter State Number to configure : 0
        Enter Target for 'a' in string:
        1
        Enter Target for 'b' in string:
        0
        Is the state active?
        1
        Is the state final?
        0

        MENU
        1.Add State             2.Configure State       3.List State
        4.Remove Prev State     5.Display State         6.Run FSM
        7.Clear Screen          8.Help                  9.Exit
        Enter Choice: 2

        0. q0
        1. q1
        Enter State Number to configure : 1
        Enter Target for 'a' in string:
        0
        Enter Target for 'b' in string:
        1
        Is the state active?
        0
        Is the state final?
        1

        MENU
        1.Add State             2.Configure State       3.List State
        4.Remove Prev State     5.Display State         6.Run FSM
        7.Clear Screen          8.Help                  9.Exit
        Enter Choice: 6
        Enter the string to be Fed: baaba

        The String : baaba
        is Accepted!!

        MENU
        1.Add State             2.Configure State       3.List State
        4.Remove Prev State     5.Display State         6.Run FSM
        7.Clear Screen          8.Help                  9.Exit
        Enter Choice: 6
        Enter the string to be Fed: bbaabbaa

        The String : bbaabbaa
        is Rejected!!

        MENU
        1.Add State             2.Configure State       3.List State
        4.Remove Prev State     5.Display State         6.Run FSM
        7.Clear Screen          8.Help                  9.Exit
        Enter Choice: 9

        Thank You for using Shiv's FSM Simulator
        Process returned 0 (0x0)   execution time : 75.256 s
        Press any key to continue.



    ======================================================================================

    Variable Definitions:
    Choice              : char
     Stores the menu choice of the user.

    states[MAX_STATES]  : State
     It is an array of State objects.

    ======================================================================================

    This project was started on ‎August ‎14, ‎2015, ‏‎10:48:46 PM,
    And it was last modified on ‎August ‎15, ‎2015, ‏‎11:15:19 PM.
*/
#include <iostream>
#include <stdlib.h> // This is so that I can use the "system()" function

// Custom headers
#include "State.h"
#include "Feeder.h"

#define MAX_STATES 10 // Change this number if you want to use more than 10 states.

using namespace std;

int main()
{
    char choice;
    State states[MAX_STATES];

    cout << "Hello and Welcome to the FSM Simulator!" << endl;

    do{
        /*
                    This Do While Loop is Handling the Menu Operations.
                    I have used a char type variable to store the user's choice,
                    to avoid errors when user enters non-numeric choices.
        */
        cout << "\nMENU\n1.Add State\t\t2.Configure State\t3.List State\
        \n4.Remove Prev State\t5.Display State\t\t6.Run FSM\n7.Clear Screen\t\t8.Help\t\t\t9.Exit\nEnter Choice: ";
        cin >> choice;
        switch(choice){
            //
            // Switch case that decides what to do with the user's choice
            //
            case '1': // Add State
                      State::addState();
                      cout << "\nA new state q" << State::Counter - 1 << " has been added!\n";
                      break;

            case '2': // Configure State
                      {
                                int choice;
                                State::listState();
                                cout << "Enter State Number to configure : ";
                                cin >> choice;
                                states[choice].configure();
                      }break;

            case '3': // List State
                      State::listState();
                      break;

            case '4': // Remove State
                      State::remState();
                      cout << "\nThe previous state q" << State::Counter << " has been removed!\n";
                      break;

            case '5': // Display State
                      {
                                int choice;
                                State::listState();
                                cout << "Enter State Number to display : ";
                                cin >> choice;
                                states[choice].dispState(choice);
                      }break;

            case '6': // Run FSM
                      {
                        Feeder *f = new Feeder; // Dynamically creating Feeder object in a limited scope
                        f->feed(states);
                        delete[] f;
                      }break;

            case '7': // Clear Screen
                      {
                        system("cls");break;
                      }

            case '8': // Opens up the Help.txt in the Command Prompt Editor
                      {
                        system("Help.txt");break;
                      }

            case '9': cout << "\nThank You for using Shiv's FSM Simulator";break; // Exit Message

            default : cout << "\nInvalid Option!";
        }
    }while(choice != '9');

    return 0;
}
// EOF
