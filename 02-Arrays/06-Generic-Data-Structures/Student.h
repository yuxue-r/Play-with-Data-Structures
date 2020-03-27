//
// Created by yyz on 2020/3/27.
//

#ifndef INC_02_ARRAYS_STUDENT_H
#define INC_02_ARRAYS_STUDENT_H

#include <iostream>
#include <string>

class Student
{
public:
    Student(std::string studentName ="", int studentScore = 0)
    {
        this->name = studentName;
        this->score = studentScore;
    }

    friend std::ostream & operator<<(std::ostream &out, Student &student)
    {
        out << "name : " << student.name << ", " << " score : " << student.score;
        return out;
    }

private:
    std::string name;
    int score;
};

#endif //INC_02_ARRAYS_STUDENT_H
