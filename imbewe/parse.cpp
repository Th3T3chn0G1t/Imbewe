// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#include "include/imbewe.hpp"

namespace imbewe {
    block parse_block(const std::vector<token>& tokens, std::size_t offset) {
        while(offset < tokens.size() && tokens[offset].kind != token::type::right_brace) {
            switch() {
                
            }
        }
    }

    program parse(const std::vector<token>& tokens) {
        program out{};

        out.statements = std::move(parse_block(tokens, 0).statements);

        return out;
    }
}
