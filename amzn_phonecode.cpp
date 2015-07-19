/* Ankit Srivastava */
#include <bits/stdc++.h>
using namespace std;
int find_match(char c) {
	c = tolower(c);
	//             a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z 
	int match[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};	
	return match[c - 'a'];
}
int decode(string s)
{
	int ret = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ret *= 10;
		ret += find_match(s[i]);
	}
	return ret;
}
bool comp(string s1, string s2) 
{
	int d1 = decode(s1);
	int d2 = decode(s2);
	if(d1 == d2) return s1 < s2;
	else return d1 >= d2; 
}
int main() 
{
	std::vector<string> v;	
	//char s[][5] = {"ABC", "DEF", "XY", "XYZ", "DB", "FB", "PQRS", "PBR"};
	int n = 3;
	//scanf("%d", &n);
	char s[][10] = {"Amazon", "sun", "run"};
	for (int i = 0; i < n; ++i)
	{
		v.push_back(string(s[i]));
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; ++i)
	{
		cout << decode(v[i]) << "  " << v[i] << endl;
	}
	return 0;
}