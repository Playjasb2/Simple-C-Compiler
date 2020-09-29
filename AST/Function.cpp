//
// Created by Jasmeet Brar on 2020-09-24.
//

#include "Function.h"

Function::Function(Type type, Token *token): type(type), token(token){

}

std::string Function::getName() {
    return this->token->value;
}
