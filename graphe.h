#ifndef GRAPHE_H
#define GRAPHE_H

#include <iostream>
#include <vector>
#include <array>

class Arc;

class Noeud{
private :
    static int id;
    int _ID_;
    bool final;
    std::vector<Arc> arcs;

public:
    Noeud(bool _final_);
    Noeud();
};

class Arc{
private :
    char symbole;
    Noeud* destination;

public :
    Arc(char _symbole_, Noeud _dest_);
};

class Graphe{
    // le caractère § sert pour indiquer qu'il n'existe pas d'arc entre deux état
private :
    std::vector<std::vector<char>> matrice_adj;
    Noeud initial;

public :
    Graphe(Noeud racine);
    bool checkDerterminisme();
    bool checkUniqFinal();
    bool checkZeroRever();
    void fusionNoeud(Noeud& A,Noeud& B);
    void rendreZR();



};

#endif // GRAPHE_H
