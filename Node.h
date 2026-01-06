#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T> 
class Node {
    public:
        // --- Atributos ---
        
        /** El elemento almacenado de tipo genérico T */
        T data;           

        /** Puntero al siguiente nodo de la secuencia (o nullptr si es el último) */
        Node<T>* next;    

        // --- Métodos ---

        /** * Método constructor. 
         * Si no se proporciona 'next', por defecto será nullptr.
         */
        Node(T data, Node<T>* next = nullptr) {
            this->data = data;
            this->next = next;
        }

        /**
         * Sobrecarga global del operador <<.
         * Imprime el atributo data del nodo.
         */
        friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
            out << node.data;
            return out;
        }
};

#endif
