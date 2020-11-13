//
// Created by Jasmeet Brar on 2020-10-20.
//

#ifndef SIMPLE_C_COMPILER_COMPUTABLEEXPRESSION_H
#define SIMPLE_C_COMPILER_COMPUTABLEEXPRESSION_H

#include "BinaryExpression.h"
#include "Statement.h"
#include <map>

using namespace AST;

namespace AST {
    class ComputableExpression : public BinaryExpression, public Statement {
    private:
        StatementList *before = nullptr;
        StatementList *after = nullptr;

        const static int numberOfOperators = 14;

        constexpr const static Token_Type computable_operators[numberOfOperators] = {
                Token_Type::not_,
                Token_Type::multiply,
                Token_Type::divide,
                Token_Type::modulo,
                Token_Type::plus,
                Token_Type::minus,
                Token_Type::equal_equal,
                Token_Type::not_equal,
                Token_Type::less_than,
                Token_Type::less_than_or_equal_to,
                Token_Type::greater_than,
                Token_Type::greater_than_or_equal_to,
                Token_Type::and_,
                Token_Type::or_
        };

        constexpr const static int computable_operators_precedence[numberOfOperators] = {
                10, // not_
                9,  // multiply
                9,  // divide
                9,  // modulo
                8,  // plus
                8,  // minus
                7,  // equal_equal
                7,  // not_equal
                6,  // less_than
                6,  // less_than_or_equal_to
                6,  // greater_than
                6,  // greater_than_or_equal_to
                5,  // and_
                4   // or_
        };

    public:
        ComputableExpression(Token *operator_token, Expression *LHS, Expression *RHS);
        ComputableExpression(Token *operator_token, Expression *LHS, Expression *RHS, StatementList *before,
                             StatementList *after);

        void accept(Visitor *visitor) override;
        StatementList *getBeforeStatements();
        StatementList *getAfterStatements();

        void setBefore(StatementList *beforeStatements);
        void setAfter(StatementList *afterStatements);

        void emptyBeforeAndAfter();

        static int getOperatorPrecedence(Token_Type type);
    };
}


#endif //SIMPLE_C_COMPILER_COMPUTABLEEXPRESSION_H
