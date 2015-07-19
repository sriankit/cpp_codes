#include <bits/stdc++.h>
using namespace std;

int n, p;
string s;

int make(int i, int st) {
	if(i == n) return 1;
	for (int ch = st; ch < p; ++ch)
	{
		char c = ch + 'a';
		if(i > 0 and c == s[i - 1]) continue;
		if(i > 1 and c == s[i - 2]) continue;
		s[i] = c;
		return make(i + 1, 0);	
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	cin >> n >> p;
	cin >> s;
	bool flag = true;
	for (int i = n - 1; i >= 0; --i)
	{	
		string buf = s;
		if(make(i, s[i] - 'a' + 1)) {
			cout << s;			
			flag = false;
			break;
		}
		s = buf;		
	}
	if(flag) puts("NO");
	return 0;
}