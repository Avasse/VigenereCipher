#include <iostream>
#include <fstream>

std::string decrypt(std::string text, std::string key){
    std::string decryptedText;
    int i = 0;
    for(char c : text) {
        if (isalpha(c)) {
            decryptedText += ((c - 'A') - (key[i] - 'A') + 26) % 26 + 'A';
            i++;
            if (i > key.length()) i = 0;
        } else decryptedText += c;
    }
    return decryptedText;
}

int main() {
    std::string texte, clef;
    std::cout << "Entrez le texte a dechiffrer" << std::endl;
    getline(std::cin,texte);
    std::cout << "Entrez la clef" << std::endl;
    std::cin >> clef;

    std::ofstream outfile ("../texteClair.txt");
    outfile << decrypt(texte,clef) << std::endl;
    outfile.close();
    return 0;
}