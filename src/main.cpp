#include "pch.h"

// CommonLibSSE-NG exports the correctly named SKSEPlugin_Load entry point
// through this macro. The spelling is case-sensitive.
SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
    SKSE::Init(a_skse);

    logs::info("SwingFury loaded");

    return true;
}
