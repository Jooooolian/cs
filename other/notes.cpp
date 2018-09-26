#include <iostream>
#include <cmath>
#include <random>
#include <fstream>

using namespace std;


void array_notes(){
	int **p;
	int size_of_array = 100;
	p = new int*[size_of_array];
	p[0] = new int[4];
	p[1] = new int[4];
	for (int i = 0; i < size_of_array; i++){
		p[i] = new int[4];
	}
	delete [] p;
}



void swapnum(int &i, int &j) {
  int temp = i;
  i = j;
  j = temp;
}

//from a to b
void fib_sum (int &a, int &b, int &sum) {
	int x = 0;
	int y = 1;
	sum = 0;
	int temp;

	int counter = 0;
	while (counter < b){

		if (counter >= a){
			cout << to_string(x) + "+";
			sum += x;
		}
		counter++;

		swapnum(x,y);
		y = x + y;
	}
}


void fibbi(){
	int a;
	int b;
	int sum;
	cout << "Sum elements a --> b of the fibonacci sequence.\na: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	fib_sum(a,b,sum);
	cout << "=" + to_string(sum) << endl;
	cout << "\nSum: " + to_string(sum) << endl;
}

int main () {
	string a = "test";
	cout << a.substr(2);
}


