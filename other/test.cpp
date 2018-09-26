#include <iostream>
#include <cmath>
#include <random>
#include <fstream>

using namespace std;

int main(){
	string name;

	cout << "Type your name: ";
	cin >> name;
	cout << "\nYour name is: " + name + ". \nNot that this is anything special or anything. Im just learning c++ the day before im supposed to test out of a fucking class ive already taken in c... fucking bollocks!\n\n";

	int trials;
	cout << "Now lets calculate pi yo, how many trials you want bro? Enter here: ";
	cin >> trials;
	//pi*r*r = a
	//2*r*2*r = b
	// (b/a) = (4pi)
	double what_the_fuck_is_pi;
	double darts = 0.0;
	double on_target = 0.0;
	int scope = 100000000;
	double x,y;

	/* initialize random seed: */
  	srand (time(NULL));

  	ofstream myfile;
	  myfile.open ("pi_estimite.txt");
	  
	  
	string msg;

	for (int i = 0; i < trials; i++)
	{
		darts++;
		double r = (scope/2.0);
		x = fmod(rand(), scope) - r;
		y = fmod(rand(), scope) - r;

		if ((((x)*(x)) + ((y)*(y))) <= (r*r)) {
			on_target++;
		}

		what_the_fuck_is_pi =  4.0*(on_target/darts);
		msg = "Trial: " + to_string(darts) + "	pi: " + to_string(what_the_fuck_is_pi) + "\n";
		cout << msg;
		myfile << msg;

	}
	myfile.close();
	cout << scope << endl;
  	cout << x << endl;
  	cout <<y << endl;





	return 0;
}