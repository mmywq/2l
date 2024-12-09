#pragma once
#include "STUDENT.h"
#include <vector>
#include <string>

class GROUP {
private:
    std::vector<STUDENT> students;
    std::string groupName;
    std::vector<std::string> subjects;

public:
    GROUP();
    GROUP(const std::string& groupName, const std::vector<std::string>& subjects);

    void addStudent(const STUDENT& student);
    void removeStudent(int index);
    void editStudent(int index);
    void insertStudentAtPosition(const STUDENT& student, int position);

    void displayAll() const;
    void displayHighAchievers() const;
    void sortByGroup();

    std::string getGroupName() const;
};
