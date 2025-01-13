#include <iostream>
#include <string>
#include <vector>
#include "platforma.h"
#include "elev.h"
#include "profesor.h"

void afiseazaMeniu() {
    std::cout << "\n===== Meniu Principal =====\n";
    std::cout << "1. Autentificare Elev\n";
    std::cout << "2. Autentificare Profesor\n";
    std::cout << "3. Autentificare Administrator\n";
    std::cout << "0. Iesire\n";
    std::cout << "============================\n";
    std::cout << "Selectati o optiune: ";
}

int main( ) {
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
            // Dacă este autentificat ca elev, afisează meniul corespunzător
            if (elevAutentificat) {
                std::cout << "\nMeniu Elev:\n";
                std::cout << "1. Inscriere la curs\n";
                std::cout << "2. Deconectare\n";
                std::cout << "Selectati o optiune: ";
                std::cin >> optiuneAutentificare;
            }
            switch (optiuneAutentificare){

            case 1: {// inscriere elev la curs 
                int id;
                std::string numeCurs;
                std::cout << "Introduceti id elev:  ";
                std::cin >> id;
                std::cout << "Introduceti numele cursului  ";
                std::cin >> numeCurs;
                platforma.inscriereElevLaCurs(id, numeCurs);
                break;
            }
            case 2: { // Deconectare elev
                elevAutentificat = false;
                std::cout << "Elev deconectat.\n";
                break;
                    }
            }
                
            break; // Important: trebuie să se închidă corect acest caz
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

            if (profesorAutentificat) {
                std::cout << "\nMeniu Profesor:\n";
                std::cout << "1. Adauga elev la curs\n";
                std::cout << "2. Sterge elev de la curs\n";
                std::cout << "3. Adauga curs\n";
                std::cout << "4. Sterge curs\n";
                std::cout << "5. Deconectare\n";
                std::cout << "Selectati o optiune: ";
                std::cin >> optiuneAutentificare;
            }
            switch (optiuneAutentificare) {

            case 1: {// inscriere elev la curs 
                int id;
                std::string numeCurs;
                std::cout << "Introduceti id elev:  ";
                std::cin >> id;
                std::cout << "Introduceti numele cursului  ";
                std::cin >> numeCurs;
                platforma.inscriereElevLaCurs(id, numeCurs);
                break;
            }
            case 2: {// stergere elev curs 
                int id;
                std::string numeCurs;
                std::cout << "Introduceti id elev:  ";
                std::cin >> id;
                std::cout << "Introduceti numele cursului  ";
                std::cin >> numeCurs;
                platforma.stergeElevdelaCurs(id, numeCurs);
                break;
            }
            case 3: { // Adaugare Curs
                std::string numeCurs, profesor;
                int capacitateMaxima;
                std::cout << "Introduceti numele cursului: ";
                std::cin >> numeCurs;
                std::cout << "Introduceti numele profesorului: ";
                std::cin >> profesor;
                std::cout << "Introduceti capacitatea maxima: ";
                std::cin >> capacitateMaxima;
                platforma.adaugaCurs(numeCurs, profesor, capacitateMaxima);
                break;
            }
            case 4: { // Stergere Curs
                std::string numeCurs;
                std::cout << "Introduceti numele cursului de sters: ";
                std::cin >> numeCurs;
                platforma.stergeCurs(numeCurs);
                break;
            }
            case 5: { // Deconectare profesor
                elevAutentificat = false;
                std::cout << "Profesor deconectat.\n";
                break;
            }
            }

            break; // Important: trebuie să se închidă corect acest caz
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

                // Meniu Administrator
                while (adminAutentificat) {
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

                    switch (optiuneAutentificare) {
                    case 1: { // Adaugare Elev
                        int id;
                        std::string nume, prenume, usernameElev, passwordElev;
                        std::cout << "Introduceti ID-ul elevului: ";
                        std::cin >> id;
                        std::cout << "Introduceti numele elevului: ";
                        std::cin >> nume;
                        std::cout << "Introduceti prenumele elevului: ";
                        std::cin >> prenume;
                        std::cout << "Introduceti username-ul elevului: ";
                        std::cin >> usernameElev;
                        std::cout << "Introduceti parola elevului: ";
                        std::cin >> passwordElev;

                        platforma.adaugaElev(id, nume, prenume, usernameElev, passwordElev);
                        break;
                    }
                    case 2: { // Stergere Elev
                        int id;
                        std::cout << "Introduceti ID-ul elevului de sters: ";
                        std::cin >> id;
                        platforma.stergeElev(id);
                        break;
                    }
                    case 3: { // Adaugare Curs
                        std::string numeCurs, profesor;
                        int capacitateMaxima;
                        std::cout << "Introduceti numele cursului: ";
                        std::cin >> numeCurs;
                        std::cout << "Introduceti numele profesorului: ";
                        std::cin >> profesor;
                        std::cout << "Introduceti capacitatea maxima: ";
                        std::cin >> capacitateMaxima;
                        platforma.adaugaCurs(numeCurs, profesor, capacitateMaxima);
                        break;
                    }
                    case 4: { // Stergere Curs
                        std::string numeCurs;
                        std::cout << "Introduceti numele cursului de sters: ";
                        std::cin >> numeCurs;
                        platforma.stergeCurs(numeCurs);
                        break;
                    }
                    case 5: { // Adăugare Profesor
                        std::string numeProfesor, prenumeProfesor, usernameProfesor, passwordProfesor;
                        std::cout << "Introduceti numele profesorului: ";
                        std::cin >> numeProfesor;
                        std::cout << "Introduceti prenumele profesorului: ";
                        std::cin >> prenumeProfesor;
                        std::cout << "Introduceti username-ul profesorului: ";
                        std::cin >> usernameProfesor;
                        std::cout << "Introduceti parola profesorului: ";
                        std::cin >> passwordProfesor;

                        platforma.adaugaProfesor(numeProfesor, prenumeProfesor, usernameProfesor, passwordProfesor);
                        break;
                    }
                    case 6: { // Stergere Profesor
                        std::cout << "Introduceti username-ul profesorului de sters: ";
                        std::cin >> username;
                        platforma.stergeProfesor(username);
                        break;
                    }
                    case 7: { // Deconectare Administrator
                        adminAutentificat = false;
                        std::cout << "Administrator deconectat.\n";
                        break;
                    }
                    default:
                        std::cout << "Optiune invalida. Incercati din nou.\n";
                        break;
                    }
                }
            }
            else {
                std::cout << "Autentificare administrator esuata.\n";
            }
            break; // Important: trebuie să se închidă corect acest caz
        }

        case 0: {
            std::cout << "Iesire din aplicatie. La revedere!\n";
            break;
        }
        default:
            std::cout << "Optiune invalida. Incercati din nou.\n";
            break;
        }
    }

    return 0;
}
