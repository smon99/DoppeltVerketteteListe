#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>
#include <iostream>

class Node;

class DoublyLinkedList {
public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    void append(const std::string &name, const std::string &street, const std::string &city,
                const std::string &zipcode);

    void remove(Node *node);

    Node *search(const std::string &query) const;

    void sort(const std::string &key);

    void display() const;

private:
    Node *head;
    Node *tail;
};

class Node {
public:
    // Constructor declaration (but not definition)
    Node(const std::string &n, const std::string &s, const std::string &c, const std::string &z);

    std::string name;
    std::string street;
    std::string city;
    std::string zipcode;
    Node *prev;
    Node *next;
};

#endif // DOUBLYLINKEDLIST_H
