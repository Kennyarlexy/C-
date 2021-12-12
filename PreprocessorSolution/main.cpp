#define FUNCTION(str1, str2) //this says, replace FUNCTION(str1, str2) with an empty space lol
#define INF 0
#define foreach(v, i) for(int i = 0; i < n; i++)
#define io cin >> 
#define toStr(str) #str


void minimum(int &minim, int num)
{
	if (num < minim) {
		minim = num;
	}
}

void maximum(int &maxim, int num)
{
	if (num > maxim) {
		maxim = num;
	}
}

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;

	return 0;
}