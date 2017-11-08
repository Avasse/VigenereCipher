#include <iostream>
#include <fstream>

std::string encrypt(std::string text, std::string key){
    std::string cryptedText;
    int i = 0;
    for(char c : text) {
        if (isalpha(c)) {
            cryptedText += (c - 'A' + key[i] - 'A') % 26 + 'A';
            i++;
            if (i > key.length()) i = 0;
        } else cryptedText += c;
    }
    return cryptedText;
}

int main() {
    std::string texte, clef;
    std::cout << "Entrez le texte a chiffrer" << std::endl;
    getline(std::cin,texte);
    std::cout << "Entrez la clef" << std::endl;
    std::cin >> clef;

    std::ofstream outfile ("../texteChiffre.txt");
    outfile << encrypt(texte,clef) << std::endl;
    outfile.close();
    return 0;
}