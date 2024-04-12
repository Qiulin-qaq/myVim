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

//��ӡ���
void myVim::displayFileContents() {
    cout << "\033[1;1H";
    for (size_t i = 0; i < lines.size(); ++i) {
        cout << lines[i] << endl;
    }
    cout << "\033[1;1H";
}

//�����ļ�
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
        //�˳��༭������
        else if (key == 27) {
            system("cls");
            cout << "���˳��༭��" << endl;
            return;
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
            system("cls");
            cout << "�ļ��ѱ���" << endl;
        }
       
        //TODU:��������

        else if (key == 26) {
            revoke();
        }
        else {
            // �ж����
            if (currentRow >= lines.size()) continue;
            
           
            char ch = (char)key;
            if (key == 13) {
                string temp = lines[currentRow].substr(currentCol);
                lines[currentRow].erase(currentCol);
                lines.insert(lines.begin() + currentRow + 1, temp);

                currentRow++;
                currentCol = 0;
                system("cls");
                displayFileContents();
                
            }
            else {
                lines[currentRow].insert(currentCol, 1, ch);
                currentCol++;
                displayFileContents();
            }
        }
        cout << "\033[" << currentRow + 1 << ";" << currentCol + 1 << "H"; // ANSI ת�����У�+1 ����Ϊ���кŴ� 1 ��ʼ
    
        

        
    }
}

void myVim::del() {
    if (currentCol > 0 && currentCol <= lines[currentRow].size()) {
        lines[currentRow].erase(lines[currentRow].begin() + currentCol - 1);
    }
}

void myVim::revoke(){



}


