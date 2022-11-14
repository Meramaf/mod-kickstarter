#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

bool kickstarterRequireToken;
uint32 kickstarterLevel;

bool kickstarterMoney;
uint32 kickstarterMoneyAmount[3];

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

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 sender, uint32 action)
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

        if (player->getLevel() >= kickstarterLevel)
        {
            ChatHandler(player->GetSession()).PSendSysMessage("This feature can only be used below level %i.", kickstarterLevel);
            return;
        }

        SetPlayerLevel(player);
        SetWeaponSkills(player, specialization);
        SetEquipment(player, specialization);
        AddTaxiPaths(player);
        AddMoney(player);
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

    void SetPlayerLevel(Player* player)
    {
        if (player->getLevel() != kickstarterLevel)
        {
            player->SetLevel(kickstarterLevel, true);

            player->resetTalents(true);
            player->InitTalentForLevel();
            player->UpdateSkillsForLevel();

            if (player->getClass() == CLASS_HUNTER)
                player->SendTalentsInfoData(true);

            player->SetFullHealth();
            player->ResetAllPowers();

            player->CheckAllAchievementCriteria();
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

            if (!player->HasSkill(SKILL_THROWN))
                player->learnSpell(2567);

            player->SetSkill(SKILL_THROWN, 0, player->GetMaxSkillValue(SKILL_THROWN), player->GetMaxSkillValue(SKILL_THROWN));
            break;
        default:
            break;
        }
    }

    void SetEquipment(Player* player, uint32 specialization)
    {
        uint32 equipment[18][2];

        equipment[EQUIPMENT_SLOT_BODY][ITEM_ID] = 0; // Unused
        equipment[EQUIPMENT_SLOT_BODY][ITEM_RANDOM_PROPERTY] = 0; // Unused
        equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_RANDOM_PROPERTY] = 0;
        equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_RANDOM_PROPERTY] = 0;

        switch (player->getClass())
        {
        case CLASS_WARRIOR:
            if (kickstarterLevel == 60)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 14979;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 1232;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 12048;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 1208;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 14981;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 2151;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 14975;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 1232;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 14977;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 2151;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 14980;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 2158;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 14978;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 2154;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 14983;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 1205;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 14976;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 1217;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 12017;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 1208;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 11980;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 1206;
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 17774;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 5079;
                }
                else if (specialization == SPECIALIZATION_3) // Protection
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 1490;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 4130;
                }
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 15437;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 1205;
                if (specialization == SPECIALIZATION_1) // Arms
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15221;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 1199;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 15219;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 1197;
                }
                else if (specialization == SPECIALIZATION_2) // Fury
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15256;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 1226;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
                else if (specialization == SPECIALIZATION_3) // Protection
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15221;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 1199;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 14982;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 1197;
                }
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 15289;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 683;

                if (specialization == SPECIALIZATION_3) // Protection
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 1231;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 1207;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 338;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 346;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 1213;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 1228;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 338;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 287;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 1216;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 333;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 333;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 287;
                    equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 185;
                }
            }
            else if (kickstarterLevel == 70)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 25018;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 25070;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 25028;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 25008;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 25014;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 25019;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 25015;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 25021;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 25017;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -41;
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 29776;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 25937;
                }
                else if (specialization == SPECIALIZATION_3) // Protection
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 25787;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 25996;
                }
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 25042;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -41;
                if (specialization == SPECIALIZATION_1) // Arms
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25154;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 25153;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -41;
                }
                else if (specialization == SPECIALIZATION_2) // Fury
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25168;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
                else if (specialization == SPECIALIZATION_3) // Protection
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25154;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 25084;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -41;
                }
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 25252;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = -41;

                if (specialization == SPECIALIZATION_3) // Protection
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = -16;
                }
            }
            else if (kickstarterLevel == 80)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 36327;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 36435;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 36329;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 36325;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 36323;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 36328;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 36324;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 36330;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 36326;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 36421;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 36420;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 38080;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 38081;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 36407;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -7;
                if (specialization == SPECIALIZATION_1) // Arms
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 38146;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 38198;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
                else if (specialization == SPECIALIZATION_2) // Fury
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 38181;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
                else if (specialization == SPECIALIZATION_3) // Protection
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 38146;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 36449;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -45;
                }
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 38157;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_3) // Protection
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -45;
                }
            }
            break;
        case CLASS_PALADIN:
            if (kickstarterLevel == 60)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 14979;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 891;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 12048;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 784;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 14981;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 14975;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 891;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 14977;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 873;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 14980;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 888;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 14978;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 14983;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 14976;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 12017;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 867;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 11980;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 868;
                if (specialization == SPECIALIZATION_1) // Holy
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 10659;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 17774;
                }
                else if (specialization == SPECIALIZATION_2) // Protection
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 1490;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 4130;
                }
                else if (specialization == SPECIALIZATION_3) // Retribution
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 17774;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 5079;
                }
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 15437;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 864;
                if (specialization == SPECIALIZATION_1) // Holy
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15229;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 2040;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 14982;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 2043;
                }
                else if (specialization == SPECIALIZATION_2) // Protection
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15221;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 1199;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 14982;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 1197;
                }
                else if (specialization == SPECIALIZATION_3) // Retribution
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15256;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 1226;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_2) // Protection
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 1231;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 1207;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 338;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 346;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 1213;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 1228;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 338;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 287;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 1216;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 333;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 333;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 287;
                }
                else if (specialization == SPECIALIZATION_3) // Retribution
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 1232;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 1208;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 2151;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 1232;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 2151;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 2158;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 2154;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 1205;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 1217;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 1208;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 1206;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 1205;
                }
            }
            else if (kickstarterLevel == 70)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 25018;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -9;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 25070;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 25028;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 25008;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 25014;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 25019;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 25015;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 25021;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 25017;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -44;
                if (specialization == SPECIALIZATION_1) // Holy
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 25634;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 30293;
                }
                else if (specialization == SPECIALIZATION_2) // Protection
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 25787;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 25996;
                }
                else if (specialization == SPECIALIZATION_3) // Retribution
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 29776;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 25937;
                }
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 25042;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -44;
                if (specialization == SPECIALIZATION_1) // Holy
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25322;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -44;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 25084;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -44;
                }
                else if (specialization == SPECIALIZATION_2) // Protection
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25154;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 25084;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -41;
                }
                else if (specialization == SPECIALIZATION_3) // Retribution
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25168;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_2) // Protection
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -16;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -16;
                }
                else if (specialization == SPECIALIZATION_3) // Retribution
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -41;
                }
            }
            else if (kickstarterLevel == 80)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 36327;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 36435;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 36329;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 36325;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 36323;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 36328;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 36324;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 36330;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 36326;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 36421;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 36420;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -37;

                if (specialization == SPECIALIZATION_1) // Holy
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 38073;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 35935;
                }
                else if (specialization == SPECIALIZATION_2 || specialization == SPECIALIZATION_3) // Protection, Retribution
                {
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 38080;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 38081;
                }
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 36407;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -37;
                if (specialization == SPECIALIZATION_1) // Holy
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 36490;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -44;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 36449;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -36;
                }
                else if (specialization == SPECIALIZATION_2) // Protection
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 36518;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 36449;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -45;
                }
                else if (specialization == SPECIALIZATION_3) // Retribution
                {
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 36532;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_2) // Protection
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -45;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -45;
                }
                else if (specialization == SPECIALIZATION_3) // Retribution
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -43;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -43;
                }
            }
            break;
        case CLASS_HUNTER:
            if (kickstarterLevel == 60)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 15684;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 468;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 12048;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 612;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 15686;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 621;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 15680;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 636;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 15683;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 618;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 15685;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 633;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 15678;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 621;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 15679;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 609;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 15682;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 621;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 12017;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 612;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 12005;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 609;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 5079;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 17774;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 10249;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 609;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15278;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 629;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 15289;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 597;
            }
            else if (kickstarterLevel == 70)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 24906;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 25070;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 24908;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 24904;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 24902;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 24907;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 24903;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 24909;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 24905;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 25055;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 29776;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 25937;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 25042;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25182;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 25252;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = -40;
            }
            else if (kickstarterLevel == 80)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 36215;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 36435;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 36217;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 36213;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 36211;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 36216;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 36212;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 36218;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 36214;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 36421;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 36420;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 38080;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 38081;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 36407;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 36602;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 36616;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = -40;
            }
            break;
        case CLASS_ROGUE:
            if (kickstarterLevel == 60)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 15439;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 636;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 12048;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 612;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 15441;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 621;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 15442;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 636;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 15434;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 621;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 15440;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 633;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 15435;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 621;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 15436;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 609;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 15438;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 621;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 12017;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 612;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 11992;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 611;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 17774;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 5079;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 10249;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 609;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15247;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 603;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 15246;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 603;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 29203;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;
            }
            else if (kickstarterLevel == 70)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 24794;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 25070;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -5;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 24796;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 24792;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 24790;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 24795;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 24791;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 24797;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 24793;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 25055;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 29776;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 25937;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 25042;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25112;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 25111;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 28543;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = -40;
            }
            else if (kickstarterLevel == 80)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 36103;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 36435;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 36105;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 36101;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 36099;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 36104;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 36100;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 36106;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 36102;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 36421;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 36420;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 38080;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 38081;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 36407;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -40;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 38151;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 38155;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 36616;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = -40;
            }
            break;
        case CLASS_PRIEST:
        case CLASS_MAGE:
        case CLASS_WARLOCK:
            if (kickstarterLevel == 60)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 14332;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 891;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 12027;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 14335;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 14328;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 891;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 14337;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 14334;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 888;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 14329;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 14330;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 14333;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 879;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 11992;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 12017;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 867;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 10659;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 17774;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 10249;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15278;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 802;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 15283;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 854;
            }
            else if (kickstarterLevel == 70)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 24681;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 25070;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 24683;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 24679;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 24677;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 24682;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 24678;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 24684;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 24680;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 25055;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 25634;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 30293;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 25042;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25181;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 25294;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = -39;
            }
            else if (kickstarterLevel == 80)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 35991;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 36435;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 35993;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 35989;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 35987;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 35992;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 35988;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 35994;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 35990;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 36421;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 36420;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 35935;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 37555;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 36407;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 36546;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 36658;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = -39;
            }
            break;
        case CLASS_DEATH_KNIGHT:
            if (kickstarterLevel == 60)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 14979;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 1232;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 12048;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 1208;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 14981;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 2151;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 14975;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 1232;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 14977;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 2151;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 14980;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 2158;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 14978;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 2154;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 14983;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 1205;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 14976;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 1217;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 12017;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 1208;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 11980;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 1206;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 17774;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 5079;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 15437;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 1205;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15258;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 1232;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;
            }
            else if (kickstarterLevel == 70)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 25018;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 25070;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 25028;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 25008;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 25014;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 25019;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 25015;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 25021;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 25017;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 29776;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 25937;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 25042;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25168;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;
            }
            else if (kickstarterLevel == 80)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 36327;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 36435;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 36329;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 36325;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 36323;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 36328;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 36324;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 36330;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 36326;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 36421;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 36420;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 38080;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 38081;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 36407;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -7;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 36532;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -41;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;
            }
            break;
        case CLASS_SHAMAN:
            if (kickstarterLevel == 60)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 15684;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 891;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 12027;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 15686;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 15680;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 891;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 15683;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 873;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 15685;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 888;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 15678;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 15679;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 15682;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 12017;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 867;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 11992;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 611;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 10659;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 17774;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 10249;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15229;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 2040;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 10367;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 384;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_2) // Enhancement
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 636;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 287;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 621;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 639;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 618;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 633;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 621;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 609;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 621;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 612;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 611;
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 17774;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 5079;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 609;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15267;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 633;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
            }
            else if (kickstarterLevel == 70)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 24906;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 25070;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 24908;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 24904;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 24902;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 24907;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 24903;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 24909;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 24905;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 25057;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 25634;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 30293;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 25042;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25323;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 25084;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_2) // Enhancement
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 29776;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 25937;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25140;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -5;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
            }
            else if (kickstarterLevel == 80)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 36215;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 36435;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 36217;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 36213;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 36211;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 36216;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 36212;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 36218;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 36214;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 36421;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 36420;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 35935;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 37555;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 36407;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 36686;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -44;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 36449;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_2) // Enhancement
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 38080;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 38081;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 36504;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -41;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                    equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                }
            }
            break;
        case CLASS_DRUID:
            if (kickstarterLevel == 60)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 10261;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 888;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 12048;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 867;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 10263;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 10264;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 891;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 10259;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 10262;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 891;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 10257;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 10256;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 10260;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 876;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 12017;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 867;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 12005;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 865;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 10659;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 17774;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 10249;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 864;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 15278;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 885;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_2) // Feral
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = 633;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = 612;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = 621;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = 636;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = 621;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = 636;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = 621;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = 609;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = 621;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = 612;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = 609;
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 17774;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 5079;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = 609;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = 630;
                }
            }
            else if (kickstarterLevel == 70)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 24802;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 25070;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 24804;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 24800;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 24798;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 24803;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 24799;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 24805;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 24801;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 25057;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 25056;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 25634;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 30293;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 25042;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 25182;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -39;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_2) // Feral
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 29776;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 25937;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -40;
                }
            }
            else if (kickstarterLevel == 80)
            {
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_ID] = 36103;
                equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_ID] = 36435;
                equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_ID] = 36105;
                equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_ID] = 36101;
                equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_ID] = 36099;
                equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_ID] = 36104;
                equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_ID] = 36100;
                equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_ID] = 36106;
                equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_ID] = 36102;
                equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_ID] = 36421;
                equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_ID] = 36420;
                equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 35935;
                equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 37555;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_ID] = 36407;
                equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -37;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_ID] = 36602;
                equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -36;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_OFFHAND][ITEM_RANDOM_PROPERTY] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_ID] = 0;
                equipment[EQUIPMENT_SLOT_RANGED][ITEM_RANDOM_PROPERTY] = 0;

                if (specialization == SPECIALIZATION_2) // Feral
                {
                    equipment[EQUIPMENT_SLOT_HEAD][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_NECK][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_SHOULDERS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_CHEST][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_WAIST][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_LEGS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FEET][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_WRISTS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_HANDS][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FINGER1][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_FINGER2][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_TRINKET1][ITEM_ID] = 38080;
                    equipment[EQUIPMENT_SLOT_TRINKET2][ITEM_ID] = 38081;
                    equipment[EQUIPMENT_SLOT_BACK][ITEM_RANDOM_PROPERTY] = -40;
                    equipment[EQUIPMENT_SLOT_MAINHAND][ITEM_RANDOM_PROPERTY] = -40;
                }
            }
            break;
        }

        for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_TABARD; slot++)
        {
            player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

            uint32 itemId = equipment[slot][ITEM_ID];
            uint32 randomProperty = equipment[slot][ITEM_RANDOM_PROPERTY];

            if (itemId > 0)
            {
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
    }

    void AddTaxiPaths(Player* player)
    {
        player->GetSession()->SendDiscoverNewTaxiNode(79); // Marshal's Refuge, Un'Goro Crater
        player->GetSession()->SendDiscoverNewTaxiNode(80); // Ratchet, The Barrens
        player->GetSession()->SendDiscoverNewTaxiNode(166); // Emerald Sanctuary, Felwood
        player->GetSession()->SendDiscoverNewTaxiNode(179); // Mudsprocket, Dustwallow Marsh
        player->GetSession()->SendDiscoverNewTaxiNode(205); // Hatchet Hills, Ghostlands
        player->GetSession()->SendDiscoverNewTaxiNode(383); // Thondoril River, Western Plaguelands

        if (player->GetTeamId() == TEAM_ALLIANCE)
        {
            player->GetSession()->SendDiscoverNewTaxiNode(2); // Stormwind City
            player->GetSession()->SendDiscoverNewTaxiNode(4); // Sentinel Hill, Westfall
            player->GetSession()->SendDiscoverNewTaxiNode(5); // Lakeshire, Redridge Mountains
            player->GetSession()->SendDiscoverNewTaxiNode(6); // Ironforge, Dun Morogh
            player->GetSession()->SendDiscoverNewTaxiNode(7); // Menethil Harbor, Wetlands
            player->GetSession()->SendDiscoverNewTaxiNode(8); // Thelsamar, Loch Modan
            player->GetSession()->SendDiscoverNewTaxiNode(12); // Darkshire, Duskwood
            player->GetSession()->SendDiscoverNewTaxiNode(14); // Southshore, Hillsbrad Foothills
            player->GetSession()->SendDiscoverNewTaxiNode(16); // Refuge Pointe, Arathi Highlands
            player->GetSession()->SendDiscoverNewTaxiNode(19); // Booty Bay, Stranglethorn Vale
            player->GetSession()->SendDiscoverNewTaxiNode(26); // Auberdine, Darkshore
            player->GetSession()->SendDiscoverNewTaxiNode(27); // Rut'theran Village, Teldrassil
            player->GetSession()->SendDiscoverNewTaxiNode(28); // Astranaar, Ashenvale
            player->GetSession()->SendDiscoverNewTaxiNode(31); // Thalanaar, Feralas
            player->GetSession()->SendDiscoverNewTaxiNode(32); // Theramore Isle, Dustwallow Marsh
            player->GetSession()->SendDiscoverNewTaxiNode(33); // Stonetalon Peak, Stonetalon Mountains
            player->GetSession()->SendDiscoverNewTaxiNode(37); // Nijel's Point, Desolace
            player->GetSession()->SendDiscoverNewTaxiNode(38); // Shadowprey Village, Desolace
            player->GetSession()->SendDiscoverNewTaxiNode(39); // Gadgetzan, Tanaris
            player->GetSession()->SendDiscoverNewTaxiNode(41); // Feathermoon Stronghold, Feralas
            player->GetSession()->SendDiscoverNewTaxiNode(43); // Aerie Peak, The Hinterlands
            player->GetSession()->SendDiscoverNewTaxiNode(45); // Nethergarde Keep, Blasted Lands
            player->GetSession()->SendDiscoverNewTaxiNode(49); // Moonglade
            player->GetSession()->SendDiscoverNewTaxiNode(52); // Everlook, Winterspring
            player->GetSession()->SendDiscoverNewTaxiNode(62); // Nighthaven, Moonglade
            player->GetSession()->SendDiscoverNewTaxiNode(64); // Talrendis Point, Azshara
            player->GetSession()->SendDiscoverNewTaxiNode(65); // Talonbranch Glade, Felwood
            player->GetSession()->SendDiscoverNewTaxiNode(66); // Chillwind Camp, Western Plaguelands
            player->GetSession()->SendDiscoverNewTaxiNode(67); // Light's Hope Chapel, Eastern Plaguelands
            player->GetSession()->SendDiscoverNewTaxiNode(71); // Morgan's Vigil, Burning Steppes
            player->GetSession()->SendDiscoverNewTaxiNode(73); // Cenarion Hold, Silithus
            player->GetSession()->SendDiscoverNewTaxiNode(74); // Thorium Point, Searing Gorge
            player->GetSession()->SendDiscoverNewTaxiNode(93); // Blood Watch, Bloodmyst Isle
            player->GetSession()->SendDiscoverNewTaxiNode(94); // The Exodar
            player->GetSession()->SendDiscoverNewTaxiNode(167); // Forest Song, Ashenvale
            player->GetSession()->SendDiscoverNewTaxiNode(195); // Rebel Camp, Stranglethorn Vale
        }
        else if (player->GetTeamId() == TEAM_HORDE)
        {
            player->GetSession()->SendDiscoverNewTaxiNode(10); // The Sepulcher, Silverpine Forest
            player->GetSession()->SendDiscoverNewTaxiNode(11); // Undercity
            player->GetSession()->SendDiscoverNewTaxiNode(13); // Tarren Mill, Hillsbrad Foothills
            player->GetSession()->SendDiscoverNewTaxiNode(17); // Hammerfall, Arathi Highlands
            player->GetSession()->SendDiscoverNewTaxiNode(18); // Booty Bay, Stranglethorn Vale
            player->GetSession()->SendDiscoverNewTaxiNode(20); // Grom'gol, Stranglethorn Vale
            player->GetSession()->SendDiscoverNewTaxiNode(21); // Kargath, Badlands
            player->GetSession()->SendDiscoverNewTaxiNode(22); // Thunder Bluff
            player->GetSession()->SendDiscoverNewTaxiNode(23); // Orgrimmar
            player->GetSession()->SendDiscoverNewTaxiNode(25); // The Crossroads, The Barrens
            player->GetSession()->SendDiscoverNewTaxiNode(29); // Sun Rock Retreat, Stonetalon Mountains
            player->GetSession()->SendDiscoverNewTaxiNode(30); // Freewind Post, Thousand Needles
            player->GetSession()->SendDiscoverNewTaxiNode(38); // Shadowprey Village, Desolace
            player->GetSession()->SendDiscoverNewTaxiNode(40); // Gadgetzan, Tanaris
            player->GetSession()->SendDiscoverNewTaxiNode(42); // Camp Mojache, Feralas
            player->GetSession()->SendDiscoverNewTaxiNode(44); // Valormok, Azshara
            player->GetSession()->SendDiscoverNewTaxiNode(48); // Bloodvenom Post, Felwood
            player->GetSession()->SendDiscoverNewTaxiNode(53); // Everlook, Winterspring
            player->GetSession()->SendDiscoverNewTaxiNode(55); // Brackenwall Village, Dustwallow Marsh
            player->GetSession()->SendDiscoverNewTaxiNode(56); // Stonard, Swamp of Sorrows
            player->GetSession()->SendDiscoverNewTaxiNode(58); // Zoram'gar Outpost, Ashenvale
            player->GetSession()->SendDiscoverNewTaxiNode(61); // Splintertree Post, Ashenvale
            player->GetSession()->SendDiscoverNewTaxiNode(63); // Nighthaven, Moonglade
            player->GetSession()->SendDiscoverNewTaxiNode(68); // Light's Hope Chapel, Eastern Plaguelands
            player->GetSession()->SendDiscoverNewTaxiNode(69); // Moonglade
            player->GetSession()->SendDiscoverNewTaxiNode(70); // Flame Crest, Burning Steppes
            player->GetSession()->SendDiscoverNewTaxiNode(72); // Cenarion Hold, Silithus
            player->GetSession()->SendDiscoverNewTaxiNode(75); // Thorium Point, Searing Gorge
            player->GetSession()->SendDiscoverNewTaxiNode(76); // Revantusk Village, The Hinterlands
            player->GetSession()->SendDiscoverNewTaxiNode(77); // Camp Taurajo, The Barrens
            player->GetSession()->SendDiscoverNewTaxiNode(82); // Silvermoon City
            player->GetSession()->SendDiscoverNewTaxiNode(83); // Tranquillien, Ghostlands
            player->GetSession()->SendDiscoverNewTaxiNode(384); // The Bulwark, Tirisfal Glades
        }

        if (kickstarterLevel >= 70)
        {
            player->GetSession()->SendDiscoverNewTaxiNode(122); // Area 52, Netherstorm
            player->GetSession()->SendDiscoverNewTaxiNode(128); // Shattrath City
            player->GetSession()->SendDiscoverNewTaxiNode(139); // The Stormspire, Netherstorm
            player->GetSession()->SendDiscoverNewTaxiNode(140); // Altar of Sha'tar, Shadowmoon Valley
            player->GetSession()->SendDiscoverNewTaxiNode(150); // Cosmowrench, Netherstorm
            player->GetSession()->SendDiscoverNewTaxiNode(159); // Sanctum of the Stars, Shadowmoon Valley
            player->GetSession()->SendDiscoverNewTaxiNode(160); // Evergrove, Blade's Edge Mountains
            player->GetSession()->SendDiscoverNewTaxiNode(213); // Sun's Reach Harbor, Isle of Quel'Danas

            if (player->GetTeamId() == TEAM_ALLIANCE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(100); // Honor Hold, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(101); // Temple of Telhamat, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(117); // Telredor, Zangarmarsh
                player->GetSession()->SendDiscoverNewTaxiNode(119); // Telaar, Nagrand
                player->GetSession()->SendDiscoverNewTaxiNode(124); // Wildhammer Stronghold, Shadowmoon Valley
                player->GetSession()->SendDiscoverNewTaxiNode(125); // Sylvanaar, Blade's Edge Mountains
                player->GetSession()->SendDiscoverNewTaxiNode(129); // The Dark Portal, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(149); // Shatter Point, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(156); // Toshley's Station, Blade's Edge Mountains
                player->GetSession()->SendDiscoverNewTaxiNode(164); // Orebor Harborage, Zangarmarsh
            }
            else if (player->GetTeamId() == TEAM_HORDE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(99); // Thrallmar, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(102); // Falcon Watch, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(118); // Zabra'jin, Zangarmarsh
                player->GetSession()->SendDiscoverNewTaxiNode(120); // Garadar, Nagrand
                player->GetSession()->SendDiscoverNewTaxiNode(123); // Shadowmoon Village, Shadowmoon Valley
                player->GetSession()->SendDiscoverNewTaxiNode(126); // Thunderlord Stronghold, Blade's Edge Mountains
                player->GetSession()->SendDiscoverNewTaxiNode(127); // Stonebreaker Hold, Terokkar Forest
                player->GetSession()->SendDiscoverNewTaxiNode(130); // The Dark Portal, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(141); // Spinebreaker Ridge, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(142); // Reaver's Fall, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(151); // Swamprat Post, Zangarmarsh
                player->GetSession()->SendDiscoverNewTaxiNode(163); // Mok'Nathal Village, Blade's Edge Mountains
            }
        }
        
        if (kickstarterLevel == 80)
        {
            player->GetSession()->SendDiscoverNewTaxiNode(226); // Transitus Shield, Coldarra
            player->GetSession()->SendDiscoverNewTaxiNode(252); // Wyrmrest Temple, Dragonblight
            player->GetSession()->SendDiscoverNewTaxiNode(289); // Amber Ledge, Borean Tundra
            player->GetSession()->SendDiscoverNewTaxiNode(294); // Moa'ki, Dragonblight
            player->GetSession()->SendDiscoverNewTaxiNode(295); // Kamagua, Howling Fjord
            player->GetSession()->SendDiscoverNewTaxiNode(296); // Unu'pe, Borean Tundra
            player->GetSession()->SendDiscoverNewTaxiNode(304); // The Argent Stand, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(305); // Ebon Watch, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(306); // Light's Breach, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(307); // Zim'Torga, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(308); // River's Heart, Sholazar Basin
            player->GetSession()->SendDiscoverNewTaxiNode(309); // Nesingwary Base Camp, Sholazar Basin
            player->GetSession()->SendDiscoverNewTaxiNode(310); // Dalaran
            player->GetSession()->SendDiscoverNewTaxiNode(320); // K3, The Storm Peaks
            player->GetSession()->SendDiscoverNewTaxiNode(321); // The Frost Hold, The Storm Peaks
            player->GetSession()->SendDiscoverNewTaxiNode(325); // Death's Rise, Icecrown
            player->GetSession()->SendDiscoverNewTaxiNode(326); // Ulduar, The Storm Peaks
            player->GetSession()->SendDiscoverNewTaxiNode(327); // Bouldercrag's Refuge, The Storm Peaks
            player->GetSession()->SendDiscoverNewTaxiNode(331); // Dubra'Jin, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(334); // The Argent Vanguard, Icecrown
            player->GetSession()->SendDiscoverNewTaxiNode(340); // Argent Tournament Grounds, Icecrown

            if (player->GetTeamId() == TEAM_ALLIANCE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(183); // Valgarde Port, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(184); // Fort Wildervar, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(185); // Westguard Keep, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(244); // Wintergarde Keep, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(245); // Valiance Keep, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(246); // Fizzcrank Airstrip, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(247); // Stars' Rest, Dragonblight
                player->GetSession()->SendDiscoverNewTaxiNode(251); // Fordragon Hold, Dragonblight
                player->GetSession()->SendDiscoverNewTaxiNode(253); // Amberpine Lodge, Grizzly Hills
                player->GetSession()->SendDiscoverNewTaxiNode(255); // Westfall Brigade, Grizzly Hills
                player->GetSession()->SendDiscoverNewTaxiNode(321); // Frosthold, The Storm Peaks
                player->GetSession()->SendDiscoverNewTaxiNode(336); // Windrunner's Overlook, Crystalsong Forest
            }
            else if (player->GetTeamId() == TEAM_HORDE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(190); // New Agamand, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(191); // Vengeance Landing, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(192); // Camp Winterhoof, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(248); // Apothecary Camp, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(249); // Camp Oneqwah, Grizzly Hills
                player->GetSession()->SendDiscoverNewTaxiNode(254); // Venomspite, Dragonblight
                player->GetSession()->SendDiscoverNewTaxiNode(256); // Agmar's Hammer, Dragonblight
                player->GetSession()->SendDiscoverNewTaxiNode(257); // Warsong Hold, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(258); // Taunka'le Village, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(259); // Bor'gorok Outpost, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(260); // Kor'koron Vanguard, Dragonbligh
                player->GetSession()->SendDiscoverNewTaxiNode(323); // Grom'arsh Crash-Site, The Storm Peaks
                player->GetSession()->SendDiscoverNewTaxiNode(324); // Camp Tunka'lo, The Storm Peaks
                player->GetSession()->SendDiscoverNewTaxiNode(337); // Sunreaver's Command, Crystalsong Forest
            }
        }
    }
    
    void AddMoney(Player* player)
    {
        uint32 money = kickstarterMoneyAmount[0];
        if (kickstarterLevel == 70)
            money = kickstarterMoneyAmount[1];
        else if (kickstarterLevel == 80)
            money = kickstarterMoneyAmount[2];

        player->ModifyMoney(money);
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

        if (kickstarterLevel != 60 && kickstarterLevel != 70 && kickstarterLevel != 80)
            kickstarterLevel = 60;

        kickstarterMoney = sConfigMgr->GetOption<bool>("Kickstarter.StartWithMoney", 1);
        kickstarterMoneyAmount[0] = sConfigMgr->GetOption<uint32>("Kickstarter.Level.60.Money", 100000);
        kickstarterMoneyAmount[1] = sConfigMgr->GetOption<uint32>("Kickstarter.Level.70.Money", 1000000);
        kickstarterMoneyAmount[2] = sConfigMgr->GetOption<uint32>("Kickstarter.Level.80.Money", 2500000);
    }
};

void AddSC_mod_kickstarter()
{
    new Kickstarter();
    new KickstarterConfiguration();
}
