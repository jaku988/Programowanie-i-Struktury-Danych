#include "kolejkaFIFO.h"

Kolejka::Kolejka(){
    rozmiar = 0;
    head = nullptr;
    last = nullptr;
}

Kolejka::~Kolejka(){
    Node *killer = new Node();

    Node *iterator = head;
    while(iterator != nullptr){
        killer = iterator;
        iterator = iterator->next;
        delete killer;
    }
}

bool Kolejka::operator==(const Kolejka &k1){
    if(this->rozmiar == k1.rozmiar){
        Node *iterator = this->head;
        Node *iterator2 = k1.head;

        while(iterator != nullptr){
            if(iterator->data != iterator2->data) return false;
            iterator = iterator->next;
            iterator2 = iterator2->next;
        }
        return true;
    }
    else{
        return false;
    }
}

void Kolejka::print(){
    if(head == nullptr){
        cout << "Kolejka jest pusta!" << endl;
    }
    else{
        Node *iterator = head;

        while(iterator != nullptr){
            cout << iterator->data << " ";
            iterator = iterator->next;
        }
        cout << endl;
    }
}

void Kolejka::push(int a){
    Node *nowy = new Node(a);

    if(head == nullptr){
        head = nowy;
        last = head;
    }
    else{
        Node *iterator = head;

        while(iterator->next != nullptr){
            iterator = iterator->next;
        }
        iterator->next = nowy;
        last = nowy;
    }
    rozmiar++;
}

int Kolejka::pop(){
    if(head == nullptr){
        cout << "Kolejka jest pusta!";
        return -1;
    }
    else{
        Node *iterator = head;
        Node *prev = new Node();

        while(iterator->next != nullptr){
            prev = iterator;
            iterator = iterator->next;
        }
        int res = prev->next->data;
        prev->next = nullptr;
        delete prev->next;

        last = prev;
        rozmiar--;
        return res;
    }
}

void Kolejka::clear(){
    if(head != nullptr){
        head = nullptr;
    }
}

int Kolejka::getFirst(){
    if(head == nullptr){
        cout << "Kolejka jest pusta!" << endl;
        return -1;
    }
    else{
        return head->data;
    }
}

int Kolejka::getLast(){
    if(head == nullptr){
        cout << "Kolejka jest pusta!" << endl;
        return -1;
    }
    else{
        return last->data;
    }
}

bool Kolejka::isEmpty(){
    if(head == nullptr) return true;
    return false;
}