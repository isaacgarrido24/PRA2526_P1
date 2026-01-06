#ifndef POINT2D_H
#define POINT2D_H

#include <ostream> // Para std::ostream
#include <cmath>   // Para las funciones matemáticas (sqrt, pow)

class Point2D{
public:
    // Atributos
    double x;
    double y;

    // Constructor con valores por defecto
    Point2D(double x=0, double y=0);

    // Método estático para calcular la distancia euclidiana
    static double distance(const Point2D &a, const Point2D &b);

    // Declaraciones friend para sobrecarga de operadores globales
    friend bool operator==(const Point2D &a, const Point2D &b);
    friend bool operator!=(const Point2D &a, const Point2D &b);
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif

