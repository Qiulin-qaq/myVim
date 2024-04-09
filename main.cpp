#include<iostream>
#include"myVim.h"
using namespace std;

int main() {
	myVim myvim;
	string str;
	getline(cin, str);
	for (auto e : str) {
		myvim.insert(e);
	}
	myvim.print();
	myvim.judgeMove();
	myvim.print();
	return 0;
}


