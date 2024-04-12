#include <iostream>
#include <conio.h> // 包含 _getch() 函数用于捕获键盘输入
#include "myVim.h"
using namespace std;

int main() {
    
    myVim myvim;
    string fileName;
    cout << "输入文件名或文件路径：" << endl;
    cin >> fileName;
    
    system("cls");
    myvim.openFile(fileName);
    myvim.displayFileContents();
    myvim.editText();
 
    return 0;
}

