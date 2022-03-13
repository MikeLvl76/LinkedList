#include <iostream>
#include <string>
#include "templateListe.cc"

using namespace std;

int main(){

    Liste<int> l1; // liste d'entiers
    Liste<string> l2; // liste de chaine de caractère

    //iterateurs pour parcourir les listes
    Iterateur<int> i; 
    Iterateur<string> i2;

    //construction des listes
    l1.ajouter(0);
    l1.ajouter(1);
    l1.ajouter(2);
    l1.ajouter(3);

    l2.ajouter("Coucou");
    l2.ajouter("Bonjour");
    l2.ajouter("Salut");
    l2.ajouter("Bienvenue");

    // affichage des listes
    cout << "----- Liste 1 -----" << endl;
    for(i = l1.debut(); i != l1.fin();  ++i)
      cout << *i << endl;
    
    cout << "----- Liste 2 -----" << endl;
    for(i2 = l2.debut(); i2 != l2.fin(); ++i2)
      cout << *i2 << endl;

    cout << "----- Fin -----" << endl;

    // modification des listes 
    i = l1.debut();
    ++i;++i;++i;
    cout << "On insere un element dans la liste 1 !" << endl;
    l1.inserer(i, 4); // on insère avant la position i

    i2 = l2.debut();
    ++i2;++i2;--i2;
    cout << "On supprime un element de la liste 2 !" << endl;
    l2.supprimer(i2); // on supprime à la position i

    // affichage des listes
    cout << "----- Liste 1 modifiee -----" << endl;
    for(i = l1.debut(); i != l1.fin();  ++i)
      cout << *i << endl;
    
    cout << "----- Liste 2 modifiee -----" << endl;
    for(i2 = l2.debut(); i2 != l2.fin(); ++i2)
      cout << *i2 << endl;

    cout << "----- Fin -----" << endl;

    // listes copiées
    cout << "On copie les listes !" << endl;
    Liste<int> l3(l1);
    Liste<string> l4 = l2;

    // affichage des listes copiées
    cout << "----- Liste 3 -----" << endl;
    for(Iterateur<int> i4 = l3.debut(); i4 != l3.fin();  ++i4)
      cout << *i4 << endl;
    
    cout << "----- Liste 4 -----" << endl;
    for(Iterateur<string> i4 = l4.debut(); i4 != l4.fin(); ++i4)
      cout << *i4 << endl;

    cout << "----- Fin -----" << endl;

    return 0;
}
