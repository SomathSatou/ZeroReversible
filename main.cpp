#include <iostream>
#include <vector>
#include <array>

#include "graphe.h"

using namespace std;

int main()
{
    std::vector<std::string> dict;
    dict.push_back("ab");
    dict.push_back("aa");
    dict.push_back("b");
    dict.push_back("bb");
    dict.push_back("aaa");

    std::vector<char> alpha;
    alpha.push_back('a');
    alpha.push_back('b');

    Graphe test = Graphe(alpha,dict);

    test.rendreZR();
    std::cout<<test.affichageUI()<<std::endl;
    return 0;

}

