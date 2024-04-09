#include <iostream>
#include <conio.h> // 使用 _getch() 函数
#include "myVim.h" // 导入 Vim 编辑器类的头文件

using namespace std;

int main() {
    myVim editor; // 创建一个 Vim 编辑器对象

    
        

    // 显示编辑器标题
    cout << "=== Simple Vim Editor ===" << endl << endl;
       

    // 处理特殊键值
    editor.judgeMove();

       
        
   

    return 0;
}
