// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#include "include/imbewe.hpp"

int main(int argc, char** argv) {
    std::filesystem::path file("./build.imbewe");
    if(argc > 1) file = argv[1];

    imbewe::source source(file);
    std::vector<imbewe::token> tokens = source.tokenize();

    for(const auto& token : tokens) {
        switch(token.token_type) {
            case imbewe::token::type::none: std::cout << "none"; break;
            case imbewe::token::type::keyword_intrin: std::cout << "keyword_intrin"; break;
            case imbewe::token::type::keyword_config: std::cout << "keyword_config"; break;
            case imbewe::token::type::keyword_var: std::cout << "keyword_var"; break;
            case imbewe::token::type::keyword_task: std::cout << "keyword_task"; break;
            case imbewe::token::type::keyword_if: std::cout << "keyword_if"; break;
            case imbewe::token::type::keyword_elif: std::cout << "keyword_elif"; break;
            case imbewe::token::type::keyword_else: std::cout << "keyword_else"; break;
            case imbewe::token::type::keyword_while: std::cout << "keyword_while"; break;
            case imbewe::token::type::keyword_for: std::cout << "keyword_for"; break;
            case imbewe::token::type::keyword_forin: std::cout << "keyword_forin"; break;
            case imbewe::token::type::keyword_break: std::cout << "keyword_break"; break;
            case imbewe::token::type::keyword_continue: std::cout << "keyword_continue"; break;
            case imbewe::token::type::keyword_and: std::cout << "keyword_and"; break;
            case imbewe::token::type::keyword_or: std::cout << "keyword_or"; break;
            case imbewe::token::type::keyword_not: std::cout << "keyword_not"; break;
            case imbewe::token::type::left_brace: std::cout << "left_brace"; break;
            case imbewe::token::type::right_brace: std::cout << "right_brace"; break;
            case imbewe::token::type::left_bracket: std::cout << "left_bracket"; break;
            case imbewe::token::type::right_bracket: std::cout << "right_bracket"; break;
            case imbewe::token::type::left_chevron: std::cout << "left_chevron"; break;
            case imbewe::token::type::right_chevron: std::cout << "right_chevron"; break;
            case imbewe::token::type::left_parentheses: std::cout << "left_parentheses"; break;
            case imbewe::token::type::right_parentheses: std::cout << "right_parentheses"; break;
            case imbewe::token::type::string_literal: std::cout << "string_literal - '" << source.buffer->substr(token.offset, token.length) << '\''; break;
            case imbewe::token::type::assign: std::cout << "assign"; break;
            case imbewe::token::type::conditional_assign: std::cout << "conditional_assign"; break;
            case imbewe::token::type::append: std::cout << "append"; break;
            case imbewe::token::type::conditional_append: std::cout << "conditional_append"; break;
            case imbewe::token::type::compare: std::cout << "compare"; break;
            case imbewe::token::type::parameter_delimiter: std::cout << "parameter_delimiter"; break;
            case imbewe::token::type::member_accessor: std::cout << "member_accessor"; break;
            case imbewe::token::type::concatonate: std::cout << "concatonate"; break;
            case imbewe::token::type::statement_delimiter: std::cout << "statement_delimiter"; break;
            case imbewe::token::type::identifier: std::cout << "identifier - `" << source.buffer->substr(token.offset, token.length) << '`' ; break;
        }
        std::cout << std::endl;
    }
}
