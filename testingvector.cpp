#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>

class word {
public:
    std::string realword;
    int frequency;
    word() {
        realword = " ";
        frequency = 0;
    }
    word(std::string c) {
        realword = c;
        frequency = 1;
    }
    void addfrequency() {
        frequency += 1;
    }
};

void createwordvector(std::vector<std::string> strings)
{
    std::vector <word> wordsvectorofthisstring;
    std::string wordd = "";
    for (int i = 0; i < strings.size(); i++) {
        std::string str = strings[i];
        for (auto x : str)
        {
            if (x == ' ')
            {
                std::cout << "We are now here and the size of wordvectorofthisstring is "<< wordsvectorofthisstring.size() << std::endl;
                for (int i = 0; ((wordsvectorofthisstring.size() == 0) ? (i <= wordsvectorofthisstring.size()) : (i < wordsvectorofthisstring.size())); i++) {
                    if (wordsvectorofthisstring.size() == 0) {
                        word newword(wordd);
                        wordsvectorofthisstring.push_back(newword);
                        wordd = "";
                    }
                    else {
                        bool alreadyin = false;
                        for (int k = 0; k < wordsvectorofthisstring.size(); k++) {
                            if (wordd == wordsvectorofthisstring[k].realword) {
                                wordsvectorofthisstring[k].addfrequency();
                                alreadyin = true;
                            }
                        }
                        if (alreadyin == false) {
                            word newword(wordd);
                            wordsvectorofthisstring.push_back(newword);
                            wordd = "";
                        }
                    }
                }
            }
            else {
                wordd = wordd + x;
            }
        }
    }
    std::cout << "We are now outputting the words in the vector wordsvectorofthisstring of size " << wordsvectorofthisstring.size() << std::endl;
    for (int i = 0; i < wordsvectorofthisstring.size(); i++) {
        std::cout << "Word " << std::setw(2) << std::left << i << " : " << std::setw(30) << std::left << wordsvectorofthisstring[i].realword << " Frequency : " << wordsvectorofthisstring[i].frequency << std::endl;
    }
}

int main() {

    std::cout << "Please input the first string to be compared " << std::endl;
    std::vector<std::string> firststring;

    std::ifstream myfile;
    myfile.open("TEXTDATA.txt");
    if (myfile.is_open()) {
        while (myfile) { // equivalent to myfile.good()
            std::string myline;
            std::getline(myfile, myline);
            //std::cout << myline << '\n';
            firststring.push_back(myline);
        }
        for (int i = 0; i < firststring.size(); i++) {
            std::cout << firststring[i] << std::endl;
        }
    }
    else {
        std::cout << "Couldn't open file\n";
    }
  
    createwordvector(firststring);
}