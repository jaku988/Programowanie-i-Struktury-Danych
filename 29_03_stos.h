#ifndef UNTITLED_STOS_H
#define UNTITLED_STOS_H
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stos{
    Node *head;
    int rozmiar;
public:
    Stos();
    Stos(const Stos &s1);
    ~Stos();
    void print();
    void push(int a);
    int pop();
    int getR(){return rozmiar;};
    int getFirst();
    bool isEmpty();
    void clear();
    bool operator==(const Stos &s1);
    Stos &operator=(const Stos &s1);
};


#endif //UNTITLED_STOS_H
