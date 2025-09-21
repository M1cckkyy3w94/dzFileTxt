#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string obrabotka(const string& word) {
    string s = "";
    for (int i = 0; i < word.size(); i++) {
        if (isalpha(word[i])) {
            s += tolower(word[i]);
        } 
    }

    if (s == "lazy") return "unmotivated";
    else if (s == "stupid") return "silly";
    else if (s == "terrible") return "big";
    else return word;
}

int zavd1() {
    ifstream fileTxt("text.txt");
    ofstream file("resZamina.txt");

    if (!fileTxt) {
        cout << "Error" << endl;
        return 1;
    }

    string lines;
    while (getline(fileTxt, lines)) {
        string word = "";
        for (int i = 0; i <= lines.size(); i++) {
            if (i < lines.size() && lines[i] != ' ') {
                word += lines[i];
            }
            else {
                if (!word.empty()) {
                    file << obrabotka(word) << " ";
                    word = "";
                }
            }
        }
        file << endl;
    }
    cout << "Неприйняті слова видалені і замінені!\n";
    fileTxt.close();
    file.close();
    ifstream filee("resZamina.txt");
    while (getline(filee, lines)) {
        cout << lines << endl;
    }
    filee.close();

    return 0;
}
