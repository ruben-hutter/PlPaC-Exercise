#include <string>
#include <iostream>

using namespace std;

// enum with canids names
enum Canids {
	Canis_aureus,
	Canis_familiaris,
	Canis_latrans,
	Canis_lupaster,
	Canis_lupus,
	Canis_rufus,
	Canis_simensis
};

// array with canids common name
static const char *canids_normal_name[] = {
	"Golden_jackal",
	"Dog",
	"Coyote",
	"African_wolf",
	"Wolf",
	"Red_wolf",
	"Ethiopian_wolf"
};

// method to print common names of species
void canidsCommonName(int canid_val) {
	cout << canids_normal_name[canid_val] << endl;
}

int main() {
	Canids c = Canis_familiaris;
	canidsCommonName(c);
	return 0;
}
