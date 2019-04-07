#include <iostream>
#include <vector>
#include <array>

#include "graphe.h"

using namespace std;

int main()
{
    std::vector<std::string> dict;
    dict.push_back("aa");
    dict.push_back("ab");
    dict.push_back("aab");
    //dict.push_back("ba");
    //dict.push_back("aaa");
    //dict.push_back("a");



    std::vector<char> alpha;
    alpha.push_back('a');
    alpha.push_back('b');

    Graphe test = Graphe(alpha,dict);

    test.rendreZR(20);
    std::cout<<test.affichageUI()<<std::endl;
    return 0;

}

