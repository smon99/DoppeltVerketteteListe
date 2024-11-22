#include "../include/AddressManager.h"
#include <iostream>

void modify(Node *node) {
    std::string newValue;
    std::cout << "Neuen Namen eingeben (nicht ausfuellen zum behalten \"" << node->name << "\"): ";
    std::getline(std::cin, newValue);
    if (!newValue.empty()) node->name = newValue;

    std::cout << "Enter new street (nicht ausfuellen zum behalten \"" << node->street << "\"): ";
    std::getline(std::cin, newValue);
    if (!newValue.empty()) node->street = newValue;

    std::cout << "Enter new city (nicht ausfuellen zum behalten \"" << node->city << "\"): ";
    std::getline(std::cin, newValue);
    if (!newValue.empty()) node->city = newValue;

    std::cout << "Enter new zipcode (nicht ausfuellen zum behalten \"" << node->zipcode << "\"): ";
    std::getline(std::cin, newValue);
    if (!newValue.empty()) node->zipcode = newValue;

    std::cout << "Addresse erfolgreich aktualisiert.\n";
}

void deleteAddress(DoublyLinkedList &list, const std::string &query) {
    Node *node = list.search(query);
    if (node) {
        list.remove(node);
        std::cout << "Addresse erfolgreich geloescht.\n";
    } else {
        std::cout << "Keine Treffer.\n";
    }
}
