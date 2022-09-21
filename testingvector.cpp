#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>

//this is the class word. We will be using it to store the word and the frequency of the word in the text
class word 
{
public:
    std::string realword;
    int frequency;

    word() 
    {
        realword = " ";
        frequency = 0;
    }
    word(std::string c) 
    {
        realword = c;
        frequency = 1;
    }
    void addfrequency() 
    {
        frequency += 1;
    }
};

void createwordvector(std::vector<std::string> strings)
{
    std::vector <word> words;
    std::string wordd = "";

    std::cout << "The text entered has " << strings.size() << " lines. " << std::endl;
    
    for (int i = 0; i < strings.size(); i++) 
    {
        std::cout << "Operating on " << strings[i] << std::endl;
        char *charpointer = &strings[i][0]; //pointer to the start of the word

        while (*charpointer != '\0')
        {
            if ( *charpointer == ' ')
            {
                std::cout << "We are now here and the size of wordvectorofthisstring is "<< words.size() << std::endl;
                for (int i = 0; ((words.size() == 0) ? (i <= words.size()) : (i < words.size())); i++) {
                    if (words.size() == 0) 
                    {
                        word newword(wordd);
                        words.push_back(newword);
                        wordd = "";
                    }
                    else 
                    {
                        bool alreadyin = false;
                        for (int k = 0; k < words.size(); k++) 
                        {
                            if (wordd == words[k].realword) 
                            {
                                words[k].addfrequency();
                                alreadyin = true;
                            }
                        }

                        if (alreadyin == false) 
                        {
                            word newword(wordd);
                            words.push_back(newword);
                            wordd = "";
                        }
                    }
                }
            }
            else 
            {
                std::cout << "Adding a character to our word" << std::endl;
                wordd = wordd + (*charpointer);
            }
        }

        charpointer++;
    }
    
    
    std::cout << "UNIQUE WORDS FOUND IN THE STRING: " << words.size() << std::endl;

    for (int i = 0; i < words.size(); i++) 
    {
        std::cout << "Word " << std::setw(2) << std::left << i << " : " << std::setw(30) << std::left << words[i].realword << " Frequency : " << words[i].frequency << std::endl;
    }
}

int main() {

    std::cout << "Please input the first string to be compared " << std::endl;
    std::vector<std::string> firststring;

    std::ifstream myfile;
    myfile.open("TEXTDATA.txt");

    if (myfile.is_open()) 
    {
        while (myfile) 
        { // equivalent to myfile.good()
            std::string myline;
            std::getline(myfile, myline);
            //std::cout << myline << '\n';
            firststring.push_back(myline);
        }

        for (int i = 0; i < firststring.size(); i++) 
        {
            std::cout << firststring[i] << std::endl;
        }
    }
    else 
    {
        std::cout << "Couldn't open file\n";
    }
  
    createwordvector(firststring);
}