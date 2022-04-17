#include <iostream>
#include <string>

using namespace std;

// enum with canids names
enum Canids {
	Canis_Aureus,
	Canis_Familiaris,
	Canis_Latrans,
	Canis_Lupaster,
	Canis_Lupus,
	Canis_Rufus,
	Canis_Simensis
};

// array with canids common names
static const string canidsNormalNames[] = {
	"Golden Jackal",
	"Dog",
	"Coyote",
	"African Wolf",
	"Wolf",
	"Red Wolf",
	"Ethiopian Wolf"
};

// takes a Canids and prints his common name
void canidsCommonName(Canids c) {
	cout << canidsNormalNames[c] << endl;
}

int main() {
	Canids c = Canis_Familiaris;
	canidsCommonName(c);
	return 0;
}

