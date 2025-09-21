#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <vector>

#include "dzFileTxt.h"


using namespace std;

struct Transliteration {
    string rus;
    string eng;
};

Transliteration rusEngl[] = {
    {"�","a"}, {"�","b"}, {"�","v"}, {"�","g"}, {"�","d"},
    {"�","e"}, {"�","yo"}, {"�","zh"}, {"�","z"}, {"�","i"},
    {"�","y"}, {"�","k"}, {"�","l"}, {"�","m"}, {"�","n"},
    {"�","o"}, {"�","p"}, {"�","r"}, {"�","s"}, {"�","t"},
    {"�","u"}, {"�","f"}, {"�","kh"}, {"�","ts"}, {"�","ch"},
    {"�","sh"}, {"�","shch"}, {"�","y"}, {"�","e"}, {"�","yu"},
    {"�","ya"}, {"�",""}, {"�",""}
};

string transRustoEng(const string& text) {
    int sizee = sizeof(rusEngl) / sizeof(rusEngl[0]);
    string res = "";
    for (char c : text) {
        int mode = 0;
        for (int i = 0; i < sizee; i++) {
            if (c == rusEngl[i].rus[0]) {
                res += rusEngl[i].eng;
                mode = 1;
                break;
            }
        }
        if (mode == 0) res += c;
    }
    return res;
}

string transEngtoRus(const string& text) {
    int sizee = sizeof(rusEngl) / sizeof(rusEngl[0]);
    string res = "";
    for (char c : text) {
        int mode = 0;
        for (int i = 0; i < sizee; i++) {
            if (c == rusEngl[i].eng[0]) {
                res += rusEngl[i].rus;
                mode = 1;
                break;
            }
        }
        if (mode == 0) res += c;
    }
    return res;
}

int zavd2()
{
    system("chcp 1251>null");
    cout << "����: \n[1]�������� -> ���������\n[2]��������� -> ��������\n��� ����: ";
    int choice;
    cin >> choice;
    ifstream file("transl.txt");
    ofstream file2("RusToEng.txt");
    ofstream file3("EngToRus.txt");
    switch (choice) {
    case 1: {
        string line;
        while (getline(file, line)) {
            string lines = transRustoEng(line);
            file2<<lines<<endl;
        }
        cout << "������������� ������!";
        break;
    }
    case 2: {
        string line;
        while (getline(file, line)) {
            string lines = transEngtoRus(line);
            file3 << lines << endl;
        }
        cout << "������������� ������!";
        break;
    }
    default: cout << "Error"; break;
    }


    file.close();
    file2.close();
    return 0;
}
