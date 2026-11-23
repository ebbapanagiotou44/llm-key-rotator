// cooldowns.cpp — part of llm-key-rotator.

#include "llmkeyrotator/cooldowns.h"

#include <cstdio>

namespace llmkeyrotator {

Cooldowns::Cooldowns(const std::string& config_path)
    : config_path_(config_path) {}

void Cooldowns::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Cooldowns::run() {
    if (verbose_) std::fprintf(stderr, "[llm-key-rotator] cooldowns: run\n");
    // core logic lives here
    return true;
}

}  // namespace llmkeyrotator
