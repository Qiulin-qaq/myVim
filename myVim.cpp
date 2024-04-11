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
            lines.push_back(line); // ���ļ���ÿһ����ӵ� lines ������
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
        cout << "��ǰ�޴򿪵��ļ�" << endl;
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
        cout << "�޷����ļ�" << currentFilename << endl;
    }
}

void myVim::editText() {
    if (currentFilename.empty()) {
        cout << "��ǰ�޴򿪵��ļ�" << endl;
        return;
    }

    keySolution();
}

void myVim::keySolution(){
    // ����ѭ��������������벢�ƶ����
    while (true) {
        int key = _getch(); // ��ȡ��������
        if (key == 224) {
            key = _getch();
            // ���ݲ�ͬ�ķ�������ƶ����
            switch (key) {
            case 72: // �ϼ�ͷ��
                if (currentRow > 0) currentRow--; // �������ƶ�����Ļ�Ϸ�֮��
                break;
            case 80: // �¼�ͷ��
                currentRow++; // ����߽���
                break;
            case 75: // ���ͷ��
                if (currentCol > 0) currentCol--; // �������ƶ�����Ļ���֮��
                break;
            case 77: // �Ҽ�ͷ��
                currentCol++; // ����߽���
                break;
            default:
                // ����������
                continue;

            }
        }
        //ɾ������
        else if (key == 8) {
            //�ж�һ�еĺϷ���Χ
            
                del();
                system("cls");
                displayFileContents();
                currentCol--;
            
        }
        //�����ļ�
        else if (key == 19) {
            saveFile();
        }
        else {
            // �ж����
            if (currentRow >= lines.size()) continue;
            /*if (currentCol >= lines[currentRow].size()) currentCol = lines[currentRow].size();*/
           
            char ch = (char)key;
            lines[currentRow].insert(currentCol, 1, ch);
            currentCol ++;
            displayFileContents();
        }
        cout << "\033[" << currentRow + 1 << ";" << currentCol + 1 << "H"; // ANSI ת�����У�+1 ����Ϊ���кŴ� 1 ��ʼ
    
        

        
    }
}

void myVim::del() {
    if (currentCol > 0 && currentCol <= lines[currentRow].size()) {
        lines[currentRow].erase(lines[currentRow].begin() + currentCol - 1);
    }
}


