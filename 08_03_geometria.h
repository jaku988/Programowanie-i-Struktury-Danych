#ifndef ALGORYTMY_GEOMETRIA_H
#define ALGORYTMY_GEOMETRIA_H
#include <iostream>
#include <cmath>
using namespace std;

struct Punkt{
    double x;
    double y;
public:
    Punkt(double x=0, double y=0): x(x), y(y) {};
    double getX() const{return x;};
    double getY() const{return y;};
    void setX(double x){this->x = x;};
    void setY(double y){this->y = y;};
    void rysuj();
    bool operator<(const Punkt &p1);
    bool operator>(const Punkt &p1);
    bool operator<=(const Punkt &p1);
    bool operator>=(const Punkt &p1);
};

struct Prosta{
    double a;
    double b;
public:
    Prosta(double a=0, double b=0): a(a), b(b){};
    Prosta(Punkt *p1, Punkt *p2);
    double getA() const{return a;};
    double getB() const{return b;};
    void setA(const double a){this->a = a;};
    void setB(const double b){this->b = b;};
    void rysuj();
};



void Punkt::rysuj(){
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
}

bool Punkt::operator<(const Punkt &p1){
    float odleglosc = sqrt(pow(this->x, 2) + pow(this->y, 2));
    float odleglosc2 = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
    if(odleglosc < odleglosc2) return true;
    else return false;
}

bool Punkt::operator>(const Punkt &p1){
    float odleglosc = sqrt(pow(this->x, 2) + pow(this->y, 2));
    float odleglosc2 = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
    if(odleglosc > odleglosc2) return true;
    else return false;
}

bool Punkt::operator<=(const Punkt &p1){
    float odleglosc = sqrt(pow(this->x, 2) + pow(this->y, 2));
    float odleglosc2 = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
    if(odleglosc <= odleglosc2) return true;
    else return false;
}

bool Punkt::operator>=(const Punkt &p1){
    float odleglosc = sqrt(pow(this->x, 2) + pow(this->y, 2));
    float odleglosc2 = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
    if(odleglosc >= odleglosc2) return true;
    else return false;
}



Prosta::Prosta(Punkt *p1, Punkt *p2){
    if(p1->x - p2->x != 0){
        this->a = p2->y - p1->y / p2->x - p1->x;
        this->b = p1->y - this->a * p1->x;
    }
    else delete this;
}

void Prosta::rysuj(){
    cout << a << "x ";
    if(b > 0){
        cout << "+ " << b;
    }
    else if(b < 0){
        cout << "- " << abs(b);
    }
}

bool czyRownolegle(Prosta &p1, Prosta &p2){
    if(p1.a == p2.a) return true;
    else return false;
}

bool czyProstopadle(Prosta &p1, Prosta &p2){
    // p1.a  = -1 / p2.a
    if(p1.a == -1 / p2.a) return true;
    else return false;
}

#endif //ALGORYTMY_GEOMETRIA_H
