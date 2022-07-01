// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#include "include/imbewe.hpp"

void print_statements(const std::vector<imbewe::statement>& statements) {
    for(const auto& statement : statements) {
        if(instanceof<imbewe::control_flow_block>(statement)) {

        }
        else if(instanceof<imbewe::control_flow>(statement)) {
            
        }

        else if(instanceof<imbewe::string_literal>(statement)) {
            
        }
        else if(instanceof<imbewe::map_literal>(statement)) {
            
        }

        else if(instanceof<imbewe::binary_operation>(statement)) {
            
        }
        else if(instanceof<imbewe::operation>(statement)) {
            
        }

        else if(instanceof<imbewe::block>(statement)) {
            print_statements(dynamic_cast<const imbewe::block&>(statement).statements);
        }
    }
}

int main(int argc, char** argv) {
    std::filesystem::path file("./build.imbewe");
    if(argc > 1) file = argv[1];

    imbewe::source source(file);
    std::vector<imbewe::token> tokens = source.tokenize();

    imbewe::program program = imbewe::parse(tokens);
    print_statements(program.statements);
}
