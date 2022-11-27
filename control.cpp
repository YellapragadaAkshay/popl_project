#include <bits/stdc++.h>
#include <unistd.h>
#include "arm.cpp"
#include "display.cpp"
using namespace std;

string command;

// some useful control functions

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

void displayRecordedPositions(Base &b1, Shoulder &s1, Grip &g1, Elbow &e1) { // displays the recorded positions stored in BasePositions[] etc
    cout << "Base    Shoulder    Grip    Elbow";
        
    for(int i=0;i<positionIndex;i++) {
        cout << b1.BasePositions[i] << "    "  << s1.ShouPositions[i] << "    " << g1.GripPositions[i] << "    " << e1.ElbowPositions[i] << endl;
    }
}

void displayBasePositions(Base &b1) {
    cout << "Base positions: ";
    for(int j=0;j<positionIndex+1;j++) {
        cout << b1.BasePositions[j] << endl;
    }
}

void displayShouPositions(Shoulder &s1) {
    cout << "Shoulder positions: ";
    for(int j=0;j<positionIndex+1;j++) {
        cout << s1.ShouPositions[j] << endl;
    }
}

void displayGripPositions(Grip &g1) {
    cout << "Grip positions: ";
    for(int j=0;j<positionIndex+1;j++) {
        cout << g1.GripPositions[j] << endl;
    }
}

void displayElbowPositions(Elbow e1) {
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
    int command_no;
    int max_commands = 7;

    float b,s,g,e;

    startTaskMessage();

    while((c == 'y') | (c == 'Y')) {
        cout << "enter command no. " << endl;
        cout << "1. Set arm position\n";
        cout << "2. Display current position of arm\n";
        cout << "3. Set arm to position zero\n";
        cout << "4. Display recorded positions\n";
        cout << "5. Display current positions of base/shoulder/grip/arm\n";
        cout << "6. Display recorded positions of base/shoulder/grip/arm\n";
        cout << max_commands <<". exit\n";

        cin >> command_no;

        if((command_no <= 0) | (command_no > max_commands)) {
            errorMessage();
            cout << "Invalid command no." << endl;
        }

        else if(command_no == 1) {
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
        }

        else if(command_no == 2) {
            outputPosition(b1,s1,g1,e1);
        }

        else if(command_no == 3) {
            setPositionZero(b1,s1,g1,e1);
            cout << "Position set to zero successfully\n";
        }

        else if(command_no == 4) {
            displayRecordedPositions(b1, s1, g1, e1);
        }

        else if(command_no == 5) {
            char opt;
            cout << "press b for base, s for shoulder, g for grip and, e for elbow\n";
            cin >> opt;

            if((opt == 'b') | (opt == 'B')) {
                cout << "Base position: ";
                cout << b1.servoBaseValue << endl;
            }

            else if((opt == 's') | (opt == 'S')) {
                cout << "Shoulder position: ";
                cout << s1.servoShouValue << endl;
            }

            else if((opt == 'g') | (opt == 'G')) {
                cout << "Grip position: ";
                cout << g1.servoGripValue << endl;
            }

            else if((opt == 'e') | (opt == 'E')) {
                cout << "Elbow position: ";
                cout <<e1.servoElbowValue << endl;
            }

            else {
                errorMessage();
                cout << "Invalid option" << endl;
            }
        }

        else if(command_no == 6) {
            char opt;
            cout << "press b for base, s for shoulder, g for grip and, e for elbow\n";
            cin >> opt;

            if((opt == 'b') | (opt == 'B')) {
                displayBasePositions(b1);
            }

            else if((opt == 'g') | (opt == 'G')) {
                displayGripPositions(g1);
            }

            else if((opt == 's') | (opt == 'S')) {
                displayShouPositions(s1);
            }

            else if((opt == 'e') | (opt == 'E')) {
                displayElbowPositions(e1);
            }

            else {
                errorMessage();
                cout << "Invalid option" << endl;
            }
        }

        else if(command_no == max_commands) {
            break;
        }

        cout << "Press y if you wish to give more commands else press n" << endl;
        cin >> c;

        if((c!='y')&&(c!='n')&&(c!='Y')&&(c!='N')) {
            errorMessage();
            cout << "please enter y or n\n";
            cin >> c;
        }
    }

    endTaskMessage();

    return 0;
}