#include <iostream>
#include <fstream>
using namespace std;
string encrypt(string text, string key){
    string cryptedText;
    int i = 0;
    for(char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            //Encrypt the letter
            cryptedText += (c - 'A' + key[i] - 'A') % 26 + 'A';
            i++;
            //Repeat the key
            if (i == key.length()) i = 0;
        } else cryptedText += c;
    }
    return cryptedText;
}

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

int main(int argc, char* argv[])
{
    int n;
    // Check the number of parameters
    if (argc < 4) {
        cerr << "Usage : sudo exec + -c to encrypt / -d to decrypt + KEY + TEXT" << endl;
        return 1;
    } else {
        string opt = argv[1];
        string key = argv[2];
        string text = argv[3];
        if (opt == "-c") {
            ofstream outfile ("./texteChiffre.txt");
            outfile << encrypt(text,key) << endl;
            outfile.close();
            cout << "YOU CAN FIND THE CRYPTED TEXT AT ./texteChiffre.txt" << endl << endl;
            cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_ENTER SOMETHING TO CLOSE PROGRAM, THANKS YOU_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;
            cin >> n;
            return 0;
        } else if (opt == "-d") {
            ofstream outfile ("./texteClair.txt");
            outfile << decrypt(text,key) << endl;
            outfile.close();
            cout << "YOU CAN FIND THE DECRYPTED TEXT AT ./texteClair.txt" << endl << endl;
            cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_ENTER SOMETHING TO CLOSE PROGRAM, THANKS YOU_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;
            cin >> n;
            return 0;
        }
        else {
            cerr << "Usage : sudo exe + -c to encrypt / -d to decrypt + KEY + TEXT" << endl;
            cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_ENTER SOMETHING TO CLOSE PROGRAM, THANKS YOU_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;
            cin >> n;
            return 1;
        }
    }

}