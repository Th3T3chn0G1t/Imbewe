// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#pragma once

namespace imbewe {
    class statement {
    public:
        std::span<token> tokens;
    };

    class control_flow : public statement {
    public:
        token::type kind;
    };

    class expression : public statement {};
    
    class literal : public expression {};

    class string_literal : public literal {
    public:
        expression value;
    };

    class map_literal : public literal {
    public:
        std::unordered_map<std::string, expression> value;
    };

    class operation : public expression {
    public:
        token::type kind;
        expression operand;
    };

    class binary_operation : public operation {
    public:
        expression secondary;
    };

    class block : public statement {
    public:
        std::vector<statement> statements;
    };

    class control_flow_block : public control_flow {
    public:
        block block;
    };

    class assignment : public statement {
    public:
        std::string variable;
        expression value;

        bool conditional;
        bool append;
    };

    class declaration : public assignment {
    public:
        token::type kind;
    };

    class program {
    public:
        std::vector<statement> statements;
    };
}
