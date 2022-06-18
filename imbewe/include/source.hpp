// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 TTG <prs.ttg+imbewe@pm.me>

#pragma once

namespace imbewe {
    class source {
    public:
        std::shared_ptr<std::string> buffer;
        std::filesystem::path path;

        source(const std::filesystem::path& from);

        std::vector<token> tokenize();
    };
};
