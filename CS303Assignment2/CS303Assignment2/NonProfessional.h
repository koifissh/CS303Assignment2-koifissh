#pragma once
#include "Employee.h"

class Nonprofessional : public Employee {
	private:
		double hourlyRate;
		int hoursWorked;
	public:

		Nonprofessional(string name, int age, double rate, int hours) : Employee(name, age) {
			hourlyRate = rate;
			hoursWorked = hours;
		}
		double calculateWeeklySalary() {
			return (hourlyRate * hoursWorked);
		}

		double calculateHealthCareContributions() {
			return (hourlyRate * hoursWorked * 0.05);
		}

		int calculateVacationDays() {
			return (hoursWorked / 10);
		}

		void print() {
			cout << "Name: " << getName() << endl;
			cout << "Age: " << getAge() << endl;
			cout << "Weekly Salary: " << calculateWeeklySalary() << endl;
			cout << "Healthcare Contributions: " << calculateHealthCareContributions() << endl;
			cout << "Vacation Days: " << calculateVacationDays() << endl;
		}
};