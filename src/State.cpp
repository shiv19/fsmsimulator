#include "State.h"
/*

    Author: Shiva Prasad K
    This File Contains the Class Implementations for 'State' Header File.
*/
State::State()
{
    // Sets default values for the class variables
    TarA = 0;
    TarB = 0;
    isActive = false;
    isFinal = false;
}

unsigned int State :: Counter = 0; // Initializing Static variable 'Counter'
int State :: curActive = 0; // Initializing Static variable 'curActive'

void State :: setTarA(int val){
    // Sets the target state when the character
    // received is 'a'
    TarA = val;
}
void State :: setTarB(int val){
    // Sets the target state when the character
    // received is 'b'
    TarB = val;
}

void State :: incCounter(){
    // Increments State Counter
    Counter += 1;
}

void State :: decCounter(){
    // Decrements State Counter
    Counter -= 1;
}

unsigned int State :: GetCounter(){
    // Returns the number of states in use.
    return Counter;
}

bool State :: getIsActive(){
    // Tells if the current state is active.
    return isActive;
}

bool State :: getIsFinal(){
    // Tells if the current state is a final state.
    return isFinal;
}

void State :: setIsActive(bool val){
    // Used to set the setIsActive variable.
    isActive = val;
}

void State :: addState(){
    // Adds a state by incrementing the counter.
    // (a redundant function added for convenience)
    State::incCounter();
}

void State :: remState(){
    // Removes the last added state by decrementing
    // the counter. (a redundant function added for convenience)
    State::decCounter();
}

void State :: listState(){
    // Lists the available states
    cout << endl;
    for(unsigned int i = 0; i < Counter; i++){
        cout << i << ". q" << i << endl;
    }
}

void State :: dispState(int n){
    // Prints out the details of the selected n'th state
    cout << "\nDetails of State q" << n << endl;
    cout << "q" << n << " upon 'a' -> " << "q" << TarA << endl;
    cout << "q" << n << " upon 'b' -> " << "q" << TarB << endl;
    if(isActive){
        cout << "This state is currently active!" << endl;
    }else{
        cout << "This state is currently NOT active!" << endl;
    }
    if(isFinal){
        cout << "This state is a Final State!" << endl;
    }else{
        cout << "This state is NOT a Final State!" << endl;
    }
}

int State :: whoActive(State*  states){
    // Checks which state is active and returns its position.
    unsigned int i;
    for(i = 0; i < Counter; i++){
        if(states[i].getIsActive()){
            curActive = i;
            return curActive;
        }
    }
    return -1;
}



void State :: configure(){
    // Used to configure the selected n'th state.
    cout << "Enter Target for 'a' in string: " << endl;
    cin >> TarA;
    cout << "Enter Target for 'b' in string: " << endl;
    cin >> TarB;
    cout << "Is the state active?" << endl;
    cin >> isActive;
    cout << "Is the state final?" << endl;
    cin >> isFinal;
}


void State :: process(char data, State* states){
    // Feeder object uses this function to process the string.
    if(data == 'a'){
        states[curActive].isActive = false;
        states[TarA].isActive = true;
    }else if(data == 'b'){
        states[curActive].isActive = false;
        states[TarB].isActive = true;
    }
}


