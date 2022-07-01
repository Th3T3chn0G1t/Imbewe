// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#pragma once

namespace imbewe {
    class type {
    public:
        std::string name;
    };

    class string : public type {
    public:
        std::string name{"string"};
    };

    class map : public type {
    public:
        std::string name{"map"};
        std::unordered_map<std::string, variable> values;
    };

    class value {
    public:
        std::string value;
    };

    class variable {
    public:
        type type;
        std::string name;
        std::unique_ptr<value> value;
    };

    class object : public type {
    public:
        std::unordered_map<std::string, variable> members;
    };
}
