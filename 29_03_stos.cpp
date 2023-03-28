#include "stos.h"

Stos::Stos(){
    this->head = nullptr;
    this->rozmiar = 0;
}

Stos::Stos(const Stos &s1){
    this->rozmiar = s1.rozmiar;

    if(this->rozmiar != 0){
        Node *iterator = s1.head;

        while(iterator->next != nullptr){

            Node *nowy = new Node;
            nowy->data = iterator->data;
            nowy->next = nullptr;

            Node *iterator2 = this->head;

            while(iterator2->next != nullptr) {
                iterator2 = iterator2->next;
            }
            iterator2->next = nowy;
            iterator = iterator->next;
        }

    }
}

Stos::~Stos(){
    Node *killer = new Node;
    Node *iterator = head;

    while(iterator != nullptr){
        killer = iterator;
        iterator = iterator->next;
        delete killer;
    }
    this->rozmiar = NULL;
}

void Stos::print(){
    if(head == nullptr){
        cout << "Stos jest pusty!";
    }
    else{
        Node *iterator = head;

        while(iterator != nullptr){
            cout << "[" << iterator->data << "] ";
            iterator = iterator->next;
        }
    }
}

void Stos::push(int a){
    Node *nowy = new Node;
    nowy->data = a;
    nowy->next = nullptr;

    if(head == nullptr){
        head = nowy;
    }
    else{
        Node *iterator;

        nowy->next = head;
        head = nowy;
    }
    rozmiar++;
}

int Stos::pop(){
    if(head != nullptr){
        int res = head->data;
        Node *killer = head;
        head = head->next;

        delete killer;

        rozmiar++;
        return res;
    }
    cout << "Stos jest pusty!" << endl;
    return -1;
}

int Stos::getFirst(){
    if(head == nullptr){
        cout << "Stos jest pusty!" << endl;
        return -1;
    }
    else{
        return head->data;
    }

}

bool Stos::isEmpty(){
    if(head != nullptr) return true;
    else return false;
}

void Stos::clear(){
    if(head != nullptr){
        head = nullptr;
    }
    else{
        cout << "Stos jest pusty!" << endl;
    }
}

bool Stos::operator==(const Stos &s1){
    if((this->rozmiar == s1.rozmiar) && this->rozmiar != 0){
        Node *iterator = this->head;
        Node *iterator2 = s1.head;

        while(iterator->next != nullptr){
            if(iterator->data != iterator2->data) return false;
            iterator = iterator->next;
            iterator2 = iterator2->next;
        }
        return true;
    }
    return false;
}

Stos &Stos::operator=(const Stos &s1){
    this->rozmiar = s1.rozmiar;
    this->head = nullptr;

    if(this->rozmiar != 0){
        Node *iterator = s1.head;

        while(iterator->next != nullptr){

            Node *nowy = new Node;
            nowy->data = iterator->data;
            nowy->next = nullptr;

            Node *iterator2 = this->head;

            while(iterator2->next != nullptr) {
                iterator2 = iterator2->next;
            }
            iterator2->next = nowy;
            iterator = iterator->next;
        }

    }
    return *this;
}
