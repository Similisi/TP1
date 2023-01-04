#include "Date.h"

Date::Date():_jour(1),_mois(1),_annee(0){}
Date::Date(int j,int m, int a):_jour(j),_mois(m),_annee(a){}
Date::Date(std::string date){
    std::vector<std::string> tableauDate;
    char delimiteur = '/';
    decoupageString(date,delimiteur,tableauDate);
    _jour = std::stoi(tableauDate[0],nullptr);
    _mois = std::stoi(tableauDate[1],nullptr);
    _annee = std::stoi(tableauDate[2],nullptr);
}

void Date::decoupageString(std::string const &str, const char delim, std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;
 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

std::string Date::affichageDate(){
    return std::to_string(_jour)+"/"+std::to_string(_mois)+"/"+std::to_string(_annee);
}