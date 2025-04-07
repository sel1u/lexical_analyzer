#include <bits/stdc++.h>
using namespace std;

void printToken(const string& token, const string& type) {
    cout << token << " : " << type << endl;
}

bool isFloat(const string& s) {
    return s.find('.') != string::npos;
}

bool isKeyword(const string& s) {
    return s == "if" || s == "for" || s == "while";
}

int main() {
    string input;

    cout << "Enter code (type 'exit' to quit):" << endl;

    while (true) {
        getline(cin, input);
        if (input == "exit") break;

        string current = "";

        for (size_t i = 0; i < input.length(); ++i) {
            char ch = input[i];

            if (isalnum(ch) || ch == '_' || ch == '.') {
                current += ch;
            } else {
                if (!current.empty()) {
                    if (isdigit(current[0])) {
                        if (isFloat(current))
                            printToken(current, "float value ");
                        else
                            printToken(current, "integer value");
                    } else {
                        if (isKeyword(current))
                            printToken(current, "keyword");
                        else
                            printToken(current, "identifier");
                    }
                    current.clear();
                }

                if (isspace(ch)) continue;

                string twoChars = input.substr(i, 2);

                if (twoChars == "!=") { printToken("!=", "not_equal_op"); i++; }
                else if (twoChars == "=>") { printToken("=>", "LE_comparison"); i++; }
                else if (twoChars == "=<") { printToken("=<", "GE_comparison"); i++; }
                else if (twoChars == "==") { printToken("==", "equal_op"); i++; }
                else if (twoChars == "++") { printToken("++", "increment_op"); i++; }
                else if (twoChars == "--") { printToken("--", "decrement_op"); i++; }
                else if (twoChars == "**") { printToken("**", "exp_op"); i++; }
                else {
                    switch (ch) {
                        case '+': printToken("+", "plus_op"); break;
                        case '-': printToken("-", "sub_op"); break;
                        case '*': printToken("*", "Mul_op"); break;
                        case '/': printToken("/", "Div_op"); break;
                        case '=': printToken("=", "assignment_op"); break;
                        case '<': printToken("<", "greater_than_op"); break;
                        case '>': printToken(">", "less_than_op"); break;
                        case ',': printToken(",", "Comma"); break;
                        case ';': printToken(";", "Semicolon"); break;
                        case '(': printToken("(", "LPAREN"); break;
                        case ')': printToken(")", "RPAREN"); break;
                        case '{': printToken("{", "LBRACE"); break;
                        case '}': printToken("}", "RBRACE"); break;
                        case '[': printToken("[", "LBracket"); break;
                        case ']': printToken("]", "RBracket"); break;
                        default: printToken(string(1, ch), "unknown_symbol"); break;
                    }
                }
            }
        }

        if (!current.empty()) {
            if (isdigit(current[0])) {
                if (isFloat(current))
                    printToken(current, "float value");
                else
                    printToken(current, "integer value");
            } else {
                if (isKeyword(current))
                    printToken(current, "keyword");
                else
                    printToken(current, "identifier");
            }
        }

        cout << endl;
    }

    cout << "Program ended by user." << endl;
    return 0;
}