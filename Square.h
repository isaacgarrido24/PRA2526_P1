#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdexcept>
#include "Rectangle.h"

class Square : public Rectangle {
    private:
        /** Comprueba si los 4 vértices forman un cuadrado (lados iguales) */
        static bool check(Point2D* vertices);

    public:
        /** Constructor por defecto: color rojo, vértices (-1,1) a (-1,-1) */
        Square();

        /** Constructor con parámetros y validación de cuadrado */
        Square(std::string color, Point2D* vertices);

        /** Sobreescritura de set_vertices con validación de cuadrado */
        void set_vertices(Point2D* vertices) override;

        /** Sobreescritura de print para mostrar info de Square */
        void print() override;

        /** Sobrecarga del operador << para Square */
        friend std::ostream& operator<<(std::ostream &out, const Square &s);
};

#endif
