#include <iostream>
#include "entities\Element.h";
#include "entities\Vector.h"

using namespace std;
//slojih namespace std za da ne izpolzvame navsqkude std:: ,tva samo v main-a, navsqkude drugade bez namespace !

int main() {

    cout << "Start coding madafuckersss !" << endl;
	Vector vect(-3, -2, 5);
	/*cout << "Vect length test: " << vect.vectorLength() << endl;
	vect.vectorDirection();
	cout << "Changed values for vect after the direction: " << endl;
	cout << "X: " << vect.getX() << endl;
	cout << "Y: " << vect.getY() << endl;
	cout << "Z: " << vect.getZ() << endl;*/
//	cout << boolalpha << vect.vectParallelism() << endl;
	//cout << boolalpha << vect.vectPerpendicularity() << endl;
	Vector vectSum;
	Vector vect2(3, 2, 5);
	vectSum = vect + vect2;
	cout << vectSum << endl;
	//cout << vect - vect2 << endl;
	//cout << 2 * vect2 << endl;
//	cout << vect * vect2;
	cout << (vect ^ vect2);
	cout << endl;
	Vector u(5.4, 2, 3);
	Vector v(3.9, 2, 1);
	Vector w(15, 4.7, 9);
	cout << u(v, w) << endl;
	//Vectors - done

}
