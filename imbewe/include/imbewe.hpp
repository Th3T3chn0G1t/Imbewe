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

#include <cstdint>
#include <cstddef>
#include <cstring>

#include "token.hpp"
#include "source.hpp"

namespace imbewe {
    bool is_identifier_char(const char c);
    bool is_operator_char(const char c);
    bool is_blank_char(const char c);
    std::vector<std::string> split(const std::string& str, const char delimiter);
};
