/*https://www.hackerrank.com/challenges/prettyprint/problem?isFullScreen=true

Guide :
https://www.geeksforgeeks.org/formatted-i-o-in-c/
*/

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		cout.unsetf(ios::internal);
		cout << setw(0) << nouppercase << showbase << hex << (long long)A << endl;
		cout << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << B << endl;
		cout.fill(' ');
		cout.unsetf(ios::showpos);
		cout << uppercase << fixed << setprecision(9) << scientific << C << endl;
		cout.unsetf(ios::scientific);

	}
	return 0;
}