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

int modPow(int a, int b, int MOD) {
	int x = 1, y = a;
	while(b > 0) {
		if(b%2 == 1) {
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD;
			b /= 2;
	}
	return x;
}
 
int modInverse(int a, int m) {
    a %= m;
    for(int x = 1; x < m; x++) {
        if((a*x) % m == 1) return x;
    }
    return -1;
}
