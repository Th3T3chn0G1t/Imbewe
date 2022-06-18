// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#include "include/imbewe.hpp"

namespace imbewe {
    bool is_identifier_char(const char c) {
        return !is_operator_char(c) && c != '\'' && !is_blank_char(c);
    }
    bool is_operator_char(const char c) {
        return c == '{' || c == '}' || c == '[' || c == ']' || c == '<' || c == '>' || c == '(' || c == ')' || c == '=' || c == '?' || c == ',' || c == '.' || c == '+' || c == ';';
    }
    bool is_blank_char(const char c) {
        return isblank(c) || c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }

    std::vector<std::string> split(const std::string& str, const char delimiter) {
        std::vector<std::string> out{};

        std::string::const_iterator it = str.begin();
        while(it < str.end()) {
            std::string::const_iterator end = std::min(std::find(it, str.end(), delimiter), str.end() - 1);
            out.push_back(std::string(it, end));
            it = end + 1;
        }

        return std::move(out);
    }
};
