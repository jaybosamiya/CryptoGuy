#ifndef DECRYPTER_H
#define DECRYPTER_H

#include <string>
#include <vector>

namespace decrypter {
	extern std::string encrypted_string, key;
	void init();
	void run_all();
};

#endif
