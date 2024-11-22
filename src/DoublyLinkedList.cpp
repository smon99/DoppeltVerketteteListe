#include "../include/DoublyLinkedList.h"
#include <iostream>

Node::Node(const std::string &n, const std::string &s, const std::string &c, const std::string &z)
    : name(n), street(s), city(c), zipcode(z), prev(nullptr), next(nullptr) {
}

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLinkedList::append(const std::string &name, const std::string &street, const std::string &city,
                              const std::string &zipcode) {
    Node *newNode = new Node(name, street, city, zipcode);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::remove(Node *node) {
    if (!node) return;

    if (node == head) head = node->next;
    if (node == tail) tail = node->prev;

    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;

    delete node;
}

Node *DoublyLinkedList::search(const std::string &query) const {
    Node *current = head;
    while (current) {
        if (current->name.find(query) != std::string::npos ||
            current->street.find(query) != std::string::npos ||
            current->city.find(query) != std::string::npos ||
            current->zipcode.find(query) != std::string::npos) {
            return current; // Return the first matching node
        }
        current = current->next;
    }
    return nullptr;
}

void DoublyLinkedList::sort(const std::string &key) {
    if (!head || !head->next) return; // No need to sort if 0 or 1 element

    bool swapped;
    do {
        swapped = false;
        Node *current = head;

        while (current && current->next) {
            if (current->name > current->next->name) {
                std::swap(current->name, current->next->name);
                std::swap(current->street, current->next->street);
                std::swap(current->city, current->next->city);
                std::swap(current->zipcode, current->next->zipcode);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void DoublyLinkedList::display() const {
    Node *current = head;
    while (current) {
        std::cout << "Name: " << current->name
                << ", Straße: " << current->street
                << ", Stadt: " << current->city
                << ", Postleitzahl: " << current->zipcode << "\n";
        current = current->next;
    }
}
