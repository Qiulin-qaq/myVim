#include "myVim.h"
#include<iostream>
#include <conio.h>

using namespace std;

//�����ַ�
void myVim::insert(char ch) {
	
	
	// ���ַ����뵽��ǰ���λ��
	lines[currentRow].insert(lines[currentRow].begin() + currentColumn, ch);
	
	currentColumn++;

	cout << ch;

	
}


//ɾ���ַ�
void myVim::del(string str) {
	if (currentColumn > 0) {
		lines[currentRow].erase(lines[currentRow].begin() + currentColumn - 1);
		currentColumn--;
	}
	// TODO: ������������ʱ��ɾ�����
}



//����ƶ�
void myVim::moveCursor(int x, int y){
	std::cout << "\033[" << y << ";" << x << "H";
}

//�ж��ƶ�����
void myVim::judgeMove() {
	int x = 0;
	int y = 3;
	moveCursor(x, y);
	while (true) {
		int ch = _getch();
		//esc
		if (ch == 27) return;
		//�������Ҽ�
		if (ch == 224) {
			ch = _getch();
			switch (ch) {
			//�����ƶ�
			case 72:
				if (y > 1) {
					moveCursor(x, --y);
				}
				break;
			//�����ƶ�
			case 80:
				moveCursor(x, ++y);
				break;
			//�����ƶ�
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