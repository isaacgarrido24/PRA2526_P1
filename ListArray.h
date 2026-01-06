#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
    private:
        T* arr;                // Puntero al array dinámico
        int max;               // Capacidad actual del array
        int n;                 // Número de elementos actuales
        static const int MINSIZE = 2; // Tamaño mínimo inicial

        // Método privado para redimensionar el array cuando esté lleno
        void resize(int new_size) {
            T* new_arr = new T[new_size];
            for (int i = 0; i < n; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            max = new_size;
        }

    public:
        // Constructor
        ListArray() {
            arr = new T[MINSIZE];
            max = MINSIZE;
            n = 0;
        }

        // Destructor
        ~ListArray() {
            delete[] arr;
        }

        // Devuelve el elemento en la posición pos
        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición no válida");
            }
            return arr[pos];
        }

        // Busca el elemento e y devuelve su índice
        int search(T e) override {
            for (int i = 0; i < n; i++) {
                if (arr[i] == e) return i;
            }
            return -1;
        }

        // Inserta un elemento en una posición específica
        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición fuera de rango");
            }

            // Si el array está lleno, duplicamos su capacidad
            if (n == max) {
                resize(max * 2);
            }

            // Desplazamos los elementos a la derecha para hacer hueco
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }

            arr[pos] = e;
            n++;
        }

        void append(T e) override {
            insert(n, e);
        }

        void prepend(T e) override {
            insert(0, e);
        }

        // Elimina y devuelve el elemento en pos
        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }

            T element = arr[pos];

            // Desplazamos los elementos a la izquierda para cerrar el hueco
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }

            n--;
            
            // Opcional: Reducir el tamaño del array si sobra mucho espacio (p.e., al 25% de uso)
            // if (n < max / 4 && max > MINSIZE) resize(max / 2);

            return element;
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }

        // Sobrecarga del operador [] para acceso directo
        T operator[](int pos) {
            return get(pos);
        }

        // Sobrecarga del operador << para imprimir la lista
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &la) {
            out << "ListArray [";
            for (int i = 0; i < la.n; i++) {
                out << la.arr[i] << (i < la.n - 1 ? ", " : "");
            }
            out << "]";
            return out;
        }
};

#endif
