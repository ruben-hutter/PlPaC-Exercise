#include <iostream>
#include <string>

using namespace std;

enum Canids {
	Canis_Aureus,
	Canis_Familiaris,
	Canis_Latrans,
	Canis_Lupaster,
	Canis_Lupus,
	Canis_Rufus,
	Canis_Simensis
};

// takes a Canids and prints his common name
void canidsCommonName(Canids c) {
	string commonName;
	switch(c) {
		case 0:
			commonName = "Golden Jackal";
			break;
		case 1: // you can also write Canis_Familiaris
			commonName = "Dog";
			break;
		case 2:
			commonName = "Coyote";
			break;
		case 3:
			commonName = "African Wolf";
			break;
		case 4:
			commonName = "Wolf";
			break;
		case 5:
			commonName = "Red Wolf";
			break;
		case 6:
			commonName = "Ethiopian Wolf";
			break;
	}
	cout << commonName << endl;
}

int main() {
	Canids c = Canis_Familiaris;
	canidsCommonName(c);
	return 0;
}

