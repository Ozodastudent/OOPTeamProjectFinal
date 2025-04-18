#ifndef SET_H
#define SET_H

#include "Employee.h"
#include <vector>
#include <string>

template <typename T>
class Set {
protected:
    std::vector<T*> items;

public:
    Set() = default;
    virtual ~Set();

    void insert(T* item);
    void remove(T* item);
    void display() const;
};

class EmployeeSet : public Set<Employee> {
public:
    void displayByRole(const std::string& role) const;
};

#endif