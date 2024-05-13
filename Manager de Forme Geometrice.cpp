// Manager de Forme Geometrice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES // Permite accesul la M_PI
#include <iostream>
#include <vector>
#include <cmath>

class Forma {
public:
    virtual double aria() const = 0;
    virtual double perimetrul() const = 0;
    virtual void afiseaza() const = 0;
    virtual ~Forma() {}
};

class Cerc : public Forma {
private:
    double raza;
public:
    Cerc(double r) : raza(r) {}

    double aria() const override {
        return M_PI * raza * raza;
    }

    double perimetrul() const override {
        return 2 * M_PI * raza;
    }

    void afiseaza() const override {
        std::cout << "Cerc - Raza: " << raza << ", Aria: " << aria() << ", Perimetrul: " << perimetrul() << std::endl;
    }
};

class Patrat : public Forma {
private:
    double latura;
public:
    Patrat(double l) : latura(l) {}

    double aria() const override {
        return latura * latura;
    }

    double perimetrul() const override {
        return 4 * latura;
    }

    void afiseaza() const override {
        std::cout << "Patrat - Latura: " << latura << ", Aria: " << aria() << ", Perimetrul: " << perimetrul() << std::endl;
    }
};

class Dreptunghi : public Forma {
private:
    double lungime;
    double latime;
public:
    Dreptunghi(double l, double w) : lungime(l), latime(w) {}

    double aria() const override {
        return lungime * latime;
    }

    double perimetrul() const override {
        return 2 * (lungime + latime);
    }

    void afiseaza() const override {
        std::cout << "Dreptunghi - Lungime: " << lungime << ", Latime: " << latime << ", Aria: " << aria() << ", Perimetrul: " << perimetrul() << std::endl;
    }
};

int main() {
    std::vector<Forma*> forme;

    forme.push_back(new Cerc(21));
    forme.push_back(new Patrat(20));
    forme.push_back(new Dreptunghi(47, 55));

    for (const auto& forma : forme) {
        forma->afiseaza();
    }

    for (const auto& forma : forme) {
        delete forma;
    }

    return 0;
}


