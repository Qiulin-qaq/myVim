#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VimEditor {
private:
    vector<string> lines;
    size_t currentRow;
    size_t currentColumn;

public:
    VimEditor() : currentRow(0), currentColumn(0) {}

    void insert(char c) {
        lines[currentRow].insert(lines[currentRow].begin() + currentColumn, c);
        currentColumn++;
    }

    void remove() {
        if (currentColumn > 0) {
            lines[currentRow].erase(lines[currentRow].begin() + currentColumn - 1);
            currentColumn--;
        }
        else if (currentRow > 0) {
            size_t prevRowLength = lines[currentRow - 1].size();
            lines[currentRow - 1].append(lines[currentRow]);
            lines.erase(lines.begin() + currentRow);
            currentRow--;
            currentColumn = prevRowLength;
        }
    }

    void moveCursorLeft() {
        if (currentColumn > 0) {
            currentColumn--;
        }
        else if (currentRow > 0) {
            currentRow--;
            currentColumn = lines[currentRow].size();
        }
    }

    void moveCursorRight() {
        if (currentColumn < lines[currentRow].size()) {
            currentColumn++;
        }
        else if (currentRow < lines.size() - 1) {
            currentRow++;
            currentColumn = 0;
        }
    }

    void moveCursorUp() {
        if (currentRow > 0) {
            currentRow--;
            if (currentColumn > lines[currentRow].size()) {
                currentColumn = lines[currentRow].size();
            }
        }
    }

    void moveCursorDown() {
        if (currentRow < lines.size() - 1) {
            currentRow++;
            if (currentColumn > lines[currentRow].size()) {
                currentColumn = lines[currentRow].size();
            }
        }
    }

    void print() const {
        for (const auto& line : lines) {
            cout << line << endl;
        }
    }
};

int main() {
    VimEditor editor;

    editor.insert('H');
    editor.insert('e');
    editor.insert('l');
    editor.insert('l');
    editor.insert('o');
    editor.print(); // 输出: Hello

    editor.moveCursorLeft();
    editor.remove();
    editor.print(); // 输出: Hell

    editor.insert('!');
    editor.print(); // 输出: Hell!

    editor.moveCursorRight();
    editor.insert('o');
    editor.print(); // 输出: Hello!

    return 0;
}
