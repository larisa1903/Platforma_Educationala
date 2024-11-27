#include <iostream>
#include <string>
#include <vector>
#include "platforma.h"
#include "elev.h"
#include "profesor.h"// Include fișierul care conține clasa PlatformaEducatie

void afiseazaMeniu() {
    std::cout << "\n===== Meniu Principal =====\n";
    std::cout << "1. Autentificare Elev\n";
    std::cout << "2. Autentificare Profesor\n";
    std::cout << "3. Autentificare Administrator\n";
    std::cout << "0. Iesire\n";
    std::cout << "============================\n";
    std::cout << "Selectati o optiune: ";
}

int main() {
    Admin admin("admin", "admin123"); // Crearea unui administrator implicit
    PlatformaEducatie platforma(admin); // Inițializarea platformei educaționale

    int optiune = -1;
    int optiuneAutentificare = -1;
    bool elevAutentificat = false, profesorAutentificat = false, adminAutentificat = false;
    std::string username, password;

    while (optiune != 0) {
        afiseazaMeniu();
        std::cin >> optiune;

        switch (optiune) {
        case 1: { // Autentificare Elev
            std::cout << "Introduceti username-ul elevului: ";
            std::cin >> username;
            std::cout << "Introduceti parola elevului: ";
            std::cin >> password;

            // Verificare autentificare elev
            elevAutentificat = platforma.autentificareElev(username, password);
            if (elevAutentificat) {
                std::cout << "Autentificare elev reusita!\n";
            }
            else {
                std::cout << "Autentificare elev esuata.\n";
            }
            break;
        }
        case 2: { // Autentificare Profesor
            std::cout << "Introduceti username-ul profesorului: ";
            std::cin >> username;
            std::cout << "Introduceti parola profesorului: ";
            std::cin >> password;

            // Verificare autentificare profesor
            profesorAutentificat = platforma.autentificareProfesor(username, password);
            if (profesorAutentificat) {
                std::cout << "Autentificare profesor reusita!\n";
            }
            else {
                std::cout << "Autentificare profesor esuata.\n";
            }
            break;
        }
        case 3: { // Autentificare Administrator
            std::cout << "Introduceti username-ul administratorului: ";
            std::cin >> username;
            std::cout << "Introduceti parola administratorului: ";
            std::cin >> password;

            // Verificare autentificare admin
            adminAutentificat = platforma.autentificareAdministrator(username, password);
            if (adminAutentificat) {
                std::cout << "Autentificare administrator reusita!\n";
            }
            else {
                std::cout << "Autentificare administrator esuata.\n";
            }
            break;
        }
        case 0: {
            std::cout << "Iesire din aplicatie. La revedere!\n";
            break;
        }
        default:
            std::cout << "Optiune invalida. Incercati din nou.\n";
            break;
        }

        // Dacă este autentificat ca elev, profesor sau administrator, afisează meniul corespunzător
        if (elevAutentificat) {
            std::cout << "\nMeniu Elev:\n";
            std::cout << "1. Afiseaza cursuri\n";
            std::cout << "2. Inscriere la curs\n";
            std::cout << "3. Deconectare\n";
            std::cout << "Selectati o optiune: ";
            std::cin >> optiuneAutentificare;

        }

        if (profesorAutentificat) {
            std::cout << "\nMeniu Profesor:\n";
            std::cout << "1. Afiseaza cursuri predante\n";
            std::cout << "2. Deconectare\n";
            std::cout << "Selectati o optiune: ";
            std::cin >> optiuneAutentificare;

        }

        if (adminAutentificat) {
            std::cout << "\nMeniu Administrator:\n";
            std::cout << "1. Adauga elev\n";
            std::cout << "2. Sterge elev\n";
            std::cout << "3. Adauga curs\n";
            std::cout << "4. Sterge curs\n";
            std::cout << "5. Adauga profesor\n";
            std::cout << "6. Sterge profesor\n";
            std::cout << "7. Deconectare\n";
            std::cout << "Selectati o optiune: ";
            std::cin >> optiuneAutentificare;

        }
    }
