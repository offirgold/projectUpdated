//
// Created by schwe on 31/12/2018.
//
#include "BindCommand.h"
void BindCommand::doCommand(int index, vector<string> lex) {


    if (index <= 1 || index >= lex.size() - 1){
        throw invalid_argument("invalid bind");
    }
    if(lex[index - 1].compare("=")){
        throw invalid_argument("invalid bind");
    }
    if(!data->isSymbol(lex[index - 2])){
        throw invalid_argument("invalid bind");
    }

    if (data->isSymbol(lex[index + 1])) {
        data->addBindVar(lex[index - 2], lex[index + 1]);
    } else {

        if (regex_match(lex[index + 1], regex("^\".*\"$"))) {

            data->addBind(lex[index - 2], lex[index + 1].substr(1,lex[index + 1].size()-2) );

        } else {
            throw invalid_argument("invalid bind");
        }
    }
}