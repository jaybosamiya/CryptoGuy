#include <iostream>
#include <string>
#include <vector>
#include "decrypter.h"

using namespace std;

int main(int argc, char ** argv) {
	if ( argc == 1 ) {
		cerr << "Usage: " << argv[0] << " encoded_form [possible_key]\n";
		return 0;
	}
	decrypter::encrypted_string = string(argv[1]);
	if ( argc > 2 ) {
		decrypter::key = string(argv[2]);
	}

	decrypter::init();
	decrypter::run_all();

	return 0;
}

