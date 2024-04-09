#pragma once
#include<vector>
#include<string>


using namespace std;
class myVim{
private:
	vector<string> lines;
	size_t currentRow;
	size_t currentColumn;

public:
	myVim() :currentRow(0), currentColumn(0) {
		lines.push_back("");
	}
	void insert(char ch);
	void del(string str);
	void moveCursor(int x, int y);
	void judgeMove();
	void print();
};

