#include "Square.h"

/**
 * Validación específica para cuadrados:
 * Comprueba que las 4 distancias entre vértices consecutivos sean iguales.
 */
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    // Usamos un margen de error pequeño para comparaciones de double si fuera necesario,
    // pero para la práctica basta con la igualdad directa.
    return (d01 == d12 && d12 == d23 && d23 == d30);
}

/**
 * Constructor por defecto.
 * Inicializa Rectangle y luego redefine los vértices específicos del cuadrado.
 */
Square::Square() : Rectangle() {
    this->color = "red";
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

/**
 * Constructor con parámetros.
 * Llama al constructor de Rectangle pero añade la validación de Square.
 */
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no conforman un cuadrado válido.");
    }
}

/**
 * Modifica los vértices asegurando que la nueva forma siga siendo un cuadrado.
 */
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no conforman un cuadrado válido.");
    }
    // Si es válido, usamos la lógica de la clase base para copiarlos
    Rectangle::set_vertices(vertices);
}

/**
 * Redefinición de print usando el operador << de Square.
 */
void Square::print() {
    std::cout << *this;
}

/**
 * Sobrecarga de salida. 
 * Reutiliza el formato de Rectangle pero identifica que es un [Square].
 */
std::ostream& operator<<(std::ostream &out, const Square &s) {
    out << "[Square: color = " << s.color 
        << "; v0 = " << s.vs[0] << "; v1 = " << s.vs[1] 
        << "; v2 = " << s.vs[2] << "; v3 = " << s.vs[3] << "]";
    return out;
}
