//
// Created by Jasmeet Brar on 2020-09-24.
//

#include "Variable.h"

#include <utility>

Variable::Variable(string name, Type type, Token *token): name(std::move(name)), type(type), token(token) {

}
