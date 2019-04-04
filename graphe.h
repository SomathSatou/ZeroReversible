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
    std::vector<std::vector<char>> matrice_adj;
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
    void fusionNoeud(std::vector<int>&);
    void rendreZR();



};

#endif // GRAPHE_H
