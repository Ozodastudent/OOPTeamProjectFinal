#include "Employee.h"
#include "Set.h"
#include "AuthManager.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMenu() {
    std::cout << "\nEmployee Management System Menu:\n";
    std::cout << "1. Add Manager\n";
    std::cout << "2. Add Developer\n";
    std::cout << "3. Display Managers\n";
    std::cout << "4. Display Developers\n";
    std::cout << "5. Logout\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter choice: ";
}

void runTests(AuthManager& authManager, EmployeeSet& empSet) {
    // Test 1: Sign-up with additional info and Sign-in
    authManager.signUp("hr_admin", "password123", "John Doe", "john.doe@email.com", "123-456-7890");
    authManager.signIn("hr_admin", "password123");

    // Test 2: Add employees and display
    if (authManager.isUserLoggedIn()) {
        Manager* m1 = new Manager(1, "Alice", 5000, 1000);
        Developer* d1 = new Developer(2, "Bob", 4000, 10);
        empSet.insert(m1);
        empSet.insert(d1);

        std::cout << "All Managers:\n";
        empSet.displayByRole("Manager");
        std::cout << "All Developers:\n";
        empSet.displayByRole("Developer");

        // Test 3: Logout
        authManager.logout();
    }
}

int main() {
    AuthManager authManager;
    EmployeeSet empSet;
    bool running = true;

    while (running) {
        if (!authManager.isUserLoggedIn()) {
            std::cout << "\n1. Sign Up\n2. Sign In\n3. Run Tests\n4. Exit\n";
            std::cout << "Enter choice: ";
            int choice;
            std::cin >> choice;
            clearInputBuffer();

            if (choice == 1) {
                std::string username, password, fullName, email, phoneNumber;
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                std::cout << "Enter full name: ";
                std::getline(std::cin, fullName);
                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phoneNumber);
                authManager.signUp(username, password, fullName, email, phoneNumber);
            } else if (choice == 2) {
                std::string username, password;
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                authManager.signIn(username, password);
            } else if (choice == 3) {
                runTests(authManager, empSet);
            } else if (choice == 4) {
                running = false;
            } else {
                std::cout << "Invalid choice!\n";
            }
        } else {
            showMenu();
            int choice;
            std::cin >> choice;
            clearInputBuffer();

            if (choice == 1) {
                int id;
                std::string name;
                double salary, bonus;
                std::cout << "Enter ID: ";
                std::cin >> id;
                clearInputBuffer();
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter base salary: ";
                std::cin >> salary;
                std::cout << "Enter bonus: ";
                std::cin >> bonus;
                empSet.insert(new Manager(id, name, salary, bonus));
            } else if (choice == 2) {
                int id, hours;
                std::string name;
                double salary;
                std::cout << "Enter ID: ";
                std::cin >> id;
                clearInputBuffer();
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter base salary: ";
                std::cin >> salary;
                std::cout << "Enter overtime hours: ";
                std::cin >> hours;
                empSet.insert(new Developer(id, name, salary, hours));
            } else if (choice == 3) {
                std::cout << "All Managers:\n";
                empSet.displayByRole("Manager");
            } else if (choice == 4) {
                std::cout << "All Developers:\n";
                empSet.displayByRole("Developer");
            } else if (choice == 5) {
                authManager.logout();
            } else if (choice == 6) {
                running = false;
            } else {
                std::cout << "Invalid choice!\n";
            }
        }
    }
    return 0;
}