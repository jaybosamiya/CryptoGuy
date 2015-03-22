#include "util.h"

#include <sstream>

using namespace std;

vector<int> read_ints(string s) {
	istringstream ss(s);
	vector<int> ret;
	int temp;
	while ( ss >> temp ) {
		ret.push_back(temp);
	}
	return ret;
}
