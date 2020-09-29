add_library(
        AST
        Expression.h
        BinaryExpression.cpp
        Declaration.h
        Types.h
        Declaration.cpp
        BinaryExpression.h
        UnaryExpression.h
        IntegerDeclaration.cpp
        IntegerDeclaration.h
        VariableStatement.h
        StatementList.h
        StatementList.cpp
        ArithmeticExpression.cpp
        ArithmeticExpression.h
        ConditionalExpression.cpp
        ConditionalExpression.h
        NotExpression.cpp
        NotExpression.h
        AssignmentStatement.cpp
        AssignmentStatement.h
        VariableStatement.cpp
        IncrementDecrementExpression.cpp
        IncrementDecrementExpression.h
        IfStatement.cpp
        IfStatement.h
        Statement.h
        FunctionCall.cpp
        FunctionCall.h
        ASTNode.h
        ASTPrinter.cpp
        ASTPrinter.h
        Program.h
        Program.cpp
        Variable.cpp
        Variable.h
        Integer.h
        Integer.cpp
        StringValue.cpp
        StringValue.h
        Function.cpp
        Function.h
        UnaryExpression.cpp)

target_include_directories(AST PUBLIC ".")

target_link_libraries(AST include)