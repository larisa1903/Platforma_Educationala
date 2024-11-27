#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "elev.h"
#include "curs.h"
#include "profesor.h"
#include "admin.h"

class PlatformaEducatie {
private:
    std::vector<Elev> elevi;
    std::vector<Curs> cursuri;
    std::vector<Profesor> profesori;
    Admin admin;

public:
    // Constructor
    PlatformaEducatie(const Admin& admin) : admin(admin) {}


    // Afi?are cursuri disponibile
    void afiseazaCursuri() const {
        std::cout << "Cursurile disponibile sunt:\n";
        for (const auto& curs : cursuri) {
            std::cout << "- " << curs.getNumeCurs() << std::endl;
        }
    }

    // Înscriere elev la un curs specificat
    void inscriereElevLaCurs(int idElev, const std::string& numeCurs) {
        auto itElev = std::find_if(elevi.begin(), elevi.end(), [idElev](const Elev& elev) {
            return elev.getId() == idElev;
            });

        auto itCurs = std::find_if(cursuri.begin(), cursuri.end(), [&numeCurs](const Curs& curs) {
            return curs.getNumeCurs() == numeCurs;
            });

        if (itElev != elevi.end() && itCurs != cursuri.end()) {
            itCurs->adaugaElev(&(*itElev));
        }
    }

    // Gestionare Elevi
    void adaugaElev(int id, const std::string& nume) {
        elevi.emplace_back(id, nume);
        std::cout << "Elevul " << nume << " a fost adaugat.\n";
    }

    void stergeElev(int id) {
        auto it = std::remove_if(elevi.begin(), elevi.end(), [id](const Elev& elev) {
            return elev.getId() == id;
            });

        if (it != elevi.end()) {
            std::cout << "Elevul cu ID-ul " << id << " a fost sters.\n";
            elevi.erase(it, elevi.end());
        }
        else {
            std::cout << "Elevul cu ID-ul " << id << " nu a fost gasit.\n";
        }
    }

    // Gestionare Cursuri
    void adaugaCurs(const std::string& numeCurs, const std::string& profesor, int capacitateMaxima) {
        cursuri.emplace_back(numeCurs, profesor, capacitateMaxima);
        std::cout << "Cursul " << numeCurs << " a fost adaugat.\n";
    }

    void stergeCurs(const std::string& numeCurs) {
        auto it = std::remove_if(cursuri.begin(), cursuri.end(), [numeCurs](const Curs& curs) {
            return curs.getNumeCurs() == numeCurs;
            });

        if (it != cursuri.end()) {
            std::cout << "Cursul " << numeCurs << " a fost sters.\n";
            cursuri.erase(it, cursuri.end());
        }
        else {
            std::cout << "Cursul " << numeCurs << " nu a fost gasit.\n";
        }
    }

    // Gestionare Profesori
    void adaugaProfesor(const std::string& nume, const std::string& username, const std::string& password) {
        profesori.emplace_back(nume, username, password);
        std::cout << "Profesorul " << nume << " a fost adaugat.\n";
    }


    void stergeProfesor(const std::string& username) {
        auto it = std::remove_if(profesori.begin(), profesori.end(), [username](const Profesor& profesor) {
            return profesor.getUsername() == username;
            });

        if (it != profesori.end()) {
            std::cout << "Profesorul cu username-ul " << username << " a fost sters.\n";
            profesori.erase(it, profesori.end());
        }
        else {
            std::cout << "Profesorul cu username-ul " << username << " nu a fost gasit.\n";
        }
    }
    bool autentificareElev(const std::string& username, const std::string& password) {
        for (const auto& elev : elevi) {
            if (elev.getUsername() == username && elev.getPassword() == password) {
                return true;
            }
        }
        return false;
    }

    // Func?ie pentru autentificare profesor
    bool autentificareProfesor(const std::string& username, const std::string& password) {
        for (const auto& profesor : profesori) {
            if (profesor.getUsername() == username && profesor.getPassword() == password) {
                return true;
            }
        }
        return false;
    }

    // Func?ie pentru autentificare administrator
    bool autentificareAdministrator(const std::string& username, const std::string& password) {
        return (admin.getUsername() == username && admin.getPassword() == password);
    }

};
