#include "AuthManager.h"
#include <iostream>

AuthManager::AuthManager() : isLoggedIn(false), currentUser("") {}

bool AuthManager::signUp(const std::string& username, const std::string& password,
                         const std::string& fullName, const std::string& email,
                         const std::string& phoneNumber) {
    for (const auto& user : users) {
        if (user.username == username) {
            std::cout << "Username already exists!\n";
            return false;
        }
    }
    users.emplace_back(username, password, fullName, email, phoneNumber);
    std::cout << "\nSign-up successful for " << username << "!\n";
    std::cout << "User Information:\n";
    std::cout << "Full Name: " << fullName << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Phone Number: " << phoneNumber << "\n";
    return true;
}

bool AuthManager::signIn(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            isLoggedIn = true;
            currentUser = username;
            std::cout << "Sign-in successful! Welcome, " << username << "!\n";
            return true;
        }
    }
    std::cout << "Invalid username or password!\n";
    return false;
}

void AuthManager::logout() {
    if (isLoggedIn) {
        std::cout << "Logging out " << currentUser << "...\n";
        isLoggedIn = false;
        currentUser = "";
    } else {
        std::cout << "No user is currently logged in!\n";
    }
}

bool AuthManager::isUserLoggedIn() const { return isLoggedIn; }

std::string AuthManager::getCurrentUser() const { return currentUser; }