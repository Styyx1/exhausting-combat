#include "Menu/ingame-menu.h"
#include "SKSE/API.h"
#include "Utility/util.h"
#include "config.h"
#include "hooks.h"

void Listener(SKSE::MessagingInterface::Message* a_msg)
{
    switch (a_msg->type)
    {
        case SKSE::MessagingInterface::kDataLoaded:
            EXCO::Util::LookupStaminaCostGlobal();
            EXCO::FMenu::RegisterFMenu();
            break;
        default:
            break;
    }
}

SKSE_PLUGIN_LOAD(const SKSE::LoadInterface* a_skse)
{
    SKSE::Init(a_skse, {.trampoline = true});
    EXCO::CONFIG::UpdateSettings(false);
    SKSE::GetMessagingInterface()->RegisterListener(Listener);

    return true;
}
