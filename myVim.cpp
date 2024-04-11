#include "myVim.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

myVim::myVim() {
    currentRow = 0;
    currentCol = 0;
}


void myVim::openFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line); // 将文件的每一行添加到 lines 向量中
        }
        file.close();
        currentFilename = filename;
        
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void myVim::displayFileContents() {
    cout << "\033[1;1H";
    for (size_t i = 0; i < lines.size(); ++i) {
        cout << lines[i] << endl;
    }
    cout << "\033[1;1H";
}


void myVim::saveFile() {
    if (currentFilename.empty()) {
        cout << "当前无打开的文件" << endl;
        return;
    }

    ofstream file(currentFilename);
    if (file.is_open()) {
        for (const auto& line : lines) {
            file << line << endl;
        }
        file.close();
        
    }
    else {
        cout << "无法打开文件" << currentFilename << endl;
    }
}

void myVim::editText() {
    if (currentFilename.empty()) {
        cout << "当前无打开的文件" << endl;
        return;
    }

    keySolution();
}

void myVim::keySolution(){
    // 无限循环，捕获键盘输入并移动光标
    while (true) {
        int key = _getch(); // 获取键盘输入
        if (key == 224) {
            key = _getch();
            // 根据不同的方向键，移动光标
            switch (key) {
            case 72: // 上箭头键
                if (currentRow > 0) currentRow--; // 避免光标移动到屏幕上方之外
                break;
            case 80: // 下箭头键
                currentRow++; // 无需边界检查
                break;
            case 75: // 左箭头键
                if (currentCol > 0) currentCol--; // 避免光标移动到屏幕左侧之外
                break;
            case 77: // 右箭头键
                currentCol++; // 无需边界检查
                break;
            default:
                // 忽略其他键
                continue;

            }
        }
        //删除操作
        else if (key == 8) {
            //判定一行的合法范围
            
                del();
                system("cls");
                displayFileContents();
                currentCol--;
            
        }
        //保存文件
        else if (key == 19) {
            saveFile();
        }
        else {
            // 判断溢出
            if (currentRow >= lines.size()) continue;
            /*if (currentCol >= lines[currentRow].size()) currentCol = lines[currentRow].size();*/
           
            char ch = (char)key;
            lines[currentRow].insert(currentCol, 1, ch);
            currentCol ++;
            displayFileContents();
        }
        cout << "\033[" << currentRow + 1 << ";" << currentCol + 1 << "H"; // ANSI 转义序列，+1 是因为行列号从 1 开始
    
        

        
    }
}

void myVim::del() {
    if (currentCol > 0 && currentCol <= lines[currentRow].size()) {
        lines[currentRow].erase(lines[currentRow].begin() + currentCol - 1);
    }
}


