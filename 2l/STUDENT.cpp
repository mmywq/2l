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
    cout << "Введите фамилию: ";
    cin >> surname;
    cout << "Введите инициалы: ";
    cin >> initials;

    int gradeCount;
    cout << "Введите количество оценок: ";
    cin >> gradeCount;
    if (gradeCount <= 0) {
        throw invalid_argument("Количество оценок должно быть больше нуля.");
    }

    grades.resize(gradeCount);
    cout << "Введите оценки: ";
    for (int& grade : grades) {
        cin >> grade;
        if (grade < 0 || grade > 5) {
            throw invalid_argument("Оценки должны быть в диапазоне от 0 до 5.");
        }
    }
}

void STUDENT::output() const {
    cout << "Фамилия: " << surname << ", Инициалы: " << initials
        << ", Оценки: ";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << ", Средний балл: " << getAverageGrade() << endl;
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
        throw invalid_argument("Количество оценок должно быть больше нуля.");
    }
    student.grades.resize(gradeCount);
    for (int& grade : student.grades) {
        is >> grade;
        if (grade < 0 || grade > 5) {
            throw invalid_argument("Оценки должны быть в диапазоне от 0 до 5.");
        }
    }
    return is;
}