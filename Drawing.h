#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "List.h"
#include "Shape.h"

class Drawing {
    private:
        /** Lista de punteros a figuras (interfaz polimórfica) */
        List<Shape*>* shapes;

    public:
        /** Constructor y Destructor */
        Drawing();
        ~Drawing();

        /** Gestión de figuras */
        void add_front(Shape* shape);
        void add_back(Shape* shape);
        void print_all();

        /** Operaciones específicas con filtrado de tipos */
        double get_area_all_circles();
        void move_squares(double incX, double incY);
};

#endif
