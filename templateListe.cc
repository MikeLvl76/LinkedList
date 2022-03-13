#include "templateListe.h"
#include <iostream>

using namespace std;

template <typename T> class Element {
public:
   // constructeur
   Element(const T &s);

private:
   T valeur;

   // pointeurs vers les voisins
   Element<T>* precedent;
   Element<T>* suivant;

friend class Liste<T>;
friend class Iterateur<T>;
};

// constructeurs
template <typename T> Element<T>::Element(const T &s) { // constructeur par recopie

   valeur = s;
   precedent = suivant = NULL;

}

template <typename T> Iterateur<T>::Iterateur() { // constructeur par défaut

   position = dernier = NULL;

}

// fonctions
template <typename T> T& Iterateur<T>::operator*(){ // renvoie la valeur

   return this -> position -> valeur;

}

template <typename T> Iterateur<T> Iterateur<T>::operator++(int){ // opérateur vers le suivant

   Iterateur<T> it = *this;
   it.position = it.position -> suivant;
   return *this;

}

template <typename T> Iterateur<T>& Iterateur<T>::operator++(){

   position = position -> suivant;
   return *this;

}

template <typename T> Iterateur<T> Iterateur<T>::operator--(int){ // opérateur vers le précedent

   Iterateur<T> it = *this;

   if(it.position == NULL){

      it.position = dernier;

   } else {

      it.position = it.position -> precedent;

   }
   return *this;
}

template <typename T> Iterateur<T>& Iterateur<T>::operator--(){

   if(position == NULL){

      position = dernier;

   } else {

      position = position -> precedent;

   }
   return *this;
}

template <typename T> bool Iterateur<T>::operator==(const Iterateur<T> p){ // compare deux itérateurs

   return position == p.position;

}

template <typename T> bool Iterateur<T>::operator!=(const Iterateur<T> p){ // compare deux itérateurs

   return position != p.position;

}

template <typename T> Liste<T>& Liste<T>::operator=(const Liste<T>& l){ // opérateur d'affectation

   Iterateur<T> iterateur;
   
   if(this != &l){

      for(iterateur = l.debut(); iterateur != l.fin(); ++iterateur){
         supprimer(iterateur);
         ajouter(iterateur.position -> valeur);
      }

   }
   return *this;

} 

// constructeur par défaut
template <typename T> Liste<T>::Liste() {

   premier = dernier = NULL;

}

// constructeur par recopie
template <typename T> Liste<T>::Liste(Liste<T> &l){

   Iterateur<T> it;
   Iterateur<T> it2 = debut();
   premier = l.premier;
   dernier = l.dernier;
   for(it = l.debut(); it != l.fin(); ++it){
      it2.position = it.position;
      ++it2;
   }
      
}

// destructeur
template <typename T> Liste<T>::~Liste(){

   Iterateur<T> it;

   // tant que la liste n'est pas vide on supprime 
   while(this != NULL){

      supprimer(it);
      ++it;

   }

}

// ajouter s a la fin de la liste
template <typename T> void Liste<T>::ajouter(const T &s){

   Element<T>* e = new Element<T>(s);

   if(premier != NULL){
      
      e->precedent = dernier;
      dernier->suivant = e;
      dernier = e;
      
   } else {
     
      premier = dernier = e;
   
   }
}

// ajouter s avant la position pos
template <typename T> void Liste<T>::inserer(Iterateur<T>& pos, const T &s){

   Element<T>* nouv = new Element<T>(s);

   if(pos.position == premier){

      //Si la position est sur la tête 
      nouv -> suivant = premier;
      premier -> precedent = nouv;
      premier = nouv;

   } else {

      //Si la position est autre part
      nouv -> suivant = pos.position;
      nouv -> precedent = pos.position -> precedent;
      nouv -> precedent -> suivant = nouv;
      nouv -> suivant -> precedent = nouv;

   }
   if(premier == NULL){

      //Si la liste est vide
      ajouter(s);

   }
}

// supprimer l'element a la position pos
template <typename T> void Liste<T>::supprimer(Iterateur<T> &pos){

   if(pos.position == premier && pos.position == dernier){
      
      //Si la liste n'a qu'un seul élément
      premier = NULL;
      delete premier;
      dernier = NULL;
      delete dernier;

   } else if(pos.position == premier){

      //Si la position est sur la tête
      premier -> suivant -> precedent = NULL;
      delete premier -> suivant -> precedent;
      premier = premier -> suivant;

   } else if (pos.position == dernier){

      //Si la position est sur le dernier
      dernier -> precedent -> suivant = NULL;
      delete dernier -> precedent -> suivant;
      pos.position = NULL;
      delete pos.position;

   } else {

      //Si la position est autre part
      pos.position -> precedent -> suivant = pos.position -> suivant;
      pos.position -> suivant -> precedent = pos.position -> precedent;
      delete pos.position;

   }
}

template <typename T> Iterateur<T> Liste<T>::debut() const {

   Iterateur<T> it;
   it.position = premier;
   it.dernier = dernier;
   return it;

}

template <typename T> Iterateur<T> Liste<T>::fin() const {

   Iterateur<T> it;
   it.position = NULL;
   it.dernier = dernier;
   return it;

}
