#include "Drawing.h"
#include "ListArray.h" // O ListLinked.h según prefieras
#include "Circle.h"
#include "Square.h"

/**
 * Constructor: Instancia la implementación concreta de la lista.
 */
Drawing::Drawing() {
    // Usamos ListArray por su eficiencia en acceso directo
    shapes = new ListArray<Shape*>();
}

/**
 * Destructor: Libera la memoria de la lista.
 */
Drawing::~Drawing() {
    delete shapes;
}

/**
 * Añade al frente (posición 0).
 */
void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

/**
 * Añade al fondo (última posición).
 */
void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

/**
 * Recorre la lista y usa el polimorfismo para llamar a print().
 */
void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print();
        std::cout << std::endl;
    }
}

/**
 * Filtra círculos usando dynamic_cast.
 */
double Drawing::get_area_all_circles() {
    double total_area = 0;
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        // Intentamos convertir el puntero Shape* a Circle*
        Circle* c = dynamic_cast<Circle*>(s);
        if (c != nullptr) {
            total_area += c->area();
        }
    }
    return total_area;
}

/**
 * Mueve solo los cuadrados usando dynamic_cast.
 */
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        // Intentamos convertir el puntero Shape* a Square*
        Square* sq = dynamic_cast<Square*>(s);
        if (sq != nullptr) {
            sq->translate(incX, incY);
        }
    }
}
