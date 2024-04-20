#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

string hexToAscii(const string& hexString) {
    string asciiString;
    string hexByte;
    for (size_t i = 0; i < hexString.length(); i++) {
        // Skip any non-hex characters
        if (!isxdigit(hexString[i])) {
            continue;
        }
        hexByte += hexString[i];
        if (hexByte.length() == 2) {
            int asciiValue = stoi(hexByte, nullptr, 16);
            char asciiChar = static_cast<char>(asciiValue);
            asciiString += asciiChar;
            hexByte.clear();
        }
    }
    return asciiString;
}

int main()
{
    cout << "enter your username: ";
    string input;
    cin >> input;
    int sum , res;
    unsigned int A, B;
    int Size = input.size();
    int* hexArray = new int[Size];
    for (int i = 0; i < Size; i++) {
        hexArray[i] = static_cast<int>(input[i]);
    }
    for (int i = 0; i < Size; i++) {
        //cout<< hex << sum <<' ' << Size << ' ' << i << ' ' <<hex <<hexArray[i] << endl;
        sum += hexArray[i] * (Size - i);
    }
    res = ~(sum ^ 0x13131313);
    res = res ^ 0x1234ABCD;
    A = res & 0x0F0F0F0F;
    B = res & 0xF0F0F0F0;
    B = B >> 4;
    //cout << hex << A <<' ' << hex << B << endl;
    int a, b;
    string string_a , string_b;
    stringstream sstring_a,sstring_b;
    sstring_a << hex << A;
    sstring_b << hex << B;
    string_a = sstring_a.str();
    string_b = sstring_b.str();
    a = string_a.length();
    b = string_b.length();
    string a_mod, b_mod, stemp;
    stringstream ssam, ssbm;
    string sam, sbm;
    int tempa = 0,tempb = 0;
    int i = a - 1;
    while (i >= 0){
        if (i == 0){
            tempa = stoi(string_a.substr(i, 1), nullptr, 16);
        }
        else{
            tempa = stoi(string_a.substr(i - 1, 2), nullptr, 16);
        }
        i -= 2;
        if (tempa <= 0x9){
            tempa = tempa | 0x30;
        }
        else{
            tempa += 0x37;
        }
        ssam << hex << tempa;
    }
    //cout<<endl<<ssam.str()<<endl;
    //cout<<endl<<a_mod<<endl;
    i = b - 1;
    while (i >= 0){
        if (i == 0){
            tempb = stoi(string_b.substr(i, 1), nullptr, 16);
        }
        else{
            tempb = stoi(string_b.substr(i - 1, 2), nullptr, 16);
        }
        i -= 2;
        if (tempb <= 0x9){
            tempb = tempb | 0x30;
        }
        else{
            tempb += 0x37;
        }
        ssbm << hex << tempb;
    }
    //cout<<endl<<ssbm.str()<<endl;
    string asciiStringa = hexToAscii(ssam.str());
    string asciiStringb = hexToAscii(ssbm.str());
    //cout << asciiStringa << endl;
    //cout << asciiStringb << endl;
    cout << "your serial is: " << "**-" << asciiStringa << '-' <<asciiStringb;
    getch();
}
