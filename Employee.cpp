//
// Created by USER on 4/18/2025.
//

#include "Employee.h"


Employee::Employee(int id, string name, double baseSalary)
        : id(id), name(name), baseSalary(baseSalary) {}

int Employee::getId() const { return id; }
string Employee::getName() const { return name; }
void Employee::setName(const string& name) { this->name = name; }
double Employee::getBaseSalary() const { return baseSalary; }
void Employee::setBaseSalary(double salary) { this->baseSalary = salary; }

Manager::Manager(int id, string name, double baseSalary, double bonus)
        : Employee(id, name, baseSalary), bonus(bonus) {}

double Manager::calculateSalary() const {
    return getBaseSalary() + bonus;
}

string Manager::getRole() const { return "Manager"; }

double Manager::getBonus() const { return bonus; }
void Manager::setBonus(double bonus) { this->bonus = bonus; }

Developer::Developer(int id, string name, double baseSalary, int overtimeHours)
        : Employee(id, name, baseSalary), overtimeHours(overtimeHours) {}

double Developer::calculateSalary() const {
    return getBaseSalary() + (overtimeHours * 50.0); // $50 per overtime hour
}

string Developer::getRole() const { return "Developer"; }

int Developer::getOvertimeHours() const { return overtimeHours; }
void Developer::setOvertimeHours(int hours) { this->overtimeHours = hours; }