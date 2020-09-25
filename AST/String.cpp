//
// Created by Jasmeet Brar on 2020-09-24.
//

#include "String.h"

#include <utility>

String::String(string value, Token *token): value(std::move(value)), token(token){

}
