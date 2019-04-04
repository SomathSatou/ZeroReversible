#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>

#include "graphe.h"

using namespace std;

std::vector<int> Graphe::getFinals() const
{
    return finals;
}

void Graphe::setFinals(const std::vector<int> &value)
{
    finals = value;
}

std::vector<std::vector<char> > Graphe::getMatrice_adj() const
{
    return matrice_adj;
}

void Graphe::setMatrice_adj(const std::vector<std::vector<char> > &value)
{
    matrice_adj = value;
}

Graphe::Graphe(std::vector<char> alphabet,std::vector<std::string> dictionaire){
    this->alphabet = alphabet;
    this->dictionaire = dictionaire;
    this->matrice_adj.clear();
    int nbrEtatDepart = 1; // etat S
    for( std::string elt : this->dictionaire){
        nbrEtatDepart += elt.size();
    }
    for (int n = 0;n<nbrEtatDepart;n++){
        this->matrice_adj.push_back(std::vector<char>(nbrEtatDepart,'$'));
    }
    int etat = 0;
    for ( std::string mot : this->dictionaire){
        for (int j= 0;j<mot.size();j++){
            if(j==0){
                etat++;
                this->matrice_adj.at(0).at(etat)=mot[j];
                this->matrice_adj.at(etat).at(0)=mot[j];
            }else{
                this->matrice_adj.at(etat).at(etat+1)=mot[j];
                this->matrice_adj.at(etat+1).at(etat)=mot[j];
                etat++;
            }
        }
        this->finals.push_back(etat);

    }
    this->affichage();
    for(int elt : finals){
        std::cout << elt << " ";
    }
    std::cout<<std::endl;
    for(std::tuple<int, int> elt : listeArc()){
        std::cout<<"arc "<<std::get<0>(elt)<<"->"<<std::get<1>(elt)<<std::endl;
    }

}

void Graphe::affichage()
{
    for(int i = 0;i<this->matrice_adj.size();i++){
        for(int j = 0; j<this->matrice_adj.at(i).size();j++){
            std::cout << this->matrice_adj.at(i).at(j)<<" ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::tuple<int, int>> Graphe::listeArc()
{
    std::vector<std::tuple<int, int>> ret;
    for(int i = this->matrice_adj.size()-1;i>=0;i--)
        for( int j = this->matrice_adj.size()-1;j>i;j--)
            if(this->matrice_adj.at(i).at(j)!='$')
                ret.push_back(std::make_tuple(i,j));
    return ret;

}

bool Graphe::checkDerterminisme(std::vector<int> &fusion){
    // verification que le graphe est déterministe
    std::vector<char> listSymbole;
    std::vector<int> premiereItSymb;
    fusion.clear();
    bool ret = true;
    for(int i = this->matrice_adj.size()-1;i>=0;i--){
        for( int j = this->matrice_adj.size()-1;j>i;j--){
            if(this->matrice_adj.at(i).at(j)!='$'){
                if(!(listSymbole.empty())&&fusion.empty()){
                    for(int k =0;listSymbole.size()>k;k++){
                        if( this->matrice_adj.at(i).at(j) == listSymbole.at(k)) {
                                ret = false;
                                fusion.push_back(j);
                                fusion.push_back(premiereItSymb.at(k));
                        }
                    }
                    if(ret){
                            listSymbole.push_back(this->matrice_adj.at(i).at(j));
                            premiereItSymb.push_back(j);
                        }

                } else {
                    listSymbole.push_back(this->matrice_adj.at(i).at(j));
                    premiereItSymb.push_back(j);
                }
            }
        }
        listSymbole.clear();
        premiereItSymb.clear();
        }
    return ret;
}
bool Graphe::checkUniqFinal(std::vector<int> &fusion){
    // verifie qu'il y a bien que un état final
    fusion.clear();
    if(this->finals.size()>1){
        for(int elt : this->finals)
            fusion.push_back(elt);
        return false;}
    return true;
}

bool Graphe::checkZeroRever(std::vector<int> &fusion){
    // verifie qu'il n'y a pas deux (ou plusieurs) arc avec la même valeurs menant au même noeud
    return true;
}

std::vector<std::vector<char>> Graphe::fusionNoeud(std::vector<int> &fusion){
    //fonction permettant de fusionner deux noeud en ajoutant les arc qui vont et qui vienne sur B a A puis en supprimant B4
    std::vector<std::vector<char>> ret;
    for(int it = 0 ; it<fusion.size(); it++){
        std::cout<<fusion.at(it);
    }
    std::cout<<std::endl;
    int rece = fusion.at(0);
        int supp = fusion.at(1);
        for(int i = 0;i<this->matrice_adj.size();i++){
            ret.push_back(std::vector<char>(this->matrice_adj.size(),' '));
            for(int j = 0; j<this->matrice_adj.at(i).size();j++){
                ret.at(i).at(j) = this->matrice_adj.at(i).at(j);
                if(i==supp){
                    ret.at(rece).at(j)=this->matrice_adj.at(i).at(j);
                    //ret.at(j).at(rece)=this->matrice_adj.at(j).at(i);
                }
            }
        }
        std::cout<<"la copie c'est ok"<<std::endl;
        for(int i = 0;i<ret.at(rece).size();i++){
            ret.at(rece).at(i) = ret.at(supp).at(i);
        }
        std::cout<<"la premier supression aussi"<<std::endl;
        ret.erase(ret.begin()+supp);
        for(int i = 0;i<ret.at(0).size();i++){
            ret.at(i).erase(ret.at(i).begin()+supp);
        }
        fusion.erase(fusion.begin()+1);
        std::cout<<"arriver des finalistes"<<std::endl;
        std::vector<int> newFinals;
        for(int m =0;m< this->finals.size();m++){
            if(this->finals.at(m)>supp){
                newFinals.push_back(this->finals.at(m)-1);
            }
            if(this->finals.at(m)<supp){
                newFinals.push_back(this->finals.at(m));
            }
        }
         this->setFinals(newFinals);
            fusion=this->getFinals();
            for(int it = 0 ; it<fusion.size(); it++){
                std::cout<<fusion.at(it);
            }
            std::cout<<std::endl;

    return ret;
}

void Graphe::rendreZR(){
    // se sert des fonction précédente pour rendre le graphe zero_réversible
    //création du grapphe
    std::vector<int>  noeudFusion;
    bool fin = true;
    int compt = 0;
    while(fin&&compt<20){
    if (checkDerterminisme(noeudFusion)){
        if (checkUniqFinal(noeudFusion)){
            if( checkZeroRever(noeudFusion)){
                    fin = false;
            }else{
                std::cout<< "non ZR"<<std::endl;
                this->matrice_adj = this->fusionNoeud(noeudFusion);
            }
        }else{
            std::cout<< "non one final"<<std::endl;
            this->matrice_adj = this->fusionNoeud(noeudFusion);
        }
    }else{
    std::cout<< "non deterministe"<<std::endl;
    this->setMatrice_adj(this->fusionNoeud(noeudFusion));
    }
    this->affichage();
    compt++;
    noeudFusion.clear();
    }
}
