#include <iostream>
#include "entities\Element.h";
#include "entities\Vector.h"

using namespace std;
//slojih namespace std za da ne izpolzvame navsqkude std:: ,tva samo v main-a, navsqkude drugade bez namespace !

int main() {

    cout << "Start coding madafuckersss !" << endl;
	Vector vect(2,3,4);
	cout << "Vect length test: " << vect.vectorLength() << endl;
	vect.vectorDirection();
	cout << "Changed values for vect after the direction: " << endl;
	cout << "X: " << vect.getX() << endl;
	cout << "Y: " << vect.getY() << endl;
	cout << "Z: " << vect.getZ() << endl;

}
