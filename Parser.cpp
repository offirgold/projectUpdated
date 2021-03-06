//
// Created by schwe on 26/12/2018.
//

#include "parser.h"
void parser(DataBase* d, vector <string> lex) {;
    vector <string> commandBlock = {"while", "if"};
    int indent = 0;
    for(int i = 0; i < lex.size(); ++i) {
        if (d->isCommand(lex[i]) && indent == 0) {
            d->getCommand(lex[i])->doCommand(i, lex);
        }
        for (int j = 0; j < commandBlock.size(); ++j) {
            if (!lex[i].compare(commandBlock[j])) {
                indent++;
            }
        }
        if (!lex[i].compare("}")) {
            indent--;
        }
        if (indent < 0) {
            throw invalid_argument("Indention is Incorrect!");
        }
    }
}