#include <iostream>
#include <fstream>

std::string encrypt(std::string text, std::string key){
    std::string cryptedText;
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

std::string decrypt(std::string text, std::string key){
    std::string decryptedText;
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
    // Check the number of parameters
    if (argc < 4) {
        std::cerr << "Usage : sudo exec + -c to encrypt / -d to decrypt + KEY + TEXT" << std::endl;
        return 1;
    } else {
        std::string opt = argv[1];
        std::string key = argv[2];
        std::string text = argv[3];
        if (opt == "-c") {
            std::ofstream outfile ("../texteChiffre.txt");
            outfile << encrypt(text,key) << std::endl;
            outfile.close();
            return 0;
        } else if (opt == "-d") {
            std::ofstream outfile ("../texteClair.txt");
            outfile << decrypt(text,key) << std::endl;
            outfile.close();
            return 0;
        }
        else {
            std::cerr << "Usage : sudo exec + -c to encrypt / -d to decrypt + KEY + TEXT" << std::endl;
            return 1;
        }
    }

}