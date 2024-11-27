#pragma once
#include <iostream>
#include <string>
#include <vector>

class Elev {
private:
    int id;
    std::string nume;
    std::string username;
    std::string password;
    std::vector<std::string> cursuri;
    bool autentificat = false;

public:
    Elev(int id, const std::string& nume, const std::string& username, const std::string& password)
        : id(id), nume(nume), username(username), password(password) {}
    Elev() : id(0), nume("") {}

    // Constructor with two arguments
    Elev(int id, const std::string& nume) : id(id), nume(nume) {}

    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }

    // Getters
    int getId() const { return id; }
    std::string getNume() const { return nume; }

    // Autentificare
    bool autentificare(const std::string& username, const std::string& password) {
        if (this->username == username && this->password == password) {
            autentificat = true;
            std::cout << "Autentificare reușita pentru elevul " << nume << "!\n";
            return true;
        }
        else {
            std::cout << "Autentificare eșuata. Verificați datele introduse.\n";
            return false;
        }
    }

    void deconectare() {
        autentificat = false;
        std::cout << "Elevul " << nume << " a fost deconectat.\n";
    }

    // Gestionare cursuri
    void inscriereLaCurs(const std::string& numeCurs) {
        if (autentificat) {
            cursuri.push_back(numeCurs);
            std::cout << "Elevul " << nume << " s-a inscris la cursul " << numeCurs << ".\n";
        }
        else {
            std::cout << "Autentificare necesara pentru inscrierea la cursuri.\n";
        }
    }

    void afisareCursuri() const {
        if (autentificat) {
            std::cout << "Elevul " << nume << " este înscris la urmatoarele cursuri:\n";
            for (const auto& curs : cursuri) {
                std::cout << "- " << curs << std::endl;
            }
        }
        else {
            std::cout << "Autentificare necesara pentru vizualizarea cursurilor.\n";
        }
    }
};
