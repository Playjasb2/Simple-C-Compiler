//
// Created by Jasmeet Brar on 2020-09-24.
//

#include "Integer.h"

#include <utility>

Integer::Integer(Token *token): token(token){

}

std::string Integer::getValue() {
    return this->token->value;
}

