//
// Created by Jasmeet Brar on 2020-09-24.
//

#include "StringValue.h"

StringValue::StringValue(Token *token): token(token){

}

std::string StringValue::getValue() {
    return this->token->value;
}
