#include "Set.h"
#include <iostream>

template <typename T>
Set<T>::~Set() {
    for (T* item : items) {
        delete item;
    }
}

template <typename T>
void Set<T>::insert(T* item) {
    items.push_back(item);
}

template <typename T>
void Set<T>::remove(T* item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            delete *it;
            items.erase(it);
            break;
        }
    }
}

template <typename T>
void Set<T>::display() const {
    for (const T* item : items) {
        std::cout << "Item pointer: " << item << std::endl;
    }
}

// Explicit instantiation for Employee type
template class Set<Employee>;

void EmployeeSet::displayByRole(const std::string& role) const {
    for (const Employee* emp : items) {
        if (emp->getRole() == role) {
            std::cout << "ID: " << emp->getId() << ", Name: " << emp->getName()
                      << ", Role: " << emp->getRole() << ", Salary: $" << emp->calculateSalary() << std::endl;
        }
    }
}
