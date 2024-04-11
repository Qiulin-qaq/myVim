#pragma once
#include<vector>
#include<string>
using namespace std;

class myVim {
public:
    myVim();

    void openFile(const string& filename);
    void displayFileContents();
    void saveFile();
    void editText();
    void keySolution();
    void del();
    

private:
    vector<string> lines;
    string currentFilename;
    int currentRow;
    int currentCol;
};


