#include <iostream>
using namespace std;
#include <string>
#include <math.h>


int aInstruction(string inp) {
    int finalNum = 0;
    int exponent = 0;    
        for(int i = inp.length() - 1; i > 0; i--) {
            char temp = inp.at(i);
            if(temp == '1')
                if(exponent == 0)
                    finalNum += 1;
                else {
                    finalNum += pow(2, exponent);
                }
            exponent++;
        }
        return finalNum;
}

string cInstruction(string inp) {
    string temp = "";
    if(inp.at(3) == '1') {
        if(inp.substr(4,6) == "110000")
            temp = "M";
        else if(inp.substr(4,6) == "110001")
            temp = "!M";
        else if(inp.substr(4,6) == "110011")
            temp = "-M";
        else if(inp.substr(4,6) == "110111")
            temp = "M+1";
        else if(inp.substr(4,6) == "110010")
            temp = "M-1";
        else if(inp.substr(4,6) == "000010")
            temp = "D+M";
        else if(inp.substr(4,6) == "010011")
            temp = "D-M";
        else if(inp.substr(4,6) == "000111")
            temp = "M-D";
        else if(inp.substr(4,6) == "000000")
            temp = "D&M";
        else if(inp.substr(4,6) == "010101")
            temp = "D|M";
    }
    else {
        if(inp.substr(4,6) == "101010") {
            temp = "0";
        }
        else if(inp.substr(4,6) == "111111")
            temp = "1";
        else if(inp.substr(4,6) == "111010")
            temp = "-1";
        else if(inp.substr(4,6) == "001100")
            temp = "D";
        else if(inp.substr(4,6) == "110000")
            temp = "A";
        else if(inp.substr(4,6) == "001101")
            temp = "!D";
        else if(inp.substr(4,6) == "110001")
            temp = "!A";
        else if(inp.substr(4,6) == "001111")
            temp = "-D";
        else if(inp.substr(4,6) == "110011")
            temp = "-A";
        else if(inp.substr(4,6) == "011111")
            temp = "D+1";
        else if(inp.substr(4,6) == "110111")
            temp = "A+1";
        else if(inp.substr(4,6) == "001110")
            temp = "D-1";
        else if(inp.substr(4,6) == "110010")
            temp = "A-1";
        else if(inp.substr(4,6) == "000010")
            temp = "D+A";
        else if(inp.substr(4,6) == "010011")
            temp = "D-A";
        else if(inp.substr(4,6) == "000111")
            temp = "A-D";
        else if(inp.substr(4,6) == "000000")
            temp = "D&A";
        else if(inp.substr(4,6) == "010101")
            temp = "D|A";
    }
    string secondTemp = temp;
    if(inp.substr(10,3) == "001") {
        temp = "M=" + secondTemp;
    }
    else if(inp.substr(10,3) == "010") {
        temp = "D=" + secondTemp;
    }
    else if(inp.substr(10,3) == "011") {
        temp = "MD=" + secondTemp;
    }
    else if(inp.substr(10,3) == "100") {
        temp = "A=" + secondTemp;
    }
    else if(inp.substr(10,3) == "101") {
        temp = "AM=" + secondTemp;
    }
    else if(inp.substr(10,3) == "110") {
        temp = "AD=" + secondTemp;
    }
    string thirdTemp = temp;
    if(inp.substr(13,3) == "001") {
        temp = thirdTemp + ";JGT";
    }
    else if(inp.substr(13,3) == "010") {
        temp = thirdTemp + ";JEQ";
    }
    else if(inp.substr(13,3) == "011") {
        temp = thirdTemp + ";JGE";
    }
    else if(inp.substr(13,3) == "100") {
        temp = thirdTemp + ";JLT";
    }
    else if(inp.substr(13,3) == "101") {
        temp = thirdTemp + ";JNE";
    }
    else if(inp.substr(13,3) == "110") {
        temp = thirdTemp + ";JLE";
    }
    else if(inp.substr(13,3) == "111") {
        temp = thirdTemp + ";JMP";
    }
    return temp;

    // else {

    // }

}

int main() {
    string command;
    // cout << "Enter a binary command: ";
    while(getline(cin, command)) {
    if(command.empty())
        break;
    else {
    if (command[0] == '0') {
        int finalResult = aInstruction(command);
        cout << "@" << to_string(finalResult);
        cout << endl;
    }
    else if(command[1] == '1') {
        string finalResult = cInstruction(command);
        cout << finalResult << endl;
    }
    }
    }
}

