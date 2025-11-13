/*****************
* Арабские числа *
*****************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

    string toRoman(int num) {
    
        const vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        const vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string result;
        for (int i = 0; i < values.size(); ++i) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
    return result;
    }
    
    int toArabic(string str) {
        for (char& c : str) c = toupper(c);
    
        int result = 0;
        for (char c : str) {
            switch (c) {
                case 'I': result += 1; break;
                case 'V': result += 5; break;
                case 'X': result += 10; break;
                case 'L': result += 50; break;
                case 'C': result += 100; break;
                case 'D': result += 500; break;
                case 'M': result += 1000; break;
            }
        }
        return result;
    }
    
    int main() {
        string input;
        cout << "Enter a number: ";
        cin >> input;
    
        bool isArabic = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isArabic = false;
                break;
            }
        }
    
        if (isArabic) {
            cout << "Roman: " << toRoman(stoi(input)) << endl;
        } else {
            cout << "Arabic: " << toArabic(input) << endl;
        }
    
        return 0;
    }

