#pragma once
#include <string>
#include <iostream>

class Admin {
private:
    std::string username;
    std::string password;

public:
    // Constructor
    Admin(std::string username, std::string password)
        : username(username), password(password) {}

    std::string getUsername() const {
        return username;
    }
    std::string getPassword() const {
        return password;
    }
};
