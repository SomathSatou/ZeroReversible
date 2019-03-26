#include <iostream>
#include <vector>
#include <array>

#include "graphe.h"

using namespace std;


Noeud::Noeud(bool _final_){
    _ID_ = id++;
    final = _final_;
}

Noeud::Noeud(){
    _ID_ = id++;
    final = false;
}

Arc::Arc(char _symbole_, Noeud _dest_){
    symbole = _symbole_;
    destination = &_dest_;
}

Graphe::Graphe(Noeud racine){
    initial = racine;
    //contruire la matrice
    //ajout des
}

bool Graphe::checkDerterminisme(){
    // verification que le graphe est déterministe
    return true;
}

bool Graphe::checkUniqFinal(){
    // verifie qu'il y a bien que un état final
    return true;
}

bool Graphe::checkZeroRever(){
    // verifie qu'il n'y a pas deux (ou plusieurs) arc avec la même valeurs menant au même noeud
    return true;
}

void Graphe::fusionNoeud(Noeud &A, Noeud &B){
    //fonction permettant de fusionner deux noeud en ajoutant les arc qui vont et qui vienne sur B a A puis en supprimant B
}

void Graphe::rendreZR(){
    // se sert des fonction précédente pour rendre le graphe zero_réversible
}
