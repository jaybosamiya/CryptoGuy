#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace decrypter {
	string encrypted_string, key;
	void init();
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

	decrypter::init();
	decrypter::run_all();

	return 0;
}

namespace decrypter {

	typedef string(*DecryptionFunction)(string e); // should return name of encryption algo on empty input
	typedef string(*KeyedDecryptionFunction)(string e, string k); // should return name of encryption algo on empty input

	vector<DecryptionFunction> dfv;
	vector<KeyedDecryptionFunction> kdfv;

	string trivial_decryption (string e) {
		if ( e.empty() )
			return "Trivial";
		return e;
	}

	string trivial_keyed_decryption (string e, string k) {
		if ( e.empty() )
			return "Trivial Keyed";
		return e+k;
	}

	void init() {
		dfv.push_back(trivial_decryption);
		kdfv.push_back(trivial_keyed_decryption);
	}

	void output_all(vector<string> decryption_algo, vector<string> decrypted_strings);

	void run_all() {
		vector<string> decrypted_strings;
		vector<string> decryption_algo;
		if ( key.empty() ) {
			for ( vector<DecryptionFunction>::iterator it = dfv.begin() ; it != dfv.end() ; it++ ) {
				decryption_algo.push_back((*it)(string()));
				decrypted_strings.push_back((*it)(encrypted_string));
			}
			output_all(decryption_algo,decrypted_strings);
		} else {
			for ( vector<KeyedDecryptionFunction>::iterator it = kdfv.begin() ; it != kdfv.end() ; it++ ) {
				decryption_algo.push_back((*it)(string(),string()));
				decrypted_strings.push_back((*it)(encrypted_string,key));
			}
			output_all(decryption_algo,decrypted_strings);
		}
	}

	void output_all(vector<string> decryption_algo, vector<string> decrypted_strings) {
		for ( int i = 0 ; i < (int)decrypted_strings.size() ; i++ ) {
			cout << decryption_algo[i] << ":\t" << decrypted_strings[i] << endl;
		}
	}

};
