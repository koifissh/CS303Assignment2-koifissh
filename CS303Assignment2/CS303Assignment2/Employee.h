#pragma once
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int age;
    double weeklySalary;
    int vacationDays;
    double healthCareContributions;
public:
    
    Employee(string name, int age) {
        this->name = name;
        this->age = age;
        weeklySalary = 0.0;
        vacationDays = 0;
        healthCareContributions = 0.0;
    }

    
    virtual double calculateWeeklySalary() = 0;
    virtual double calculateHealthCareContributions() = 0;
    virtual int calculateVacationDays() = 0;

    virtual string getName() { return this->name; }
    virtual int getAge() { return this->age; }
};