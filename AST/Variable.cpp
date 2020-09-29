//
// Created by Jasmeet Brar on 2020-09-24.
//

#include "Variable.h"

Variable::Variable(Type type, Token *token): type(type), token(token) {

}

std::string Variable::getName() {
    return this->token->value;
}
