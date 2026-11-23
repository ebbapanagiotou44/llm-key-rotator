// main.cpp — entry point. Wires config and subsystems together.

#include "llmkeyrotator/settings.h"
#include "llmkeyrotator/pool.h"
#include "llmkeyrotator/proxy.h"
#include "llmkeyrotator/cooldowns.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    llmkeyrotator::Settings settings = llmkeyrotator::Settings::load_default();
    llmkeyrotator::Pool pool(settings.store_path);
    llmkeyrotator::Proxy proxy(settings.store_path);
    llmkeyrotator::Cooldowns cooldowns(settings.store_path);
    std::fprintf(stderr, "[llm-key-rotator] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
