#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

//Took from EncryptDecrypt folder
string decrypt(string text, string key){
    string decryptedText;
    int i = 0;
    for(char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            //decrypt the letter
            decryptedText += ((c - 'A') - (key[i] - 'A') + 26) % 26 + 'A';
            i++;
            //Repeat the key
            if (i == key.length()) i = 0;
        } else decryptedText += c;
    }
    return decryptedText;
}

double calculInd (string text) {
    int i, j;
    double ind = 0, occured = 0, tailleTexte = text.length();
    for (i = 'A'; i <= 'Z'; i++){
        for (j = 0; j < tailleTexte; j++){
            if (text[j] == i) occured++;
        }
        ind += (occured / tailleTexte) * ((occured - 1) / (tailleTexte - 1));
        occured = 0;
    }
    return ind;
}

int getKeyLenght(string text){
    //We suppose that the key length is <=12;
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
    return keyLengthFinal;
}

string getFinalKey (string text, int keyLength){
    int i, j, k;
    static int lettersArray[26];
    string testText, key;
    for(i = 0; i < keyLength; i++){
        for(j = 0 + i; j < text.length(); j+= keyLength){
            lettersArray[text[j] - 'A']++;
        }
        int maxOccuredLetter = distance(lettersArray, max_element(lettersArray, lettersArray+26)) + 65;
        int shift = maxOccuredLetter - 'E';
        // Workaround for  : maxOccurredLetter - 'E' mod26 with negativ values // See :
        // https://stackoverflow.com/questions/12276675/modulus-with-negative-numbers-in-c
        key += ((shift %26 + 26) %26) + 65;
        //Assign 0 to each array element
        fill(lettersArray, lettersArray + 26, 0);
    }
    return key;
}

int main() {

    string firstText, secondText, line, firstCleanText, secondCleanText; // Added this line
    ifstream file;
    file.open ("../texts/first.txt");

    //Get first text
    while (!file.eof())
    {
        getline (file, line);
        firstText+= line; // Added this line
    }
    file.close();
    for(char c : firstText) {
        if (isalpha(c)) {
            firstCleanText += toupper(c);
        }
    }

    file.open ("../texts/second.txt");

    //Get second text
    while (!file.eof())
    {
        getline (file, line);
        secondText+= line; // Added this line
    }
    file.close();
    for(char c : secondText) {
        if (isalpha(c)) {
            secondCleanText += toupper(c);
        }
    }

    int keyLenghtFirst = getKeyLenght(firstCleanText);
    string keyFirst = getFinalKey(firstCleanText, keyLenghtFirst);

    ofstream firstOutfile ("../premierTexteClair.txt");
    firstOutfile << decrypt(firstText,keyFirst);
    firstOutfile.close();

    int keyLenghtSecond = getKeyLenght(secondCleanText);
    string keySecond = getFinalKey(secondCleanText, keyLenghtSecond);

    ofstream secondOutfile ("../deuxiemeTexteClair.txt");
    secondOutfile << decrypt(secondText,keySecond);
    secondOutfile.close();

    cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_HELLO THIS IS A VIGENERE CIPHER WITH 2 PREDEFINED TEXTS_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;
    cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_FIRST TEXT RESULTS_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;
    cout << "KEY LENGTH : " << keyLenghtFirst << endl;
    cout << "FINAL KEY : " << keyFirst << endl;
    cout << "YOU CAN FIND THE DECRYPTED TEXT AT ./premierTexteClair.txt" << endl << endl;

    cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_SECOND TEXT RESULTS_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;
    cout << "KEY LENGTH : " << keyLenghtSecond << endl;
    cout << "FINAL KEY : " << keySecond << endl;
    cout << "YOU CAN FIND THE DECRYPTED TEXT AT ./deuxiemeTexteClair.txt";

    return 0;
}