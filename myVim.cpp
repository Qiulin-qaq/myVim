#include "myVim.h"
#include<iostream>
#include <conio.h>

using namespace std;

//插入字符
void myVim::insert(char ch) {
	
	
	// 将字符插入到当前光标位置
	lines[currentRow].insert(lines[currentRow].begin() + currentColumn, ch);
	
	currentColumn++;

	cout << ch;

	
}


//删除字符
void myVim::del(string str) {
	if (currentColumn > 0) {
		lines[currentRow].erase(lines[currentRow].begin() + currentColumn - 1);
		currentColumn--;
	}
	// TODO: 补充光标在行首时的删除情况
}



//光标移动
void myVim::moveCursor(int x, int y){
	std::cout << "\033[" << y << ";" << x << "H";
}

//判断移动方向
void myVim::judgeMove() {
	int x = 0;
	int y = 3;
	moveCursor(x, y);
	while (true) {
		int ch = _getch();
		//esc
		if (ch == 27) return;
		//上下左右键
		if (ch == 224) {
			ch = _getch();
			switch (ch) {
			//向上移动
			case 72:
				if (y > 1) {
					moveCursor(x, --y);
				}
				break;
			//向下移动
			case 80:
				moveCursor(x, ++y);
				break;
			//向左移动
			case 75:
				if (x > 1) {
					moveCursor(--x, y);
				}
					break;
			case 77:
				if (x < 100) {
					moveCursor(++x, y);
					break;
				}
				
			}
		
		}
		else if (ch == 13) {
			lines.push_back("");
			moveCursor(0, ++y);
			currentRow++;
			currentColumn = 0;
		}
		else {
			insert(ch);
		}
	}
}

void myVim::print() {
	for (const auto& e : lines) {
		cout << e;
	}
	

}