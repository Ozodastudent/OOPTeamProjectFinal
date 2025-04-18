#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H

#include <string>
#include <vector>

class AuthManager {
private:
    struct User {
        std::string username;
        std::string password;
        std::string fullName;
        std::string email;
        std::string phoneNumber;
        User(const std::string& uname, const std::string& pwd, const std::string& name,
             const std::string& mail, const std::string& phone)
                : username(uname), password(pwd), fullName(name), email(mail), phoneNumber(phone) {}
    };

    std::vector<User> users;
    bool isLoggedIn;
    std::string currentUser;

public:
    AuthManager();
    bool signUp(const std::string& username, const std::string& password,
                const std::string& fullName, const std::string& email,
                const std::string& phoneNumber);
    bool signIn(const std::string& username, const std::string& password);
    void logout();
    bool isUserLoggedIn() const;
    std::string getCurrentUser() const;
};

#endif