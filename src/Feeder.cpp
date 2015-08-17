#include "Feeder.h"
/*

    Author: Shiva Prasad K
    This File Contains the Class Implementations for 'Feeder' Header File.
*/

Feeder::Feeder()
{
    // Constructor that asks for the input string.
    cout << "Enter the string to be Fed: ";
    cin >> str;
}

void Feeder :: feed(State*  states){
    // This function feeds the input string One letter at a
    // time to the process() function of a State Object
    // which is currently active. (there can only be one
    // active state at a time.)
    int i = 0;
    int j;
    int len;

    len = strlen(str);
    while(i != len){
        // This while loop is checking which state is currently
        // active and passing the input character to the process() function
        // as long as there are more characters left in the input string.
        j = State::whoActive(states);
        states[j].process(str[i], states);
        i++;
    }

    // After the feeder feeds all the character to FSM,
    // the code below this checks which state is active,
    // and if the active state is a final state then it
    // accepts the string, else it rejects it.
    j = State::whoActive(states);

    if(states[j].getIsFinal()){
        cout << "\nThe String : " << str;
        cout << "\nis Accepted!!\n";
    }else{
        cout << "\nThe String : " << str;
        cout << "\nis Rejected!!\n";
    }

    // The Code below this, resets the FSM after
    // it finishes processing the input string.
    while(State::whoActive(states) != -1){
        j = State::whoActive(states);
        states[j].setIsActive(false);
    }states[0].setIsActive(true);
}
