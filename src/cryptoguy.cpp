#include <iostream>
#include <string>

using namespace std;

int main(int argc, char ** argv) {
	string enc, key;
	if ( argc == 1 ) {
		cerr << "Usage: " << argv[0] << " encoded_form [possible_key]\n";
		return 0;
	}
	enc = string(argv[1]);
	if ( argc > 2 ) {
		key = string(argv[2]);
	}

	// TODO: Run decoding algos

	return 0;
}
