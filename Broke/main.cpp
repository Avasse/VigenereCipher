#include <iostream>
#include <string>
#include <iomanip>

int getKeyLenght(std::string text){
    //On suppose que la taille de la clef est <=10;
    int i, j, k;
    double occured = 0, ind = 0, indFinal = 0, kFinal = 0, tailleTexte = text.length();
    std::string textTest;
    for (k = 2; k <= 10; k++){
        for (i = 1; i <= 26; i++){
            for (j = 0; j <= tailleTexte; j+=k) {
                int letterText = text[j] - 96;
                if (letterText == i) {
                    occured ++;
                }
            }
            ind += (occured / tailleTexte) * ((occured - 1) / (tailleTexte - 1));
            occured = 0;
        }
        if(indFinal < ind){
            indFinal = ind;
            kFinal = k;
        }
    }
    std::cout << "Indice : " << indFinal << " Taille Clef : " << kFinal << std::endl;
    return k;
}

int main() {
    std::string line, text, cleanedText;
    std::cout << "Entrez le texte a dechiffrer : " << std::endl;
    getline(std::cin, text);

    std::ifstream inFile;
    inFile.open(inFileName);//open the input file

    stringstream strStream;
    strStream << inFile.rdbuf();//read the file
    string str = strStream.str();//str holds the content of the file

    cout << str << endl;

    for(char c : text) {
        if (isalpha(c)) {
            cleanedText += tolower(c);
        }
    }
    getKeyLenght(cleanedText);
    return 0;
}