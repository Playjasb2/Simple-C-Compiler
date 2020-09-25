//
// Created by Jasmeet Brar on 2020-09-24.
//

#include "Function.h"

#include <utility>

Function::Function(string name, Type type, Token *token): name(std::move(name)), type(type), token(token){

}
