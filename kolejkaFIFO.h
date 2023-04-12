#ifndef UNTITLED_KOLEJKAFIFO_H
#define UNTITLED_KOLEJKAFIFO_H
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int a=0){
        this->data = a;
        this->next = nullptr;
    };
};

struct Kolejka{
    Node *head;
    Node *last;
    int rozmiar;

    Kolejka();
    ~Kolejka();
    Kolejka(Kolejka &k1);
    bool operator==(const Kolejka &k1);
    Kolejka &operator=(const Kolejka &k1);
    void print();
    void push(int a);
    int pop();
    int getR() const{return this->rozmiar;};
    void clear();
    int getFirst();
    int getLast();
    bool isEmpty();

};


struct PID{
    int id_procesu;
    int liczba;

    PID(int id, int n){
        id_procesu = id;
        if(n < 0) n = 0;
        liczba = n;
    }
};

struct Proces{
    PID *data;
    int liczba_watkow;


    Proces(int id, int n, int a){
        data->id_procesu = id;
        data->liczba = n;

        if(a < 1) a = 1;

        liczba_watkow = a;
        next = nullptr;
    }
};

struct Kolejka_procesow{
    Proces data;
    Proces *head;
};





#endif //UNTITLED_KOLEJKAFIFO_H
