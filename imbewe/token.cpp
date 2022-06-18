// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#include "include/imbewe.hpp"

namespace imbewe {
    const token::map token::keywords = {
        {"intrin", token::type::keyword_intrin},
        {"config", token::type::keyword_config},
        {"var", token::type::keyword_var},
        {"task", token::type::keyword_task},
        {"if", token::type::keyword_if},
        {"elif", token::type::keyword_elif},
        {"else", token::type::keyword_else},
        {"while", token::type::keyword_while},
        {"for", token::type::keyword_for},
        {"forin", token::type::keyword_forin},
        {"break", token::type::keyword_break},
        {"continue", token::type::keyword_continue},
        {"and", token::type::keyword_and},
        {"or", token::type::keyword_or},
        {"not", token::type::keyword_not}
    };

    const token::map token::operators = {
        {"{", token::type::left_brace},
        {"}", token::type::right_brace},
        {"[", token::type::left_bracket},
        {"]", token::type::right_bracket},
        {"<", token::type::left_chevron},
        {">", token::type::right_chevron},
        {"(", token::type::left_parentheses},
        {")", token::type::right_parentheses},
        {"=", token::type::assign},
        {"?=", token::type::conditional_assign},
        {"+=", token::type::append},
        {"?+=", token::type::conditional_append},
        {"==", token::type::compare},
        {",", token::type::parameter_delimiter},
        {".", token::type::member_accessor},
        {"+", token::type::concatonate},
        {";", token::type::statement_delimiter}
    };
};
