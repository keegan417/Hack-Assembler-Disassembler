#include <iostream>
using namespace std;
#include <string>
#include <math.h>
#include <map>



string bitConversion(string inp) {
    string temp = inp;
    // if(temp == "SP")
    //     return "0";
    // else if(temp == "LCL")
    //     return "1";
    // else if(temp == "ARG")
    //     return "2";
    // else if(temp == "THIS")
    //     return "3";
    // else if(temp == "THAT")
    //     return "4";
    // else if(temp == "SCREEN")
    //     return "16384";
    // else if(temp == "KBD")
    //     return "24576";
    // else if(temp == "R0")
    //     return "0";
    // else if(temp == "R1")
    //     return "1";
    // else if(temp == "R2")
    //     return "0";  
    string newStr = "0";
    int num = stoi(temp);
    int aray[16];
    aray[0] = '0';
    for(int i = 1; i < 16; i++) {
        aray[i] = -1;
    }
    int i = 1;
    int remainder = 0;
    while(num > 0) {
        remainder = num % 2;
        aray[i] = remainder;
        num /= 2;
        i++;
    }
    for(int i = 15; i > 0; i--) {
        if(aray[i] != -1) {
            newStr += to_string(aray[i]);
        }
        else {
            newStr += '0';
        }
    }

    // while(num > 0) {
    //     remainder = num % 2;
    //     int insert = remainder * digitsPlace;
    //     // cout << insert;
    //     tempResult += insert;
    //     digitsPlace *= 10;
    //     num /= 2;
    // }
    
    // newStr = to_string(tempResult);
    // if(newStr.size() < 16) {
    //     int amtAdd = 16 - newStr.size();
    //     for(int i = 0; i < amtAdd; i++) {
    //         newStr = '0' + newStr;
    //     }
    // }
    return newStr;
    }
   



string cInstruction(string inp) {
    string temp1 = "111";
    string temp2 = "";
    string temp3 = "";
    if(inp.size() > 2) {
    if(inp.at(1) == '=' || inp.at(2) == '=') {
        if(inp.substr(0,2) == "AD")
            temp2 = "110";
        else if(inp.substr(0,2) == "AM")
            temp2 = "101";
        else if(inp.substr(0,2) == "MD")
            temp2 = "011";
        else if(inp.at(0) == 'D')
            temp2 = "010";
        else if(inp.at(0) == 'A')
            temp2 = "100";
        else if(inp.at(0) == 'M')
            temp2 = "001";
    }
    else {
        temp2 = "000";
    }
    }
    if(inp.find(';') == std::string::npos){
        temp3 = "000";
    }
    else {
        if(inp.substr(inp.find(';') + 1) == "JGT")
            temp3 = "001";
        else if(inp.substr(inp.find(';') + 1) == "JEQ")
            temp3 = "010";
        else if(inp.substr(inp.find(';') + 1) == "JGE")
            temp3 = "011";
        else if(inp.substr(inp.find(';') + 1) == "JLT")
            temp3 = "100";
        else if(inp.substr(inp.find(';') + 1) == "JNE")
            temp3 = "101";
        else if(inp.substr(inp.find(';') + 1) == "JLE")
            temp3 = "110";
        else if(inp.substr(inp.find(';') + 1) == "JMP")
            temp3 = "111";
    }
    string temp4 = "";
    if(inp.find('=') == std::string::npos && inp.find(';') == std::string::npos)
    {
        if(inp == "M")
            temp4 = "1110000";
        else if(inp == "!M")
            temp4 = "1110001";
        else if(inp == "-M")
            temp4 = "1110011";
        else if(inp == "M+1")
            temp4 = "1110111";
        else if(inp == "M-1")
            temp4 = "1110010";
        else if(inp == "D+M")
            temp4 = "1000010";
        else if(inp == "D-M")
            temp4 = "1010011";
        else if(inp == "M-D")
            temp4 = "1000111";
        else if(inp == "D&M")
            temp4 = "1000000";
        else if(inp == "D|M")
            temp4 = "1010101";
        else if(inp == "0")
            temp4 = "0101010";
        else if(inp == "1")
            temp4 = "0111111";
        else if(inp == "-1")
            temp4 = "0111010";
        else if(inp == "D")
            temp4 = "0001100";
        else if(inp == "A")
            temp4 = "0110000";
        else if(inp == "!D")
            temp4 = "0001101";
        else if(inp == "!A")
            temp4 = "0110001";
        else if(inp == "-D")
            temp4 = "0001111";
        else if(inp == "-A")
            temp4 = "0110011";
        else if(inp == "D+1")
            temp4 = "0011111";
        else if(inp == "A+1")
            temp4 = "0110111";
        else if(inp == "D-1")
            temp4 = "0001110";
        else if(inp == "A-1")
            temp4 = "0110010";
        else if(inp == "D+A")
            temp4 = "0000010";
        else if(inp == "D-A")
            temp4 = "0010011";
        else if(inp == "A-D")
            temp4 = "0000111";
        else if(inp == "D&A")
            temp4 = "0000000";
        else if(inp == "D|A")
            temp4 = "0010101";
        
    }
    else if(inp.find('=') == std::string::npos) {
        int pos = inp.find(';');
        if(inp.substr(0,pos) == "M")
            temp4 = "1110000";
        else if(inp.substr(0,pos) == "!M")
            temp4 = "1110001";
        else if(inp.substr(0,pos) == "-M")
            temp4 = "1110011";
        else if(inp.substr(0,pos) == "M+1")
            temp4 = "1110111";
        else if(inp.substr(0,pos) == "M-1")
            temp4 = "1110010";
        else if(inp.substr(0,pos) == "D+M")
            temp4 = "1000010";
        else if(inp.substr(0,pos) == "D-M")
            temp4 = "1010011";
        else if(inp.substr(0,pos) == "M-D")
            temp4 = "1000111";
        else if(inp.substr(0,pos) == "D&M")
            temp4 = "1000000";
        else if(inp.substr(0,pos) == "D|M")
            temp4 = "1010101";
        else if(inp.substr(0,pos) == "0")
            temp4 = "0101010";
        else if(inp.substr(0,pos) == "1")
            temp4 = "0111111";
        else if(inp.substr(0,pos) == "-1")
            temp4 = "0111010";
        else if(inp.substr(0,pos) == "D")
            temp4 = "0001100";
        else if(inp.substr(0,pos) == "A")
            temp4 = "0110000";
        else if(inp.substr(0,pos) == "!D")
            temp4 = "0001101";
        else if(inp.substr(0,pos) == "!A")
            temp4 = "0110001";
        else if(inp.substr(0,pos) == "-D")
            temp4 = "0001111";
        else if(inp.substr(0,pos) == "-A")
            temp4 = "0110011";
        else if(inp.substr(0,pos) == "D+1")
            temp4 = "0011111";
        else if(inp.substr(0,pos) == "A+1")
            temp4 = "0110111";
        else if(inp.substr(0,pos) == "D-1")
            temp4 = "0001110";
        else if(inp.substr(0,pos) == "A-1")
            temp4 = "0110010";
        else if(inp.substr(0,pos) == "D+A")
            temp4 = "0000010";
        else if(inp.substr(0,pos) == "D-A")
            temp4 = "0010011";
        else if(inp.substr(0,pos) == "A-D")
            temp4 = "0000111";
        else if(inp.substr(0,pos) == "D&A")
            temp4 = "0000000";
        else if(inp.substr(0,pos) == "D|A")
            temp4 = "0010101";
    }
    else if(inp.find(';') == std::string::npos) {
        int pos = inp.find('=');
        if(inp.substr(pos+1, inp.length() - pos - 1) == "M")
            temp4 = "1110000";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "!M")
            temp4 = "1110001";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "-M")
            temp4 = "1110011";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "M+1")
            temp4 = "1110111";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "M-1")
            temp4 = "1110010";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D+M")
            temp4 = "1000010";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D-M")
            temp4 = "1010011";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "M-D")
            temp4 = "1000111";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D&M")
            temp4 = "1000000";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D|M")
            temp4 = "1010101";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "0")
            temp4 = "0101010";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "1")
            temp4 = "0111111";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "-1")
            temp4 = "0111010";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D")
            temp4 = "0001100";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "A")
            temp4 = "0110000";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "!D")
            temp4 = "0001101";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "!A")
            temp4 = "0110001";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "-D")
            temp4 = "0001111";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "-A")
            temp4 = "0110011";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D+1")
            temp4 = "0011111";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "A+1")
            temp4 = "0110111";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D-1")
            temp4 = "0001110";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "A-1")
            temp4 = "0110010";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D+A")
            temp4 = "0000010";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D-A")
            temp4 = "0010011";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "A-D")
            temp4 = "0000111";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D&A")
            temp4 = "0000000";
        else if(inp.substr(pos+1, inp.length() - pos - 1) == "D|A")
            temp4 = "0010101";
    }
    else {
        int pos1 = inp.find('=');
        int pos2 = inp.find(';');
        if(inp.substr(pos1+1, pos2-pos1-1) == "M")
            temp4 = "1110000";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "!M")
            temp4 = "1110001";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "-M")
            temp4 = "1110011";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "M+1")
            temp4 = "1110111";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "M-1")
            temp4 = "1110010";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D+M")
            temp4 = "1000010";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D-M")
            temp4 = "1010011";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "M-D")
            temp4 = "1000111";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D&M")
            temp4 = "1000000";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D|M")
            temp4 = "1010101";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "0")
            temp4 = "0101010";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "1")
            temp4 = "0111111";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "-1")
            temp4 = "0111010";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D")
            temp4 = "0001100";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "A")
            temp4 = "0110000";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "!D")
            temp4 = "0001101";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "!A")
            temp4 = "0110001";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "-D")
            temp4 = "0001111";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "-A")
            temp4 = "0110011";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D+1")
            temp4 = "0011111";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "A+1")
            temp4 = "0110111";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D-1")
            temp4 = "0001110";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "A-1")
            temp4 = "0110010";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D+A")
            temp4 = "0000010";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D-A")
            temp4 = "0010011";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "A-D")
            temp4 = "0000111";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D&A")
            temp4 = "0000000";
        else if(inp.substr(pos1+1, pos2-pos1-1) == "D|A")
            temp4 = "0010101";
    }
    string fin = "";
    // if(inp.find('=') != std::string::npos) {
    //     fin = temp1 + temp4 + temp2 + temp3;
    // }
    // else if(inp.find(';') == std::string::npos)
    //     fin = temp1 + temp4 + temp2 + temp3 + "000";
    // else if(inp.find('='))
    //     fin = temp1 + temp4 + temp2 + temp3;
    if(inp.find('=') == std::string::npos && inp.find(';') == std::string::npos) {
        if(inp == "0" || inp == "1" || inp == "-1" || inp == "D" || inp == "A" || inp == "!D" || inp == "!A" || inp == "-D" || inp == "-A" || inp == "M" || inp == "!M" || inp == "-M")
            return temp1 + temp4 + temp2 + temp3 + "000";
    }
    fin = temp1 + temp4 + temp2 + temp3;
    return fin;
    

}





//  else {
//         bool found;
//         if(mapTemp[temp] != NULL)
//             found = true;
//         if(found == true) {
//                 int num = mapTemp[temp];
//                 int digitsPlace = 1;
//                 int remainder = 0;
//                 int tempResult = 0;
//                 while(num > 0) {
//                     remainder = num % 2;
//                     int insert = remainder * digitsPlace;
//                     tempResult += insert;
//                     digitsPlace *= 10;
//                     num /= 2;

//     }
//         string newStr = "";
//                 newStr = to_string(tempResult);
//                 if(newStr.size() < 16) {
//                     int amtAdd = 16 - newStr.size();
//                     for(int i = 0; i < amtAdd; i++) {
//                     newStr = '0' + newStr;
//                 }
//             }
//                 return '0' + newStr;
//             }
//             else {
//                 mapTemp[temp] = varCounter;
//                 string newStr = "";
//                 int num = varCounter;
//                 int digitsPlace = 1;
//                 int remainder = 0;
//                 int tempResult = 0;
//                 while(num > 0) {
//                     remainder = num % 2;
//                     int insert = remainder * digitsPlace;
//                     tempResult += insert;
//                     digitsPlace *= 10;
//                     num /= 2;

//          }

//                 newStr = to_string(tempResult);
//                 if(newStr.size() < 16) {
//                     int amtAdd = 16 - newStr.size();
//                 for(int i = 0; i < amtAdd; i++) {
//                         newStr = '0' + newStr;
//             }
//     }
//             varCounter++;
//             return newStr;
//             }
//         }
//         }

int main () {
    // string command;
    map<string, int> m;
    m["SP"] = 0;
    m["LCL"] = 1;
    m["ARG"] = 2;
    m["THIS"] = 3;
    m["THAT"] = 4;
    m["R0"] = 0;
    m["R1"] = 1;
    m["R2"] = 2;
    m["R3"] = 3;
    m["R4"] = 4;
    m["R5"] = 5;
    m["R6"] = 6;
    m["R7"] = 7;
    m["R8"] = 8;
    m["R9"] = 9;
    m["R10"] = 10;
    m["R11"] = 11;
    m["R12"] = 12;
    m["R13"] = 13;
    m["R14"] = 14;
    m["R15"] = 15;
    m["SCREEN"] = 16384;
    m["KBD"] = 24576;
    string command;
    int variableCount = 16;
    int labelCount = 0;


    while(getline(cin, command)) {
        // if(command.substr(0,2) == "//") {
        //     break;
        // } {}
        string tempC = command;
        if(command[0] == '(' && command[command.size() - 1] == ')') {
            for(int i = 0; i < command.size(); i++) {
                if(command[i] == '(' || command[i] == ')')
                    command.erase(i, 1);
            }
            if(m.find(command) == m.end()) {
                m[command] = labelCount;
                command = to_string(labelCount);
            }
            else {
                command = to_string(m[command]);
            }
            labelCount++;
            continue;
        }
        if(command[0] == '/' && command[1] == '/') {
            continue;
        }
        long unsigned int length = command.length();
        for(int i = 0; i < length; i++) {
            if(command[i] == '/' && command[i+1] == '/')
                command.erase(i, command.size() - 1);
        }
        for(int i = 0; i < command.length(); i++) {
            if(command[i] == ' ')
                command.erase(i, 1);
        }

        // if(command[0] == '(') {
        //     string tempName = "";
        //     int i = 1;
        //     while(!command[i] == ')') {
        //         tempName += command[i];
        //         i++;
        //     }
        //     m[tempName] = labelCounter;
        // }
        if(command[0] == '@') {
                command = command.substr(1);
                bool isNum = true;
                for(int i = 0; i < command.length(); i++) {
                if(!isdigit(command[i]))
                    isNum = false;
                        }
                if(!isNum) {
                    if(m.find(command) == m.end()) {
                        m[command] = variableCount;
                        command = to_string(variableCount);
                        variableCount++;
                    }
                    else {
                        command = to_string(m[command]);
                    }
                }
                // else
                //     command = command.substr(1);
                cout << bitConversion(command) << endl;
            }
        else if(command[0] != '@' && command.substr(0,2) != "//" && command != "" && command[0] != '(') {
            string tempResult = cInstruction(command);
            if(command != "")
                cout << cInstruction(command) << endl;
            // cout << cInstruction(command) << endl;
        }
        labelCount++;

    }

}