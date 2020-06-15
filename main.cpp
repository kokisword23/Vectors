#include <iostream>
#include "entities\Element.h"
#include "entities\Vector.h"
#include "entities\Point.h"
#include "entities/vectorlengthexception.h"
#include <cmath>

using namespace std;
//slojih namespace std za da ne izpolzvame navsqkude std::  ,tva samo v main-a, navsqkude drugade bez namespace !

int main() {
    cout << "Welcome to our Vectors Project! " << endl;
    int geoObj;
    do {
        cout << "Please enter type of geometrical object: (between 1 and 5, 0 to terminate)" << endl;
        cout << "1. Point " << endl;
        cout << "2. Vector " << endl;
        cout << "3. Line " << endl;
        cout << "4. Segment " << endl;
        cout << "5. Triangle " << endl;

        double x, y, z;

        Vector vect;
        Point p;
        cin >> geoObj;
        switch (geoObj) {
            case 1:
                cout << "Please enter x,y,z for Point:" << endl;
                cin >> p;
                cout << p << endl;

                break;

            case 2:
                cout << "Please enter x for Vector: ";
                cin >> x;
                vect.setX(x);
                cout << "Please enter y for Vector: ";
                cin >> y;
                vect.setY(y);
                cout << "Please enter z for Vector: ";
                cin >> z;
                vect.setZ(z);
                
                cout << "Functions: " << endl;
                cout << "1.Vector length" << endl;
                cout << "2.Vector direction" << endl;
                cout << "3.Check Vector length" << endl;
                cout << "4.Vector Parallelism" << endl;
                cout << "5. Vector Perpendicularity" << endl;
                int funcChoose;
                cout << "Chose function to perform: ";
                cin >> funcChoose;
                switch (funcChoose) {
                    case 1:
                        cout << "The length of the vector is:" << vect.checkVectLength() << endl;
                        break;
                    case 2:
                        cout << "Calculated vector direction: " << endl;
                        try {
                            vect.vectorDirection();

                        }
                        catch (const VectorLengthException &vectorExc) {
                            cerr << vectorExc.what() << endl;
                            cout << "Please enter new values for x,y and z that are not 0 ! \n";
                            double num;
                            do {
                              cin >> num;
                                vect.setX(num);
                                cin >> num;
                                vect.setY(num);
                               cin >> num;
                                vect.setZ(num);
                            } while (num != 0);


                            vect.setX(vect.getX() /
                                      sqrt(pow(vect.getX(), 2) + pow(vect.getY(), 2) + pow(vect.getZ(), 2)));
                            vect.setY(vect.getY() /
                                      sqrt(pow(vect.getX(), 2) + pow(vect.getY(), 2) + pow(vect.getZ(), 2)));
                            vect.setZ(vect.getZ() /
                                      sqrt(pow(vect.getX(), 2) + pow(vect.getY(), 2) + pow(vect.getZ(), 2)));
                        }
                        break;
                    case 3:
                        if (vect.checkVectLength()) {
                            cout << "Vector length is 0 ! " << endl;
                        } else {
                            cout << "Vector length isn't 0 ! " << endl;
                        }

                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    default:
                        break;
                }
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;

            default:
                break;
        }
    } while (geoObj != 0);
}


