// main.cpp
#include "GROUP.h"
#include "FileProcessor.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;

void displayGroupMenu() {
    cout << "���� ������� 1:\n";
    cout << "1. ������� ������\n";
    cout << "2. ������� ������\n";
    cout << "3. �������� �������� � ������\n";
    cout << "4. ������������� ������\n";
    cout << "5. ������������� �������� � ������\n";
    cout << "6. ������� �������� �� ������\n";
    cout << "7. �������� �������� �� ����������� ������� � ������\n";
    cout << "8. �������� ��� ������\n";
    cout << "9. �������� ��������� � ������ > 4.0\n";
    cout << "0. ����� � ������� ����\n";
    cout << "��� �����: ";
}

void displayFileMenu() {
    cout << "\n���� ������ � �������:\n";
    cout << "1. ������� ����� �� �����\n";
    cout << "2. ������� ����� � ���������� ������� ����\n";
    cout << "0. ����� � ������� ����\n";
    cout << "�������� ��������: ";
}

void displayMainMenu() {
    cout << "\n����:\n";
    cout << "1. ������ � ��������\n";
    cout << "2. ������ � �������\n";
    cout << "0. �����\n";
    cout << "�������� ��������: ";
}

void displayAllGroups(const vector<GROUP>& groups) {
    if (groups.empty()) {
        cout << "����� ���� ���." << endl;
        return;
    }
    for (size_t i = 0; i < groups.size(); ++i) {
        cout << i + 1 << ". " << groups[i].getGroupName() << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<GROUP> groups;
    int mainChoice;

    while (true) {
        displayMainMenu();
        cin >> mainChoice;

        try {
            if (mainChoice == 1) {
                int groupChoice;
                while (true) {
                    displayGroupMenu();
                    cin >> groupChoice;

                    if (groupChoice == 1) {
                        string groupName;
                        vector<string> subjects;
                        int subjectCount;

                        cout << "������� �������� ������: ";
                        cin >> groupName;

                        cout << "������� ���������� ���������: ";
                        cin >> subjectCount;
                        if (subjectCount <= 0) {
                            throw invalid_argument("���������� ��������� ������ ���� ������ ����.");
                        }

                        subjects.resize(subjectCount);
                        cout << "������� �������� ���������: ";
                        for (string& subject : subjects) {
                            cin >> subject;
                        }

                        groups.emplace_back(groupName, subjects);
                        cout << "������ �������." << endl;
                    }
                    else if (groupChoice == 2) {
                        int index;
                        cout << "������� ������ ������ ��� ��������: ";
                        cin >> index;
                        if (index < 1 || index > groups.size()) {
                            cout << "������ ������ ��� ���������. ���������� �����." << endl;
                        }
                        else {
                            groups.erase(groups.begin() + (index - 1));
                            cout << "������ �������." << endl;
                        }
                    }
                    else if (groupChoice == 8) {
                        displayAllGroups(groups);
                    }
                    else if (groupChoice == 0) {
                        break;
                    }
                    else {
                        cout << "�������� �����. ���������� �����." << endl;
                    }
                }
            }
            else if (mainChoice == 2) {
                int fileChoice;
                while (true) {
                    displayFileMenu();
                    cin >> fileChoice;

                    if (fileChoice == 1) {
                        string inputFilename;
                        cout << "������� ��� �������� �����: ";
                        cin >> inputFilename;

                        try {
                            ifstream inputFile(inputFilename);
                            if (!inputFile.is_open()) {
                                throw runtime_error("�� ������� ������� ����: " + inputFilename);
                            }

                            string line;
                            cout << "���������� �����:\n";
                            while (getline(inputFile, line)) {
                                cout << line << endl;
                            }
                            inputFile.close();
                        }
                        catch (const exception& e) {
                            cout << "������: " << e.what() << endl;
                        }
                    }
                    else if (fileChoice == 2) {
                        string inputFilename, outputFilename;
                        cout << "������� ��� �������� �����: ";
                        cin >> inputFilename;
                        cout << "������� ��� ��������� �����: ";
                        cin >> outputFilename;

                        try {
                            FileProcessor::processFile(inputFilename, outputFilename);
                            cout << "���� ��������� � ������� ��� " << outputFilename << endl;
                        }
                        catch (const exception& e) {
                            cout << "������: " << e.what() << endl;
                        }
                    }
                    else if (fileChoice == 0) {
                        break;
                    }
                    else {
                        cout << "�������� �����. ���������� �����." << endl;
                    }
                }
            }
            else if (mainChoice == 0) {
                break;
            }
            else {
                cout << "�������� �����. ���������� �����." << endl;
            }
        }
        catch (const exception& e) {
            cout << "������: " << e.what() << endl;
        }
    }

    return 0;
}