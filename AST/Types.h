//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_TYPES_H
#define SIMPLE_C_COMPILER_TYPES_H

#include <string>

namespace AST {

    enum Type {
        Integer = 1,
        String,
        Boolean,
        Void,
        Unknown,
        TYPE_MAX
    };

    const char *Type_Names[Type::TYPE_MAX] = {"Integer", "StringValue", "Boolean", "Void"};

}

#endif //SIMPLE_C_COMPILER_TYPES_H