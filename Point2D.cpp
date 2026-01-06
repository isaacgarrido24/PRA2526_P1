#include "Point2D.h"
#include <cmath> // Necesario para sqrt y pow

// Constructor
Point2D::Point2D(double x, double y) : x(x), y(y) {}

// Distancia euclidiana
double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Operador de igualdad
bool operator==(const Point2D &a, const Point2D &b) {
    return a.x == b.x && a.y == b.y;
}

// Operador de desigualdad
bool operator!=(const Point2D &a, const Point2D &b) {
    return !(a == b); // Reutilizamos el operador ==
}

// Operador de inserción en flujo (impresión)
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
