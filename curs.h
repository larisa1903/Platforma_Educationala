#pragma once

#include <iostream>   // Pentru std::cout și std::endl
#include <string>     // Pentru std::string
#include <vector>     // Pentru std::vector
#include "elev.h"     // Include fișierul care conține clasa Elev

class Curs {
private:
    std::string numeCurs;
    std::string profesor;
    int capacitateMaxima;
    std::vector<Elev*> studentiInscrisi; // Lista pointerilor către elevii înscriși

public:
    Curs(std::string numeCurs, std::string profesor, int capacitateMaxima)
        : numeCurs(numeCurs), profesor(profesor), capacitateMaxima(capacitateMaxima) {}

    bool adaugaElev(Elev* elev) {
        if (studentiInscrisi.size() < capacitateMaxima) {
            studentiInscrisi.push_back(elev);
            elev->inscriereLaCurs(numeCurs);
            return true;
        }
        else {
            std::cout << "Cursul " << numeCurs << " este plin.\n";
            return false;
        }
    }

    void afiseazaStudenti() const {
        std::cout << "Studentii inscrisi la cursul " << numeCurs << ":\n";
        for (const auto& elev : studentiInscrisi) {
            std::cout << "- " << elev->getNume() << std::endl;
        }
    }

    std::string getNumeCurs() const { return numeCurs; }
    bool eliminaElev(Elev* elev) {
        auto it = std::find(studentiInscrisi.begin(), studentiInscrisi.end(), elev);
        if (it != studentiInscrisi.end()) {
            studentiInscrisi.erase(it);
            std::cout << "Elevul " << elev->getNume() << " a fost eliminat de la cursul " << numeCurs << ".\n";
            return true;
        }
        else {
            std::cout << "Elevul nu este înscris la acest curs.\n";
            return false;
        }
    }

};
