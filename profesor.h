#pragma once
#include <string>
#include <vector>

class Curs; // Forward declaration

class Profesor {
private:
    std::string nume;
    std::string username;
    std::string password;
    std::vector<Curs*> cursuriPredate;

public:
    Profesor(std::string nume, std::string username, std::string password)
        : nume(nume), username(username), password(password) {}

    std::string getUsername() const {
        return username;
    }
   
    std::string getPassword() const { return password; }  // Getter pentru parola

    void adaugaCurs(Curs* curs) {
        cursuriPredate.push_back(curs);
    }

    void afisareCursuriPredate() const {
        std::cout << "Profesorul " << nume << " preda urmatoarele cursuri:\n";
        for (const auto& curs : cursuriPredate) {
            std::cout << "- " << curs->getNumeCurs() << std::endl;
        }
    }
};
