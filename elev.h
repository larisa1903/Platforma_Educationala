#pragma once
#include <iostream>
#include <string>
#include <vector>

class Elev {
private:
    int id;
    std::string nume; // Numele elevului
    std::string prenume; // Prenumele elevului
    std::string username;
    std::string password;
    std::vector<std::string> cursuri;
    bool autentificat = false;

public:
    Elev(int id, const std::string& nume, const std::string& prenume, const std::string& username, const std::string& password)
        : id(id), nume(nume), prenume(prenume), username(username), password(password) {}

    Elev(int id, const std::string& nume, const std::string& prenume)
        : id(id), nume(nume), prenume(prenume) {}

    Elev() : id(0), nume(""), prenume("") {}


    // Getteri
    int getId() const { return id; }
    std::string getNume() const { return nume; }
    std::string getPrenume() const { return prenume; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
 


    // Metodă pentru autentificare
    bool autentificare(const std::string& username, const std::string& password) {
        if (this->username == username && this->password == password) {
            autentificat = true;
            std::cout << "Autentificare reușită pentru elevul " << nume << " " << prenume << "!\n";
            return true;
        }
        else {
            std::cout << "Autentificare eșuată. Verificați datele introduse.\n";
            return false;
        }
    }

    void deconectare() {
        autentificat = false;
        std::cout << "Elevul " << nume << " " << prenume << " a fost deconectat.\n";
    }

    // Gestionare cursuri
    void inscriereLaCurs(const std::string& numeCurs) {
        if (autentificat) {
            cursuri.push_back(numeCurs);
            std::cout << "Elevul " << nume << " " << prenume << " s-a înscris la cursul " << numeCurs << ".\n";
        }
        else {
            std::cout << "Autentificare necesară pentru înscrierea la cursuri.\n";
        }
    }

    void afisareCursuri() const {
        if (autentificat) {
            std::cout << "Elevul " << nume << " " << prenume << " este înscris la următoarele cursuri:\n";
            for (const auto& curs : cursuri) {
                std::cout << "- " << curs << std::endl;
            }
        }
        else {
            std::cout << "Autentificare necesară pentru vizualizarea cursurilor.\n";
        }
    }
};
