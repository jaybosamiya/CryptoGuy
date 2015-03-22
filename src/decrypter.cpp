#include "decrypter.h"
#include "generated_algos.h"

#include <iostream>

using namespace std;

namespace decrypter {

	string encrypted_string, key;

	typedef string(*DecryptionFunction)(string e); // should return name of encryption algo on empty input
	typedef string(*KeyedDecryptionFunction)(string e, string k); // should return name of encryption algo on empty input

	vector<DecryptionFunction> dfv;
	vector<KeyedDecryptionFunction> kdfv;

	void init() {
		dfv.push_back(Trivial);
		kdfv.push_back(Trivial_Keyed);
		kdfv.push_back(Affine);
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
			if ( decrypted_strings[i].size() != 0 ) {
				cout << decryption_algo[i] << ":\t" << decrypted_strings[i] << endl;
			}
		}
	}

};
