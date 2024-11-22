#include <iostream>
#include <string>
#include "../include/DoublyLinkedList.h"
#include "../include/AddressManager.h"

void displayMenu() {
    std::cout << "\nAddressverwaltung\n";
    std::cout << "1. Addresse hinzufuegen\n";
    std::cout << "2. Addressen anzeigen\n";
    std::cout << "3. Addressen suchen\n";
    std::cout << "4. Addressesen sortieren\n";
    std::cout << "5. Addresse bearbeiten\n";
    std::cout << "6. Addresse loeschen\n";
    std::cout << "0. Beenden\n";
    std::cout << "Bitte Auswahl eingeben: ";
}

int main() {
    DoublyLinkedList addressList;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string name, street, city, zipcode;
                std::cout << "Namen eingeben: ";
                std::getline(std::cin, name);
                std::cout << "Strasse und Hausnummer eingeben: ";
                std::getline(std::cin, street);
                std::cout << "Stadt eingeben: ";
                std::getline(std::cin, city);
                std::cout << "Postleitzahl eingeben: ";
                std::getline(std::cin, zipcode);

                addressList.append(name, street, city, zipcode);
                break;
            }
            case 2:
                addressList.display();
                break;
            case 3: {
                std::string query;
                std::cout << "Stichwort eingeben: ";
                std::getline(std::cin, query);
                Node *node = addressList.search(query);
                if (node == nullptr) {
                    std::cout << "Keine Treffer.\n";
                } else {
                    std::cout << "Name: " << node->name << ", Strasse: " << node->street
                            << ", Stadt: " << node->city << ", Postleitzahl: " << node->zipcode << "\n";
                }
                break;
            }
            case 4:
                addressList.sort("name");
                std::cout << "Addressen sortiert.\n";
                break;
            case 5: {
                std::string query;
                std::cout << "Namen der Adresse eingeben die geändert werden soll: ";
                std::getline(std::cin, query);
                Node *node = addressList.search(query);
                if (node) {
                    modify(node);
                } else {
                    std::cout << "Addresse nicht gefunden.\n";
                }
                break;
            }
            case 6: {
                std::string query;
                std::cout << "Namen der Adresse eingeben die gelöscht werden soll: ";
                std::getline(std::cin, query);
                deleteAddress(addressList, query);
                break;
            }
            case 0:
                std::cout << "Programm wird beendet.\n";
                break;
            default:
                std::cout << "Ungueltige Auswahl bitte erneut versuchen.\n";
        }
    } while (choice != 0);

    return 0;
}
