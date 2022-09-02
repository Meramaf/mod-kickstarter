#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

bool kickstarterRequireToken;
uint32 kickstarterLevel;

enum KickstarterSpecialization
{
    SPECIALIZATION_1 = 0,
    SPECIALIZATION_2 = 1,
    SPECIALIZATION_3 = 2,
};

enum KickstarterItemInfo
{
    ITEM_ID = 0,
    ITEM_RANDOM_PROPERTY = 1,
};

class Kickstarter : public CreatureScript
{
public:
    Kickstarter() : CreatureScript("npc_kickstarter") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        ClearGossipMenuFor(player);

        switch (player->getClass())
        {
        case CLASS_WARRIOR:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Arms", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Fury", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Protection", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        case CLASS_PALADIN:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Holy", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Protection", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Retribution", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        case CLASS_HUNTER:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Beast Mastery", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Marksmanship", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Survival", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        case CLASS_ROGUE:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Assassination", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Combat", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Subtlety", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        case CLASS_PRIEST:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Discipline", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Holy", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Shadow", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        case CLASS_DEATH_KNIGHT:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Blood", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Frost", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Unholy", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        case CLASS_SHAMAN:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Elemental", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Enhancement", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Restoration", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        case CLASS_MAGE:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Arcane", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Fire", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Frost", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        case CLASS_WARLOCK:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Affliction", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Demonology", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Destruction", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        case CLASS_DRUID:
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Balance", GOSSIP_SENDER_MAIN, SPECIALIZATION_1, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Feral", GOSSIP_SENDER_MAIN, SPECIALIZATION_2, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to use Restoration", GOSSIP_SENDER_MAIN, SPECIALIZATION_3, "Are you absolutely certain you want to do this? All of your current equipment will be deleted!", 0, false);
            break;
        }

        if (kickstarterRequireToken)
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "How many tokens do I have?", GOSSIP_SENDER_MAIN, 3);

        SendGossipMenuFor(player, 48, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (sender != GOSSIP_SENDER_MAIN)
            return false;

        if (action == SPECIALIZATION_1 || action == SPECIALIZATION_2 || action == SPECIALIZATION_3)
            Kickstart(player, action);
        else if (action == 3)
            GetTokenStatus(player);

        CloseGossipMenuFor(player);
        return true;
    }

private:
    void Kickstart(Player* player, uint32 specialization)
    {
        if (!HasToken(player))
        {
            ChatHandler(player->GetSession()).SendSysMessage("You have no tokens available.");
            return;
        }

        if (player->getLevel() > kickstarterLevel)
        {
            ChatHandler(player->GetSession()).PSendSysMessage("This feature can only be used at or below level %i.", kickstarterLevel);
            return;
        }

        SetPlayerLevel(player, kickstarterLevel);
        SetWeaponSkills(player, specialization);
        SetEquipment(player, specialization, kickstarterLevel);
        RemoveToken(player);
    }

    void GetTokenStatus(Player* player)
    {
        uint32 tokens = 0;
        QueryResult result = LoginDatabase.Query("SELECT tokens FROM kickstarter_tokens WHERE account_id={}",
            player->GetSession()->GetAccountId());

        if (result)
            tokens = result->Fetch()->Get<uint32>();

        ChatHandler(player->GetSession()).PSendSysMessage("You have %s %s available.", (tokens > 0) ? std::to_string(tokens) : "no", (tokens == 0 || tokens > 1) ? "tokens" : "token");
    }

    bool HasToken(Player* player)
    {
        uint32 tokens = 0;
        QueryResult result = LoginDatabase.Query("SELECT tokens FROM kickstarter_tokens WHERE account_id={}",
            player->GetSession()->GetAccountId());

        if (result)
            tokens = result->Fetch()->Get<uint32>();

        if (kickstarterRequireToken && tokens == 0)
            return false;

        return true;
    }

    void SetPlayerLevel(Player* player, uint32 level)
    {
        if (player->getLevel() != level)
        {
            player->SetLevel(level, true);

            player->resetTalents(true);
            player->InitTalentForLevel();
            player->UpdateSkillsForLevel();

            if (player->getClass() == CLASS_HUNTER)
                player->SendTalentsInfoData(true);

            player->SetFullHealth();
            player->ResetAllPowers();
        }
    }

    void SetWeaponSkills(Player* player, uint32 specialization)
    {
        player->SetSkill(SKILL_DEFENSE, 0, player->GetMaxSkillValue(SKILL_DEFENSE), player->GetMaxSkillValue(SKILL_DEFENSE));

        switch (player->getClass())
        {
        case CLASS_WARRIOR:
        case CLASS_PALADIN:
            if (!player->HasSkill(SKILL_PLATE_MAIL))
                player->learnSpell(750);

            if (player->getClass() == CLASS_WARRIOR)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3)
                {
                    if (!player->HasSkill(SKILL_SWORDS))
                        player->learnSpell(201);

                    player->SetSkill(SKILL_SWORDS, 0, player->GetMaxSkillValue(SKILL_SWORDS), player->GetMaxSkillValue(SKILL_SWORDS));
                }

                if (!player->HasSkill(SKILL_BOWS))
                    player->learnSpell(264);

                player->SetSkill(SKILL_BOWS, 0, player->GetMaxSkillValue(SKILL_BOWS), player->GetMaxSkillValue(SKILL_BOWS));

                if (specialization == SPECIALIZATION_1)
                {
                    if (!player->HasSkill(SKILL_DUAL_WIELD))
                        player->learnSpell(674);
                }
                else if (specialization == SPECIALIZATION_2)
                {
                    if (!player->HasSkill(SKILL_2H_SWORDS))
                        player->learnSpell(202);
                }
            }
            else if (player->getClass() == CLASS_PALADIN)
            {
                if (specialization == SPECIALIZATION_1)
                {
                    if (!player->HasSkill(SKILL_MACES))
                        player->learnSpell(198);

                    player->SetSkill(SKILL_MACES, 0, player->GetMaxSkillValue(SKILL_MACES), player->GetMaxSkillValue(SKILL_MACES));
                }
                else if (specialization == SPECIALIZATION_2)
                {
                    if (!player->HasSkill(SKILL_SWORDS))
                        player->learnSpell(201);

                    player->SetSkill(SKILL_SWORDS, 0, player->GetMaxSkillValue(SKILL_SWORDS), player->GetMaxSkillValue(SKILL_SWORDS));
                }
                else if (specialization == SPECIALIZATION_3)
                {
                    if (!player->HasSkill(SKILL_2H_SWORDS))
                        player->learnSpell(202);

                    player->SetSkill(SKILL_2H_SWORDS, 0, player->GetMaxSkillValue(SKILL_2H_SWORDS), player->GetMaxSkillValue(SKILL_2H_SWORDS));
                }
            }
            break;
        case CLASS_HUNTER:
        case CLASS_SHAMAN:
            if (!player->HasSkill(SKILL_MAIL))
                player->learnSpell(8737);

            if (player->getClass() == CLASS_HUNTER)
            {
                if (!player->HasSkill(SKILL_STAVES))
                    player->learnSpell(227);

                player->SetSkill(SKILL_STAVES, 0, player->GetMaxSkillValue(SKILL_STAVES), player->GetMaxSkillValue(SKILL_STAVES));

                if (!player->HasSkill(SKILL_BOWS))
                    player->learnSpell(264);

                player->SetSkill(SKILL_BOWS, 0, player->GetMaxSkillValue(SKILL_BOWS), player->GetMaxSkillValue(SKILL_BOWS));
            }
            else if (player->getClass() == CLASS_SHAMAN)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3)
                {
                    if (!player->HasSkill(SKILL_MACES))
                        player->learnSpell(198);

                    player->SetSkill(SKILL_MACES, 0, player->GetMaxSkillValue(SKILL_MACES), player->GetMaxSkillValue(SKILL_MACES));
                }
                else if (specialization == SPECIALIZATION_2)
                {
                    if (!player->HasSkill(SKILL_2H_MACES))
                        player->learnSpell(199);

                    player->SetSkill(SKILL_MACES, 0, player->GetMaxSkillValue(SKILL_2H_MACES), player->GetMaxSkillValue(SKILL_2H_MACES));
                }
            }
            break;
        case CLASS_PRIEST:
        case CLASS_MAGE:
        case CLASS_WARLOCK:
        case CLASS_DRUID:
            if (player->getClass() == CLASS_PRIEST || player->getClass() == CLASS_MAGE || player->getClass() == CLASS_WARLOCK)
            {
                if (!player->HasSkill(SKILL_WANDS))
                    player->learnSpell(5009);

                player->SetSkill(SKILL_WANDS, 0, player->GetMaxSkillValue(SKILL_WANDS), player->GetMaxSkillValue(SKILL_WANDS));
            }

            if (!player->HasSkill(SKILL_STAVES))
                player->learnSpell(227);

            player->SetSkill(SKILL_STAVES, 0, player->GetMaxSkillValue(SKILL_STAVES), player->GetMaxSkillValue(SKILL_STAVES));
            break;
        case CLASS_ROGUE:
            if (!player->HasSkill(SKILL_DUAL_WIELD))
                player->learnSpell(674);

            if (!player->HasSkill(SKILL_DAGGERS))
                player->learnSpell(1180);

            player->SetSkill(SKILL_DAGGERS, 0, player->GetMaxSkillValue(SKILL_DAGGERS), player->GetMaxSkillValue(SKILL_DAGGERS));
            break;
        default:
            break;
        }
    }

/*
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_BODY][ITEM_ID] = 0; // Unused
            equipment[EQUIPMENT_SLOT_BODY][ITEM_RANDOM_PROPERTY] = 0; // Unused
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : 0;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;
*/

    void SetEquipment(Player* player, uint32 specialization, uint32 level)
    {
        uint32 equipment[18][2];

        uint32 playerClass = player->getClass();
        switch (playerClass)
        {
        case CLASS_WARRIOR:
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = level == 60 ? 14979 : 25018;
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 1232 : -41;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = level == 60 ? 12048 : 25070;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 1208 : -41;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = level == 60 ? 14981 : 25028;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 2151 : -41;
            equipment[EQUIPMENT_SLOT_BODY][ITEM_ID] = 0; // Unused
            equipment[EQUIPMENT_SLOT_BODY][ITEM_RANDOM_PROPERTY] = 0; // Unused
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = level == 60 ? 14975 : 25008;
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 1232 : -41;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = level == 60 ? 14977 : 25014;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 2151 : -41;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = level == 60 ? 14980 : 25019;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 2158 : -41;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = level == 60 ? 14978 : 25015;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 2154 : -41;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = level == 60 ? 14983 : 25021;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1205 : -41;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = level == 60 ? 14976 : 25017;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1217 : -41;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = level == 60 ? 12017 : 25056;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 1208 : -41;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = level == 60 ? 11980 : 25056;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 1206 : -41;
            if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
            {
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 17774 : 29776;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 5079 : 25937;
            }
            else if (specialization == SPECIALIZATION_3) // Protection
            {
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 1490 : 25787;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 4130 : 25996;
            }
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = level == 60 ? 15437 : 25042;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 1205 : -41;
            if (specialization == SPECIALIZATION_1) // Arms
            {
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15221 : 25154;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 1199 : -41;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = level == 60 ? 15219 : 25153;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 1197 : -41;
            }
            else if (specialization == SPECIALIZATION_2) // Fury
            {
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15256 : 25168;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 1226 : -41;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
            }
            else if (specialization == SPECIALIZATION_3) // Protection
            {
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15221 : 25154;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 1199 : -41;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = level == 60 ? 14982 : 25084;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 1197 : -41;
            }
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = level == 60 ? 15289 : 25252;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = level == 60 ? 683 : -41;

            if (specialization == SPECIALIZATION_3) // Protection
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 1231 : -16;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 1207 : -16;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 338 : -16;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 346 : -16;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 1213 : -16;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1228 : -16;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 338 : -16;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 287 : -16;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1216 : -16;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 333 : -16;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 333 : -16;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 287 : -16;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = level == 60 ? 185 : -16;
            }
            break;
        case CLASS_PALADIN:
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = level == 60 ? 14979 : 25018;
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 891 : -9;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = level == 60 ? 12048 : 25070;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 784 : -44;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = level == 60 ? 14981 : 25028;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 876 : -44;
            equipment[EQUIPMENT_SLOT_BODY][ITEM_ID] = 0; // Unused
            equipment[EQUIPMENT_SLOT_BODY][ITEM_RANDOM_PROPERTY] = 0; // Unused
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = level == 60 ? 14975 : 25008;
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 891 : -44;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = level == 60 ? 14977 : 25014;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 873 : -44;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = level == 60 ? 14980 : 25019;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 888 : -44;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = level == 60 ? 14978 : 25015;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 876 : -44;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = level == 60 ? 14983 : 25021;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 864 : -44;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = level == 60 ? 14976 : 25017;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 876 : -44;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = level == 60 ? 12017 : 25056;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 867 : -44;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = level == 60 ? 11980 : 25056;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 868 : -44;
            if (specialization == SPECIALIZATION_1) // Holy
            {
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 10659 : 25634;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 17774 : 30293;
            }
            else if (specialization == SPECIALIZATION_2) // Protection
            {
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 1490 : 25787;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 4130 : 25996;
            }
            else if (specialization == SPECIALIZATION_3) // Retribution
            {
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 17774 : 29776;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 5079 : 25937;
            }
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = level == 60 ? 15437 : 25042;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 864 : -44;
            if (specialization == SPECIALIZATION_1) // Holy
            {
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15229 : 25322;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 2040 : -44;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = level == 60 ? 14982 : 25084;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 2043 : -44;
            }
            else if (specialization == SPECIALIZATION_2) // Protection
            {
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15221 : 25154;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 1199 : -41;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = level == 60 ? 14982 : 25084;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 1197 : -41;
            }
            else if (specialization == SPECIALIZATION_3) // Retribution
            {
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15256 : 25168;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 1226 : -41;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
            }
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

            if (specialization == SPECIALIZATION_2) // Protection
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 1231 : -16;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 1207 : -16;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 338 : -16;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 346 : -16;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 1213 : -16;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1228 : -16;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 338 : -16;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 287 : -16;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1216 : -16;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 333 : -16;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 333 : -16;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 287 : -16;
            }
            else if (specialization == SPECIALIZATION_3) // Retribution
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 1232 : -41;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 1208 : -41;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 2151 : -41;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 1232 : -41;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 2151 : -41;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 2158 : -41;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 2154 : -41;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1205 : -41;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1217 : -41;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 1208 : -41;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 1206 : -41;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 1205 : -41;
            }
            break;
        case CLASS_HUNTER:
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = level == 60 ? 15684 : 24906;
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 468 : -5;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = level == 60 ? 12048 : 25070;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 612 : -5;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = level == 60 ? 15686 : 24908;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 621 : -5;
            equipment[EQUIPMENT_SLOT_BODY][ITEM_ID] = 0; // Unused
            equipment[EQUIPMENT_SLOT_BODY][ITEM_RANDOM_PROPERTY] = 0; // Unused
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = level == 60 ? 15680 : 24904;
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 636 : -5;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = level == 60 ? 15683 : 24902;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 618 : -5;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = level == 60 ? 15685 : 24907;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 633 : -5;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = level == 60 ? 15678 : 24903;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 621 : -5;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = level == 60 ? 15679 : 24909;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 609 : -5;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = level == 60 ? 15682 : 24905;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 621 : -5;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = level == 60 ? 12017 : 25056;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 612 : -5;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = level == 60 ? 12005 : 25055;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 609 : -5;
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 5079 : 29776;
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 17774 : 25937;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = level == 60 ? 10249 : 25042;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 609 : -5;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15278 : 25182;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 629 : -5;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = level == 60 ? 15289 : 25252;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = level == 60 ? 597 : -40;
            break;
        case CLASS_ROGUE:
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = level == 60 ? 15439 : 24794;
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 636 : -40;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = level == 60 ? 12048 : 25070;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 612 : -5;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = level == 60 ? 15441 : 24796;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 621 : -40;
            equipment[EQUIPMENT_SLOT_BODY][ITEM_ID] = 0; // Unused
            equipment[EQUIPMENT_SLOT_BODY][ITEM_RANDOM_PROPERTY] = 0; // Unused
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = level == 60 ? 15442 : 24792;
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 636 : -40;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = level == 60 ? 15434 : 24790;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 621 : -40;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = level == 60 ? 15440 : 24795;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 633 : -40;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = level == 60 ? 15435 : 24791;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 621 : -40;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = level == 60 ? 15436 : 24797;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 609 : -40;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = level == 60 ? 15438 : 24793;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 621 : -40;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = level == 60 ? 12017 : 25056;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 612 : -40;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = level == 60 ? 11992 : 25055;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 611 : -40;

            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 17774 : 29776;
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 5079 : 25937;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = level == 60 ? 10249 : 25042;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 609 : -40;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15247 : 25112;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 603 : -40;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = level == 60 ? 15246 : 25111;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 603 : -40;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = level == 60 ? 29203 : 28543;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = level == 60 ? 0 : -40;
            break;
        case CLASS_PRIEST:
        case CLASS_MAGE:
        case CLASS_WARLOCK:
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = level == 60 ? 14332 : 24681;
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 891 : -37;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = level == 60 ? 12027 : 25070;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 864 : -37;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = level == 60 ? 14335 : 24683;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 876 : -37;
            equipment[EQUIPMENT_SLOT_BODY][ITEM_ID] = 0; // Unused
            equipment[EQUIPMENT_SLOT_BODY][ITEM_RANDOM_PROPERTY] = 0; // Unused
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = level == 60 ? 14328 : 24679;
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 891 : -37;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = level == 60 ? 14337 : 24677;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 876 : -37;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = level == 60 ? 14334 : 24682;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 888 : -37;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = level == 60 ? 14329 : 24678;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 876 : -37;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = level == 60 ? 14330 : 24684;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 864 : -37;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = level == 60 ? 14333 : 24680;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 879 : -37;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = level == 60 ? 11992 : 25056;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 864 : -37;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = level == 60 ? 12017 : 25055;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 867 : -39;
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 10659 : 25634;
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 17774 : 30293;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = level == 60 ? 10249 : 25042;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 864 : -37;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15278 : 25181;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 802 : -39;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = level == 60 ? 15283 : 25294;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = level == 60 ? 854 : -39;
            break;
        case CLASS_DEATH_KNIGHT:
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = level == 60 ? 14979 : 25018;
            equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = level == 60 ? 1232 : -41;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = level == 60 ? 12048 : 25070;
            equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = level == 60 ? 1208 : -41;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = level == 60 ? 14981 : 25028;
            equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = level == 60 ? 2151 : -41;
            equipment[EQUIPMENT_SLOT_BODY][ITEM_ID] = 0; // Unused
            equipment[EQUIPMENT_SLOT_BODY][ITEM_RANDOM_PROPERTY] = 0; // Unused
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = level == 60 ? 14975 : 25008;
            equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = level == 60 ? 1232 : -41;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = level == 60 ? 14977 : 25014;
            equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = level == 60 ? 2151 : -41;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = level == 60 ? 14980 : 25019;
            equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = level == 60 ? 2158 : -41;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = level == 60 ? 14978 : 25015;
            equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = level == 60 ? 2154 : -41;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = level == 60 ? 14983 : 25021;
            equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1205 : -41;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = level == 60 ? 14976 : 25017;
            equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = level == 60 ? 1217 : -41;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = level == 60 ? 12017 : 25056;
            equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = level == 60 ? 1208 : -41;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = level == 60 ? 11980 : 25056;
            equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = level == 60 ? 1206 : -41;
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = level == 60 ? 17774 : 29776;
            equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = level == 60 ? 5079 : 25937;
            equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = level == 60 ? 15437 : 25042;
            equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = level == 60 ? 1205 : -41;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = level == 60 ? 15258 : 25168;
            equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = level == 60 ? 1232 : -41;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
            equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
            equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;
            break;
        case CLASS_SHAMAN: // Elemental, Enhancement, Restoration
            break;
        case CLASS_DRUID: // Balance, Feral, Restoration
            break;
        }

        for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_TABARD; slot++)
        {
            player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

            uint32 itemId = equipment[slot][ITEM_ID];
            uint32 randomProperty = equipment[slot][ITEM_RANDOM_PROPERTY];

            if (itemId > 0)
                if (sObjectMgr->GetItemTemplate(itemId))
                {
                    if (Item* item = Item::CreateItem(itemId, 1, player, false, randomProperty > 0 ? randomProperty : 0))
                    {
                        if (randomProperty < 0)
                            item->SetUInt32Value(ITEM_FIELD_PROPERTY_SEED, std::abs((int)randomProperty));

                        player->EquipItem(slot, item, true);
                    }
                }
        }
    }

    void RemoveToken(Player* player)
    {
        if (kickstarterRequireToken)
            QueryResult result = LoginDatabase.Query("UPDATE `kickstarter_tokens` SET `tokens` = `tokens` - 1 WHERE `account_id` = {}",
                player->GetSession()->GetAccountId());
    }
};

class KickstarterConfiguration : public WorldScript
{
public:
    KickstarterConfiguration() : WorldScript("KickstarterConfiguration") {}

    void OnAfterConfigLoad(bool /*reload*/) override
    {
        kickstarterRequireToken = sConfigMgr->GetOption<bool>("Kickstarter.RequireToken", 1);
        kickstarterLevel = sConfigMgr->GetOption<uint32>("Kickstarter.Level", 60);

        if (kickstarterLevel != 60 && kickstarterLevel != 70)
            kickstarterLevel = 60;
    }
};

void AddSC_mod_kickstarter()
{
    new Kickstarter();
    new KickstarterConfiguration();
}
