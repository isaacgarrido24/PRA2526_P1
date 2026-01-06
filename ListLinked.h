#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        /** Puntero al primer nodo de la secuencia */
        Node<T>* first; 

        /** Número de elementos que contiene la lista */
        int n;          

    public:
        /**
         * Constructor: Inicializa la lista vacía.
         */
        ListLinked() {
            first = nullptr;
            n = 0;          
        }

        /**
         * Destructor: Libera la memoria de todos los nodos.
         */
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;              
                first = aux;               
            }
        }

        /**
         * Sobrecarga del operador []: Acceso al elemento en pos.
         */
        T operator[](int pos) {
            return get(pos);
        }

        /**
         * Sobrecarga del operador <<: Imprime la lista completa.
         */
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            Node<T>* aux = list.first;
            out << "[";
            while (aux != nullptr) {
                out << aux->data;
                if (aux->next != nullptr) out << ", ";
                aux = aux->next;
            }
            out << "]";
            return out;
        }

        // --- Implementación de los métodos de List<T> ---

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición fuera de rango");
            }

            if (pos == 0) {
                first = new Node<T>(e, first);
            } else {
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                prev->next = new Node<T>(e, prev->next);
            }
            n++;
        }

        void append(T e) override {
            insert(n, e);
        }

        void prepend(T e) override {
            insert(0, e);
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }

            Node<T>* toDelete;
            T data;

            if (pos == 0) {
                toDelete = first;
                first = first->next;
            } else {
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                toDelete = prev->next;
                prev->next = toDelete->next;
            }

            data = toDelete->data;
            delete toDelete;
            n--;
            return data;
        }

        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición no válida");
            }
            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }

        int search(T e) override {
            Node<T>* aux = first;
            for (int i = 0; i < n; i++) {
                if (aux->data == e) return i;
                aux = aux->next;
            }
            return -1;
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }
};

#endif
