#ifndef GRAPHE_H
#define GRAPHE_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <iterator>

class Graphe{
    // le caractère § sert pour indiquer qu'il n'existe pas d'arc entre deux état
private :
    std::vector<std::vector<std::vector<char>>> matrice_adj;
    std::vector<char> alphabet;
    std::vector<std::string> dictionaire;
    std::vector<int> finals; //liste des états finaux

public :
    Graphe(std::vector<char>,std::vector<std::string>);
    void affichage();
    std::vector<std::tuple<int, int>> listeArc();
    bool checkDerterminisme(std::vector<int>&);
    bool checkUniqFinal(std::vector<int>&);
    bool checkZeroRever(std::vector<int>&);
    std::vector<std::vector<std::vector<char> > > fusionNoeud(std::vector<int>&);
    std::vector<char> Union(std::vector<char>,std::vector<char>);

    void rendreZR();



    std::vector<int> getFinals() const;
    void setFinals(const std::vector<int> &value);
    std::vector<std::vector<std::vector<char> > > getMatrice_adj() const;
    void setMatrice_adj(const std::vector<std::vector<std::vector<char> > > &value);
};

#endif // GRAPHE_H
