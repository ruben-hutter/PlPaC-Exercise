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

enum Canids_Common_Name {
	Golden_jackal,
	Dog,
	Coyote,
	African_wolf,
	Wolf,
	Red_wolf,
	Ethiopian_wolf
} commonName;

// takes a Canids and prints his common name
void canidsCommonName(Canids c) {
	Canids_Common_Name cmn_name;
	cout << cmn_name << endl;
}

int main() {
	Canids c = Canis_Familiaris;
	//canidsCommonName(c);
	return 0;
}

