// main.cpp
#include "GROUP.h"
#include "FileProcessor.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;

void displayGroupMenu() {
    cout << "Меню задания 1:\n";
    cout << "1. Создать группу\n";
    cout << "2. Удалить группу\n";
    cout << "3. Добавить студента в группу\n";
    cout << "4. Редактировать группу\n";
    cout << "5. Редактировать студента в группе\n";
    cout << "6. Удалить студента из группы\n";
    cout << "7. Добавить студента на определённую позицию в группе\n";
    cout << "8. Показать все группы\n";
    cout << "9. Показать студентов с баллом > 4.0\n";
    cout << "0. Назад в главное меню\n";
    cout << "Ваш выбор: ";
}

void displayFileMenu() {
    cout << "\nМеню работы с файлами:\n";
    cout << "1. Вывести текст из файла\n";
    cout << "2. Вывести текст с изменением порядка слов\n";
    cout << "0. Назад в главное меню\n";
    cout << "Выберите действие: ";
}

void displayMainMenu() {
    cout << "\nМеню:\n";
    cout << "1. Работа с группами\n";
    cout << "2. Работа с файлами\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
}

void displayAllGroups(const vector<GROUP>& groups) {
    if (groups.empty()) {
        cout << "Групп пока нет." << endl;
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

                        cout << "Введите название группы: ";
                        cin >> groupName;

                        cout << "Введите количество предметов: ";
                        cin >> subjectCount;
                        if (subjectCount <= 0) {
                            throw invalid_argument("Количество предметов должно быть больше нуля.");
                        }

                        subjects.resize(subjectCount);
                        cout << "Введите названия предметов: ";
                        for (string& subject : subjects) {
                            cin >> subject;
                        }

                        groups.emplace_back(groupName, subjects);
                        cout << "Группа создана." << endl;
                    }
                    else if (groupChoice == 2) {
                        int index;
                        cout << "Введите индекс группы для удаления: ";
                        cin >> index;
                        if (index < 1 || index > groups.size()) {
                            cout << "Индекс группы вне диапазона. Попробуйте снова." << endl;
                        }
                        else {
                            groups.erase(groups.begin() + (index - 1));
                            cout << "Группа удалена." << endl;
                        }
                    }
                    else if (groupChoice == 8) {
                        displayAllGroups(groups);
                    }
                    else if (groupChoice == 0) {
                        break;
                    }
                    else {
                        cout << "Неверный выбор. Попробуйте снова." << endl;
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
                        cout << "Введите имя входного файла: ";
                        cin >> inputFilename;

                        try {
                            ifstream inputFile(inputFilename);
                            if (!inputFile.is_open()) {
                                throw runtime_error("Не удалось открыть файл: " + inputFilename);
                            }

                            string line;
                            cout << "Содержимое файла:\n";
                            while (getline(inputFile, line)) {
                                cout << line << endl;
                            }
                            inputFile.close();
                        }
                        catch (const exception& e) {
                            cout << "Ошибка: " << e.what() << endl;
                        }
                    }
                    else if (fileChoice == 2) {
                        string inputFilename, outputFilename;
                        cout << "Введите имя входного файла: ";
                        cin >> inputFilename;
                        cout << "Введите имя выходного файла: ";
                        cin >> outputFilename;

                        try {
                            FileProcessor::processFile(inputFilename, outputFilename);
                            cout << "Файл обработан и сохранён как " << outputFilename << endl;
                        }
                        catch (const exception& e) {
                            cout << "Ошибка: " << e.what() << endl;
                        }
                    }
                    else if (fileChoice == 0) {
                        break;
                    }
                    else {
                        cout << "Неверный выбор. Попробуйте снова." << endl;
                    }
                }
            }
            else if (mainChoice == 0) {
                break;
            }
            else {
                cout << "Неверный выбор. Попробуйте снова." << endl;
            }
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }

    return 0;
}