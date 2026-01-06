#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
    protected:
        Point2D* vs; // Puntero a array de 4 vértices

    public:
        static const int N_VERTICES = 4;

        // Constructores y Destructor
        Rectangle();
        Rectangle(std::string color, Point2D* vertices);
        Rectangle(const Rectangle &r); // Constructor de copia
        virtual ~Rectangle();          // Destructor

        // Métodos específicos
        Point2D get_vertex(int ind) const;
        Point2D operator[](int ind) const;
        virtual void set_vertices(Point2D* vertices);
        Rectangle& operator=(const Rectangle &r); // Operador de asignación

        // Implementación de métodos de Shape
        double area() const override;
        double perimeter() const override;
        void translate(double incX, double incY) override;
        virtual void print() override;

        // Sobrecarga de <<
        friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

    private:
        static bool check(Point2D* vertices);
};

#endif
