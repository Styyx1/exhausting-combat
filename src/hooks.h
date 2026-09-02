#pragma once

#include "RE/Offsets_VTABLE.h"
#include "REL/Relocation.h"
#include "REL/THook.h"
namespace EXCO
{
namespace HOOKS
{

struct PlayerUpdateHook
{
    static void Call(RE::PlayerCharacter* a_this, float a_deltaTime);
    static inline REL::THookVFT func{RE::PlayerCharacter::VTABLE[0], 0xad, Call};
};

struct NPCUpdateHook
{
    static void Call(RE::Actor* a_this, float a_deltaTime);
    static inline REL::THookVFT func{RE::Character::VTABLE[0], 0xad, Call};
};


struct JumpGetScaleHook
{
    static float Call(RE::TESObjectREFR* a_this);
    static inline REL::THook func{REL::ID(37257), 0x17f, Call};
};

struct StartCastingHook
{
    static void Call(RE::ActorMagicCaster* a_this);
    static inline REL::THookVFT func{RE::VTABLE_ActorMagicCaster[0], 0x06, Call};
};


struct CasterUpdateHook
{
    static void Call(RE::ActorMagicCaster* a_this, float a_deltaTime);
    static inline REL::THookVFT func{RE::VTABLE_MagicCaster[0], 0x1d, Call};
};

struct AttackStamCostHook
{
    static float Call(RE::ActorValueOwner* a_this, RE::BGSAttackData* a_attack);
    static inline REL::THook func{REL::ID(38603), 0x171, Call};
};

struct AttackChance
{
    static float Call(RE::Actor* a_attacker, RE::Actor* a_victim, RE::BGSAttackData* a_attack);
    static inline REL::THook func{REL::ID(49170), 0x28d, Call};
};

struct FireArrowHook
{
    static void Call(RE::TESObjectWEAP* a_weapon, RE::TESObjectREFR* a_source, RE::TESAmmo* a_overwriteAmmo,
                     RE::EnchantmentItem* a_ammoEnch, RE::AlchemyItem* a_poison);
    static inline REL::THook func{REL::ID(42859), 0x138, Call};
};
} // namespace HOOKS
} // namespace EXCO