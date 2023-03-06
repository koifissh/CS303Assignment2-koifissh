#pragma once
#include "Employee.h"

class Professional : public Employee {
private:
	double monthlySalary;
	int daysVacation;
public:
	Professional(string name, int age, double monthly) : Employee(name, age) {
		monthlySalary = monthly;
		daysVacation = 30;
	}
	double calculateWeeklySalary() {
		return (monthlySalary/4);
	}
	double calculateHealthCareContributions() {
		return((monthlySalary * 0.10) / 4);
	}
	int calculateVacationDays() {
		return daysVacation;
	}

	void print() {
		cout << "Name: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Weekly Salary: " << calculateWeeklySalary() << endl;
		cout << "Healthcare Contributions: " << calculateHealthCareContributions() << endl;
		cout << "Vacation Days: " << calculateVacationDays() << endl;
	}
};