//
// Created by Jasmeet Brar on 2020-09-24.
//

#include "Integer.h"

#include <utility>

Integer::Integer(string value, Token *token): value(std::move(value)), token(token){

}

