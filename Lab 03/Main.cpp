#include <iostream>

using namespace std;

class Demo {
public:
	Demo() {
		cout << "Now the constructor is running" << endl;
	}
};

int main() {
	cout << "This is displayed before the object is created." << endl;
	Demo demoObj;
	cout << "This is displayed after the object is created." << endl;
	return 0;
}