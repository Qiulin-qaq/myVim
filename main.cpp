#include <iostream>
#include <conio.h> // ���� _getch() �������ڲ����������
#include "myVim.h"
using namespace std;

int main() {
    
    myVim myvim;
    string fileName;
    cout << "�����ļ������ļ�·����" << endl;
    cin >> fileName;
    
    system("cls");
    myvim.openFile(fileName);
    myvim.displayFileContents();
    myvim.editText();
 
    return 0;
}

