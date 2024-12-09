#pragma once
#include <iostream>
#include <string>
#include <vector>

class STUDENT {
private:
    std::string surname;
    std::string initials;
    std::vector<int> grades;

public:
    STUDENT();
    STUDENT(const std::string& surname, const std::string& initials, const std::vector<int>& grades);

    void input();
    void output() const;

    float getAverageGrade() const;
    const std::string& getSurname() const;

    friend std::ostream& operator<<(std::ostream& os, const STUDENT& student);
    friend std::istream& operator>>(std::istream& is, STUDENT& student);
};
