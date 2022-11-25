#include <bits/stdc++.h>
#include <unistd.h>
#include "arm.cpp"
#include "display.cpp"
using namespace std;

string command;

void recordArmPosition(Base &b1, Grip &g1, Shoulder &s1, Elbow &e1)
{
    // for recording different arm positions to display
    positionIndex++;     
    g1.GripPositions[positionIndex] = g1.servoGripValue;
    b1.BasePositions[positionIndex] = b1.servoBaseValue;
    s1.ShouPositions[positionIndex] = s1.servoShouValue;
    e1.ElbowPositions[positionIndex] = e1.servoElbowValue;

}

void setPositionZero(Base &b1,Shoulder &s1,Grip &g1,Elbow &e1)
{
    /* move the arm to position zero (
    set positions of the different motors to
    the mid position) */

    b1.servoBaseValue = b1.midBase;
    s1.servoShouValue = s1.midShou;
    g1.servoGripValue = g1.midGrip;
    e1.servoElbowValue = e1.midElbow;
}

void outputPosition(Base &b1, Shoulder &s1, Grip &g1, Elbow &e1) { // displays the current values of the different parts of the arm
    cout << "Base: " << b1.servoBaseValue << endl;
    cout << "Shoulder: " << s1.servoShouValue << endl;
    cout << "Grip: " << g1.servoGripValue << endl;
    cout << "Elbow: " << e1.servoElbowValue << endl;
}

void setup(Base &b1, Grip &g1, Shoulder &s1, Elbow &e1)
{
    // for initialising the variables for the arm
    // myservoBase.attach(servoBasePin);  attaches the servo
    // myservoShou.attach(servoShouPin);  attaches the servo
    // myservoGrip.attach(servoGripPin);  attaches the servo
    // myservoElbw.attach(servoElbwPin);  attaches the servo

    cout << "\a" << endl; // generates a beep sound

    recordArmPosition(b1,g1,s1,e1);

    cout << "Red LED OFF" << endl; 
    cout << "Green LED OFF" << endl;
    cout << "Yellow LED ON" << endl;

    setPositionZero(b1,s1,g1,e1); // Put Arm at "position zero" that is defined as "mid<servo>" position

    // usleep(time); adds a delay 
    outputPosition(b1,s1,g1,e1); // Display Servo Positions

    startTaskMessage();
    cout << "Green LED ON" << endl;
}

void checkCommand()
{
    // takes command as input
    cin >> command;
}


/* bool movement()
{
    // to check if the arm has moved
    if (oldPosition != newPosition)
    {
        return true;
    }

    else
    {
        return false;
    }
}

*/

void setBasePosition(Base &b1, float base) {
    b1.servoBaseValue = base;
}

void setShouPosition(Shoulder &s1, float shou) {
    s1.servoShouValue = shou;
}

void setGripPosition(Grip &g1, float grip) {
    g1.servoGripValue = grip;
}

void setElbowPosition(Elbow &e1, float elbow) {
    e1.servoElbowValue = elbow;
}

// some useful display functions

void displayMessage(string message)
{
    // to print custom messages on the display

    cout << message << endl;
}

void displayRecordedPositions(Base &b1, Shoulder &s1, Grip &g1, Elbow &e1) { // displays the recorded positions stored in BasePositions[] etc
    cout << "Base positions: ";
    for(int j=0;j<positionIndex+1;j++) {
        cout << b1.BasePositions[j] << endl;
    }

    cout << "Shoulder positions: ";
    for(int j=0;j<positionIndex+1;j++) {
        cout << s1.ShouPositions[j] << endl;
    }

    cout << "Grip positions: ";
    for(int j=0;j<positionIndex+1;j++) {
        cout << g1.GripPositions[j] << endl;
    }

    cout << "Elbow positions: ";
    for(int j=0;j<positionIndex+1;j++) {
        cout << e1.ElbowPositions[j] << endl;
    }
}

int main() {
    onMessage();

    Base b1;
    Shoulder s1;
    Grip g1;
    Elbow e1;

    setup(b1,g1,s1,e1);

    char c = 'y';
    char pos_display = 'n'; 

    float b,s,g,e;

    startTaskMessage();

    while(c == 'y') {

        cout << "Enter base: ";
        cin >> b;

        cout << "Enter shoulder: ";
        cin >> s;

        cout << "Enter elbow: ";
        cin >> e;

        cout << "Enter grip: ";
        cin >> g;

        setBasePosition(b1,b);
        setShouPosition(s1,s);
        setGripPosition(g1,g);
        setElbowPosition(e1,e);

        recordArmPosition(b1,g1,s1,e1);

        cout << "Do you wish to see the current position of the arm?" << endl;
        cin >> pos_display;

        if((pos_display == 'y') | (pos_display == 'Y')) {
            outputPosition(b1,s1,g1,e1);
        }

        cout << "Press y if you wish to give more commands else press n" << endl;
        cin >> c;
    }

    endTaskMessage();

    return 0;
}