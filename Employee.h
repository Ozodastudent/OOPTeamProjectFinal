#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double baseSalary;

public:
    Employee(int id, string name, double baseSalary);
    virtual ~Employee() = default;

    int getId() const;
    string getName() const;
    void setName(const string& name);
    double getBaseSalary() const;
    void setBaseSalary(double salary);

    virtual double calculateSalary() const = 0;
    virtual string getRole() const = 0;
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(int id, string name, double baseSalary, double bonus);
    double calculateSalary() const override;
    string getRole() const override;
    double getBonus() const;
    void setBonus(double bonus);
};

class Developer : public Employee {
private:
    int overtimeHours;

public:
    Developer(int id, string name, double baseSalary, int overtimeHours);
    double calculateSalary() const override;
    string getRole() const override;
    int getOvertimeHours() const;
    void setOvertimeHours(int hours);
};

#endif
