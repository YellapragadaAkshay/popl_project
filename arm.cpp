#include<bits/stdc++.h>
using namespace std;

int positionIndex = 0;

class Base
{
    public: 
        // used for rotation of arm
        float minBase;
        float maxBase; // initial angles of base servo motor
        float midBase;
        float servoBaseValue;
        float BasePositions[100];
        /*to store past and new positions of
        Base*/

    public: 
        Base() {
            minBase = 0;
            maxBase = 360;
            midBase = 180;
            servoBaseValue = midBase;

            for(int j=0;j<100;j++) {
                BasePositions[j] = -1;
            }
        }

        Base(float x) {
            servoBaseValue = x;
        }
};

class Shoulder
{
    public:
    // used for moving the arm upwards/downwards
        float minShou;
        float maxShou; // initial angles of shoulder servo motor
        float midShou;
        float servoShouValue;
        float ShouPositions[100];
        // to store past and new positions of Shoulder

    public: 
        Shoulder() {
            minShou = 0;
            maxShou = 180;
            midShou = 90;
            servoShouValue = midShou;

            for(int j=0;j<100;j++) {
                ShouPositions[j] = -1;
            }
        }

        Shoulder(float x) {
            servoShouValue = x;
        }
};

class Grip
{
    public:
        // used for picking up objects
        float minGrip;
        float maxGrip; // initial angles of grip servo motor
        float midGrip;
        float servoGripValue;
        float GripPositions[100];
        // to store past and new positions of Grip

    public: 
        Grip() {
            minGrip = 0;
            maxGrip = 100;
            midGrip = 50;
            servoGripValue = midGrip;

            for(int j=0;j<100;j++) {
                GripPositions[j] = -1;
            }
        }

        Grip(float x) {
            servoGripValue = x;
        }
};

class Elbow
{
    public: 
        // used for moving the arm forward/backward
        float minElbow;
        float maxElbow; // initial angles of elbow servo motor
        float midElbow;
        float servoElbowValue;
        float ElbowPositions[100];
        // to store past and new positions of Elbow

    public: 
        Elbow() {
            minElbow = 0;
            maxElbow = 180;
            midElbow = 90;
            servoElbowValue = midElbow;

            for(int j=0;j<100;j++) {
                ElbowPositions[j] = -1;
            }
        }

        Elbow(float x) {
            servoElbowValue = x;
        }
};
