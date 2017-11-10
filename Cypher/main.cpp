//for (i = 1; i <= 26; i++){
//for (j = 0; j <= tailleTexte; j+=k) {
//int letterText = text[j] - 'A';
//if (letterText == i) {
//occured ++;
//}
//}
//ind += (occured / tailleTexte) * ((occured - 1) / (tailleTexte - 1));
//occured = 0;
//}
//if(indFinal < ind){
//indFinal = ind;
//kFinal = k;
//}

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

double calculInd (string text) {
    int i, j;
    double ind = 0, occured = 0, tailleTexte = text.length();
    for (i = 'A'; i <= 'Z'; i++){
        for (j = 0; j < tailleTexte; j++){
            if (text[j] == i) occured++;
        }
        double test1 = occured / tailleTexte;
        double test2 = (occured - 1) / (tailleTexte - 1);
        double total = test1 * test2;
        ind += (occured / tailleTexte) * ((occured - 1) / (tailleTexte - 1));
        occured = 0;
    }
    return ind;
}

int getKeyLenght(string text){
    //On suppose que la taille de la clef est <=12;
    int i, k;
    string text2, text3, text4, text5, text6, text7, text8, text9, text10, text11, text12;
    for(k = 2; k <= 12; k++) {
        for(i = 0; i < text.length(); i+=k){
            if (k == 2) text2 += text[i];
            if (k == 3) text3 += text[i];
            if (k == 4) text4 += text[i];
            if (k == 5) text5 += text[i];
            if (k == 6) text6 += text[i];
            if (k == 7) text7 += text[i];
            if (k == 8) text8 += text[i];
            if (k == 9) text9 += text[i];
            if (k == 10) text10 += text[i];
            if (k == 11) text11 += text[i];
            if (k == 12) text12 += text[i];
        }
    }

    string texts[] = {text2, text3, text4, text5, text6, text7, text8, text9, text10, text11, text12};
    int keyLengthFinal = 0;
    int keyLength = 2;
    double indFinal = 0;
    for(string text : texts) {
        double ind = calculInd(text);
        if (indFinal < ind) {
            indFinal = ind;
            keyLengthFinal = keyLength;
        }
        keyLength++;
    }

    cout << "Key length : " << keyLengthFinal << "ind : " << indFinal << endl;
}

int main() {

    string text, line, cleanText; // Added this line
    ifstream file;
    file.open ("../first.txt");

    while (!file.eof())
    {
        getline (file, line);
        text+= line; // Added this line
    }
    file.close();
    for(char c : text) {
        if (isalpha(c)) {
            cleanText += toupper(c);
        }
    }
    getKeyLenght(cleanText);



    return 0;
}