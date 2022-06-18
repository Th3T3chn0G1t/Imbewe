// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#include "include/imbewe.hpp"

namespace imbewe {
    source::source(const std::filesystem::path& from) : path(from) {
        std::ifstream file_stream(from, std::ios::in | std::ios::binary);
        const std::size_t file_size = std::filesystem::file_size(from);
        this->buffer = std::make_shared<std::string>(file_size, '\0');
        file_stream.read(this->buffer->data(), file_size);
    }

    std::vector<token> source::tokenize() {
        std::vector<token> tokens{};

        for(std::string::iterator i = this->buffer->begin(); i < this->buffer->end();) {
            char c = *i;

            std::string::iterator start = i;
            std::string::iterator end = this->buffer->end();
            token t{token::type::none, 0, 0};
            if(c == '\'') {
                start++;
                end = std::find(start, this->buffer->end(), '\'');
                t.token_type = token::type::string_literal;
            }
            else if(is_identifier_char(c)) {
                end = std::find_if_not(i, this->buffer->end(), is_identifier_char);
                token::map::const_iterator found = token::keywords.find(std::string(start, end));
                if(found != token::keywords.end()) t.token_type = found->second;
                else t.token_type = token::type::identifier;
            }
            else if(is_operator_char(c)) {
                end = std::find_if_not(i, this->buffer->end(), is_operator_char);
                token::map::const_iterator found = token::operators.find(std::string(start, end));
                if(found != token::operators.end()) t.token_type = found->second;
                else {
                    std::cerr << "Unknown token: " << std::string(i, end) << std::endl;
                    i = end + 1;
                    continue;
                }
            }
            else if(is_blank_char(c)) {
                i++;
                continue;
            }
            else {
                std::cerr << "Unknown token: " << *i << std::endl;
            }

            t.offset = start - this->buffer->begin();
            t.length = end - start;
            tokens.push_back(t);

            i = end + 1;
        }

        return std::move(tokens);
    }
};
