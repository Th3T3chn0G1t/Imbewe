// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#pragma once

#include <string>
#include <string_view>
#include <filesystem>
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <span>

#include <cstdint>
#include <cstddef>
#include <cstring>

#include "token.hpp"
#include "source.hpp"
#include "syntax.hpp"
#include "value.hpp"

namespace imbewe {
    bool is_identifier_char(const char c);
    bool is_operator_char(const char c);
    bool is_blank_char(const char c);
    std::vector<std::string> split(const std::string& str, const char delimiter);

    // https://stackoverflow.com/a/25231384/13771204
    template<typename Base, typename T>
    inline bool instanceof(const T& v) {
        return dynamic_cast<const Base*>(&v) != nullptr;
    }

    program parse(const std::vector<token>& tokens);
};
