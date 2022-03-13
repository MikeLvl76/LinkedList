#ifndef LISTE_H

#define LISTE_H

#include <string>

template <typename T> class Element;
template <typename T> class Iterateur;

template <typename T> class Liste {
public:
   // constructeur
   Liste();
   Liste(Liste<T>& l); // constructeur par recopie 
   ~Liste(); // destructeur
   Liste<T>& operator=(const Liste<T>& l); // opérateur d'affectation

   // ajouter s a la fin de la liste
   void ajouter(const T &s);

   // ajouter s avant la position pos
   void inserer(Iterateur<T> &pos, const T &s);

   // supprimer l'element a la position pos
   void supprimer(Iterateur<T> &pos);

   // la premiere position
   Iterateur<T> debut() const;

   // la fin de la liste (apres la derniere position)
   Iterateur<T> fin() const;

private:
   // pointeurs vers le premier et le dernier element
   Element<T>* premier;
   Element<T>* dernier;
};


template <typename T> class Iterateur {
public:
   // constructeur
   Iterateur();

   // retourne la valeur dans cette position
   T& operator*();

   // avance a la position suivante
   Iterateur<T> operator++(int);
   Iterateur<T>& operator++();

   // recule a la position precedente
   Iterateur<T> operator--(int);
   Iterateur<T>& operator--();

   // compare deux iterateurs
   bool operator==(const Iterateur<T> p);
   bool operator!=(const Iterateur<T> p);

private:
   // pointeur vers l'element courant
   Element<T>* position;

   // pointeur vers le dernier element de la liste
   Element<T>* dernier;

friend class Liste<T>;
};

#endif
