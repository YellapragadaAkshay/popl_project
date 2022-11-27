#include<bits/stdc++.h>
using namespace std;

void onMessage() {  // prints a message to indicate that the arm has been turned on
    cout << "Arm ON \a" << endl;
}

void offMessage() { // prints a message to indicate that the arm is turning off
    cout << "Arm OFF \a" << endl;
}

void displayMessage(string message)
{
    // to print custom messages on the display
    cout << message << endl;
}

void startTaskMessage() { // prints a message to indicate that a task has started executing
    cout << "Task started \a" << endl; // generates a beep along with message
}

void stopTaskMessage() { // prints a message to indicate that the ongoing task has been stopped
    cout << "Task stopped \a" << endl; // generates a beep along with message
}

void endTaskMessage() { // prints a message to indicate that the given task has been completed
    cout << "Task ended \a" << endl; // generates a beep along with message
}

void errorMessage() { // used to handle invalid input/ unexpected errors
    cout << "Error" << endl;
}