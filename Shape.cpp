#include "Shape.h"

// Constructor por defecto: rojo
Shape::Shape() {
    color = "red";
}

// Constructor con parámetros y validación
Shape::Shape(std::string color) {
    if (color == "red" || color == "green" || color == "blue") {
        this->color = color;
    } else {
        throw std::invalid_argument("Color no válido. Debe ser red, green o blue.");
    }
}

// Getter
std::string Shape::get_color() const {
    return color;
}

// Setter con validación
void Shape::set_color(std::string c) {
    if (c == "red" || c == "green" || c == "blue") {
        color = c;
    } else {
        throw std::invalid_argument("Color no válido. Debe ser red, green o blue.");
    }
}
