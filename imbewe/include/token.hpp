// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#pragma once

namespace imbewe {
    class token {
    public:
        enum class type {
            none,

            newline,

            keyword_intrin,
            keyword_config,
            keyword_var,
            keyword_task,

            keyword_if,
            keyword_elif,
            keyword_else,

            keyword_while,
            keyword_for,
            keyword_forin,

            keyword_break,
            keyword_continue,
            keyword_return,

            keyword_and,
            keyword_or,
            keyword_not,

            left_brace,
            right_brace,

            left_bracket,
            right_bracket,

            left_chevron,
            right_chevron,

            left_parentheses,
            right_parentheses,

            string_literal,

            assign,
            conditional_assign,
            append,
            conditional_append,

            compare,

            parameter_delimiter,

            member_accessor,

            concatonate,

            identifier
        };

        using map = std::unordered_map<std::string, token::type>;
        static const map keywords;
        static const map operators;

        type kind{type::none};

        std::size_t offset{0};
        std::size_t length{0};
    };
};
