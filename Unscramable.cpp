#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include <list>
#include <map>
#include <iterator>
#define MOD 100000007
#define sizee 61336
using namespace std;

long long pow(long long a)
{
	return a * a;
}

int value(string s)
{
	int sum = 0, power = 0, product = 1, count = s.length();
	for (int i = 0; i < count; i++)
	{
		int v = s[i] - 95;
		sum += v;
		product = (product * v) % MOD;
		power += pow(v);
	}
	return pow(sum) % MOD + pow(product) % MOD + pow(power) % MOD + count;
}

int main()
{
	map<int, vector<string>> p;
	map<int, vector<string>> ::iterator itr;
	fstream f, ff;
	f.open("word.txt", ios::in);
	string s;
	for (int i = 0; i < sizee; ++i)
	{
		getline(f, s);
		int v = value(s);
		itr = p.find(v);
		if (itr == p.end())
		{
			vector<string> word;
			word.push_back(s);
			p.insert(pair<int, vector<string>>(v, word));
		}
		else
		{
			itr->second.push_back(s);
		}
	}
	f.close();
	ff.open("word.output", ios::out);
	for (itr = p.begin(); itr != p.end(); ++itr)
	{
		
		if (itr->second.size() > 1)
		{
			ff << itr->first << ": ";
			for (int j = 0; j < itr->second.size(); ++j)
				ff << itr->second[j] << " ";
			ff << endl;
		}
	}
	ff.close();
	return 0;

}

