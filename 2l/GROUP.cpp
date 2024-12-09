#include "GROUP.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

GROUP::GROUP() : groupName("Unknown"), subjects() {}

GROUP::GROUP(const string& groupName, const vector<string>& subjects)
    : groupName(groupName), subjects(subjects) {}

void GROUP::addStudent(const STUDENT& student) {
    students.push_back(student);
}

void GROUP::removeStudent(int index) {
    if (index < 0 || index >= students.size()) {
        throw out_of_range("������ ��� ���������");
    }
    students.erase(students.begin() + index);
}

void GROUP::editStudent(int index) {
    if (index < 0 || index >= students.size()) {
        throw out_of_range("������ ��� ���������");
    }
    students[index].input();
}

void GROUP::displayAll() const {
    for (const auto& student : students) {
        student.output();
    }
}

void GROUP::displayHighAchievers() const {
    bool found = false;
    for (const auto& student : students) {
        if (student.getAverageGrade() > 4.0) {
            cout << student.getSurname() << ", ������: " << groupName << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "��� ��������� �� ������� ������ ���� 4.0" << endl;
    }
}

void GROUP::insertStudentAtPosition(const STUDENT& student, int position) {
    if (position < 0 || position > students.size()) {
        throw out_of_range("������ ��� ���������");
    }
    students.insert(students.begin() + position, student);
}

void GROUP::sortByGroup() {
    sort(students.begin(), students.end(), [](const STUDENT& a, const STUDENT& b) {
        return a.getSurname() < b.getSurname();
        });
}
