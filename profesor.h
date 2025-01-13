#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>
#include <vector>
#include "curs.h" 

class Profesor {
private:
    std::string nume;
    std::string prenume;
    std::string username;
    std::string password;
    std::vector<Curs*> cursuriPredate;

public:
    Profesor(std::string nume, std::string prenume, std::string username, std::string password)
        : nume(nume), prenume(prenume), username(username), password(password) {}

    std::string getNume() const {
        return nume;
    }

    std::string getPrenume() const {
        return prenume;
    }

    std::string getUsername() const {
        return username;
    }

    std::string getPassword() const {
        return password;
    }

    void adaugaCurs(Curs* curs) {
        cursuriPredate.push_back(curs);
    }

    void afisareCursuriPredate() const {
        std::cout << "Profesorul " << nume << " " << prenume << " preda urmatoarele cursuri:\n";
        for (const auto& curs : cursuriPredate) {
            std::cout << "- " << curs->getNumeCurs() << std::endl;
        }
    }
};

#endif  // PROFESOR_H
