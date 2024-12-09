#include "STUDENT.h"
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <fstream>
using namespace std;

STUDENT::STUDENT() : surname("Unknown"), initials("Unknown"), grades() {}

STUDENT::STUDENT(const string& surname, const string& initials, const vector<int>& grades)
    : surname(surname), initials(initials), grades(grades) {}

void STUDENT::input() {
    cout << "������� �������: ";
    cin >> surname;
    cout << "������� ��������: ";
    cin >> initials;

    int gradeCount;
    cout << "������� ���������� ������: ";
    cin >> gradeCount;
    if (gradeCount <= 0) {
        throw invalid_argument("���������� ������ ������ ���� ������ ����.");
    }

    grades.resize(gradeCount);
    cout << "������� ������: ";
    for (int& grade : grades) {
        cin >> grade;
        if (grade < 0 || grade > 5) {
            throw invalid_argument("������ ������ ���� � ��������� �� 0 �� 5.");
        }
    }
}

void STUDENT::output() const {
    cout << "�������: " << surname << ", ��������: " << initials
        << ", ������: ";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << ", ������� ����: " << getAverageGrade() << endl;
}

float STUDENT::getAverageGrade() const {
    if (grades.empty()) return 0.0f;
    return accumulate(grades.begin(), grades.end(), 0.0f) / grades.size();
}

const string& STUDENT::getSurname() const {
    return surname;
}

ostream& operator<<(ostream& os, const STUDENT& student) {
    os << student.surname << " " << student.initials << " ";
    os << student.grades.size() << " ";
    for (int grade : student.grades) {
        os << grade << " ";
    }
    return os;
}

istream& operator>>(istream& is, STUDENT& student) {
    size_t gradeCount;
    is >> student.surname >> student.initials >> gradeCount;
    if (gradeCount <= 0) {
        throw invalid_argument("���������� ������ ������ ���� ������ ����.");
    }
    student.grades.resize(gradeCount);
    for (int& grade : student.grades) {
        is >> grade;
        if (grade < 0 || grade > 5) {
            throw invalid_argument("������ ������ ���� � ��������� �� 0 �� 5.");
        }
    }
    return is;
}