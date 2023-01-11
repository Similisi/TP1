#ifndef DATE_H
#define DATE_H
#include<string>
#include<vector>
#include<iostream>
class Date{
public:
    Date();
    Date(int j,int m, int a);
    Date(std::string date);
    void decoupageString(std::string const &str, const char delim, std::vector<std::string> &out);
    std::string affichageDate();
private:
    int _jour;
    int _mois;
    int _annee;
};
#endif