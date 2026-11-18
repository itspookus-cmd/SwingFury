#include "pch.h"

SKSE_PLUGIN_LOAD(const SKSE::LoadInterface* a_skse)
{
    SKSE::Init(a_skse);

    logs::info("SwingFury loaded. Runtime: {}", REL::Module::get().version().string());

    return true;
}
