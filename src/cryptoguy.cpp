#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace decrypter {
	string encrypted_string, key;
	void run_all();
};

int main(int argc, char ** argv) {
	if ( argc == 1 ) {
		cerr << "Usage: " << argv[0] << " encoded_form [possible_key]\n";
		return 0;
	}
	decrypter::encrypted_string = string(argv[1]);
	if ( argc > 2 ) {
		decrypter::key = string(argv[2]);
	}

	decrypter::run_all();

	return 0;
}

namespace decrypter {

	typedef string(*DecryptionFunction)(string); // should return name of encryption algo on empty input
	typedef string(*KeyedDecryptionFunction)(string,string); // should return name of encryption algo on empty input

	vector<DecryptionFunction> dfv;
	vector<KeyedDecryptionFunction> kdfv;

	void init() {
		// dfv.push_back(/*function*/);
		// kdfv.push_back(/*function*/);
	}

	void run_all() {
		vector<string> decrypted_strings;
		vector<string> decryption_algo;
		if ( key.empty() ) {
			for ( vector<DecryptionFunction>::iterator it = dfv.begin() ; it != dfv.end() ; it++ ) {
				decryption_algo.push_back((*it)(string()));
				decrypted_strings.push_back((*it)(encrypted_string));
			}
		} else {
			for ( vector<KeyedDecryptionFunction>::iterator it = kdfv.begin() ; it != kdfv.end() ; it++ ) {
				decryption_algo.push_back((*it)(string(),string()));
				decrypted_strings.push_back((*it)(encrypted_string,key));
			}
		}
	}

};
