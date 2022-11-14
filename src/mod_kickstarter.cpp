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
        player->GetSession()->SendDiscoverNewTaxiNode(79);
        player->GetSession()->SendDiscoverNewTaxiNode(80);
        player->GetSession()->SendDiscoverNewTaxiNode(166);
        player->GetSession()->SendDiscoverNewTaxiNode(179);
        player->GetSession()->SendDiscoverNewTaxiNode(205);
        player->GetSession()->SendDiscoverNewTaxiNode(383);

        if (player->GetTeamId() == TEAM_ALLIANCE)
        {
            player->GetSession()->SendDiscoverNewTaxiNode(2);
            player->GetSession()->SendDiscoverNewTaxiNode(4);
            player->GetSession()->SendDiscoverNewTaxiNode(5);
            player->GetSession()->SendDiscoverNewTaxiNode(6);
            player->GetSession()->SendDiscoverNewTaxiNode(7);
            player->GetSession()->SendDiscoverNewTaxiNode(8);
            player->GetSession()->SendDiscoverNewTaxiNode(12);
            player->GetSession()->SendDiscoverNewTaxiNode(14);
            player->GetSession()->SendDiscoverNewTaxiNode(15);
            player->GetSession()->SendDiscoverNewTaxiNode(16);
            player->GetSession()->SendDiscoverNewTaxiNode(19);
            player->GetSession()->SendDiscoverNewTaxiNode(26);
            player->GetSession()->SendDiscoverNewTaxiNode(27);
            player->GetSession()->SendDiscoverNewTaxiNode(28);
            player->GetSession()->SendDiscoverNewTaxiNode(31);
            player->GetSession()->SendDiscoverNewTaxiNode(32);
            player->GetSession()->SendDiscoverNewTaxiNode(33);
            player->GetSession()->SendDiscoverNewTaxiNode(37);
            player->GetSession()->SendDiscoverNewTaxiNode(38);
            player->GetSession()->SendDiscoverNewTaxiNode(41);
            player->GetSession()->SendDiscoverNewTaxiNode(43);
            player->GetSession()->SendDiscoverNewTaxiNode(45);
            player->GetSession()->SendDiscoverNewTaxiNode(49);
            player->GetSession()->SendDiscoverNewTaxiNode(52);
            player->GetSession()->SendDiscoverNewTaxiNode(62);
            player->GetSession()->SendDiscoverNewTaxiNode(64);
            player->GetSession()->SendDiscoverNewTaxiNode(65);
            player->GetSession()->SendDiscoverNewTaxiNode(66);
            player->GetSession()->SendDiscoverNewTaxiNode(67);
            player->GetSession()->SendDiscoverNewTaxiNode(71);
            player->GetSession()->SendDiscoverNewTaxiNode(73);
            player->GetSession()->SendDiscoverNewTaxiNode(74);
            player->GetSession()->SendDiscoverNewTaxiNode(93);
            player->GetSession()->SendDiscoverNewTaxiNode(94);
            player->GetSession()->SendDiscoverNewTaxiNode(167);
            player->GetSession()->SendDiscoverNewTaxiNode(195);
        }
        else if (player->GetTeamId() == TEAM_HORDE)
        {
            player->GetSession()->SendDiscoverNewTaxiNode(10);
            player->GetSession()->SendDiscoverNewTaxiNode(11);
            player->GetSession()->SendDiscoverNewTaxiNode(13);
            player->GetSession()->SendDiscoverNewTaxiNode(17);
            player->GetSession()->SendDiscoverNewTaxiNode(18);
            player->GetSession()->SendDiscoverNewTaxiNode(20);
            player->GetSession()->SendDiscoverNewTaxiNode(21);
            player->GetSession()->SendDiscoverNewTaxiNode(22);
            player->GetSession()->SendDiscoverNewTaxiNode(23);
            player->GetSession()->SendDiscoverNewTaxiNode(25);
            player->GetSession()->SendDiscoverNewTaxiNode(29);
            player->GetSession()->SendDiscoverNewTaxiNode(30);
            player->GetSession()->SendDiscoverNewTaxiNode(38);
            player->GetSession()->SendDiscoverNewTaxiNode(40);
            player->GetSession()->SendDiscoverNewTaxiNode(42);
            player->GetSession()->SendDiscoverNewTaxiNode(44);
            player->GetSession()->SendDiscoverNewTaxiNode(48);
            player->GetSession()->SendDiscoverNewTaxiNode(53);
            player->GetSession()->SendDiscoverNewTaxiNode(55);
            player->GetSession()->SendDiscoverNewTaxiNode(56);
            player->GetSession()->SendDiscoverNewTaxiNode(58);
            player->GetSession()->SendDiscoverNewTaxiNode(61);
            player->GetSession()->SendDiscoverNewTaxiNode(63);
            player->GetSession()->SendDiscoverNewTaxiNode(68);
            player->GetSession()->SendDiscoverNewTaxiNode(69);
            player->GetSession()->SendDiscoverNewTaxiNode(70);
            player->GetSession()->SendDiscoverNewTaxiNode(72);
            player->GetSession()->SendDiscoverNewTaxiNode(75);
            player->GetSession()->SendDiscoverNewTaxiNode(76);
            player->GetSession()->SendDiscoverNewTaxiNode(77);
            player->GetSession()->SendDiscoverNewTaxiNode(82);
            player->GetSession()->SendDiscoverNewTaxiNode(83);
            player->GetSession()->SendDiscoverNewTaxiNode(384);
        }

        if (kickstarterLevel >= 70)
        {
            player->GetSession()->SendDiscoverNewTaxiNode(122);
            player->GetSession()->SendDiscoverNewTaxiNode(128);
            player->GetSession()->SendDiscoverNewTaxiNode(139);
            player->GetSession()->SendDiscoverNewTaxiNode(140);
            player->GetSession()->SendDiscoverNewTaxiNode(150);
            player->GetSession()->SendDiscoverNewTaxiNode(159);
            player->GetSession()->SendDiscoverNewTaxiNode(160);
            player->GetSession()->SendDiscoverNewTaxiNode(213);

            if (player->GetTeamId() == TEAM_ALLIANCE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(100);
                player->GetSession()->SendDiscoverNewTaxiNode(101);
                player->GetSession()->SendDiscoverNewTaxiNode(117);
                player->GetSession()->SendDiscoverNewTaxiNode(119);
                player->GetSession()->SendDiscoverNewTaxiNode(122);
                player->GetSession()->SendDiscoverNewTaxiNode(124);
                player->GetSession()->SendDiscoverNewTaxiNode(125);
                player->GetSession()->SendDiscoverNewTaxiNode(129);
                player->GetSession()->SendDiscoverNewTaxiNode(149);
                player->GetSession()->SendDiscoverNewTaxiNode(156);
                player->GetSession()->SendDiscoverNewTaxiNode(164);
            }
            else if (player->GetTeamId() == TEAM_HORDE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(99);
                player->GetSession()->SendDiscoverNewTaxiNode(102);
                player->GetSession()->SendDiscoverNewTaxiNode(118);
                player->GetSession()->SendDiscoverNewTaxiNode(120);
                player->GetSession()->SendDiscoverNewTaxiNode(123);
                player->GetSession()->SendDiscoverNewTaxiNode(126);
                player->GetSession()->SendDiscoverNewTaxiNode(127);
                player->GetSession()->SendDiscoverNewTaxiNode(130);
                player->GetSession()->SendDiscoverNewTaxiNode(141);
                player->GetSession()->SendDiscoverNewTaxiNode(142);
                player->GetSession()->SendDiscoverNewTaxiNode(151);
                player->GetSession()->SendDiscoverNewTaxiNode(163);
            }
        }
        
        if (kickstarterLevel == 80)
        {
            player->GetSession()->SendDiscoverNewTaxiNode(226);
            player->GetSession()->SendDiscoverNewTaxiNode(252);
            player->GetSession()->SendDiscoverNewTaxiNode(289);
            player->GetSession()->SendDiscoverNewTaxiNode(294);
            player->GetSession()->SendDiscoverNewTaxiNode(295);
            player->GetSession()->SendDiscoverNewTaxiNode(296);
            player->GetSession()->SendDiscoverNewTaxiNode(304);
            player->GetSession()->SendDiscoverNewTaxiNode(305);
            player->GetSession()->SendDiscoverNewTaxiNode(306);
            player->GetSession()->SendDiscoverNewTaxiNode(307);
            player->GetSession()->SendDiscoverNewTaxiNode(308);
            player->GetSession()->SendDiscoverNewTaxiNode(309);
            player->GetSession()->SendDiscoverNewTaxiNode(310);
            player->GetSession()->SendDiscoverNewTaxiNode(320);
            player->GetSession()->SendDiscoverNewTaxiNode(325);
            player->GetSession()->SendDiscoverNewTaxiNode(326);
            player->GetSession()->SendDiscoverNewTaxiNode(327);
            player->GetSession()->SendDiscoverNewTaxiNode(331);
            player->GetSession()->SendDiscoverNewTaxiNode(334);
            player->GetSession()->SendDiscoverNewTaxiNode(340);

            if (player->GetTeamId() == TEAM_ALLIANCE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(183);
                player->GetSession()->SendDiscoverNewTaxiNode(184);
                player->GetSession()->SendDiscoverNewTaxiNode(185);
                player->GetSession()->SendDiscoverNewTaxiNode(244);
                player->GetSession()->SendDiscoverNewTaxiNode(245);
                player->GetSession()->SendDiscoverNewTaxiNode(246);
                player->GetSession()->SendDiscoverNewTaxiNode(247);
                player->GetSession()->SendDiscoverNewTaxiNode(251);
                player->GetSession()->SendDiscoverNewTaxiNode(253);
                player->GetSession()->SendDiscoverNewTaxiNode(255);
                player->GetSession()->SendDiscoverNewTaxiNode(321);
                player->GetSession()->SendDiscoverNewTaxiNode(336);
            }
            else if (player->GetTeamId() == TEAM_HORDE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(190);
                player->GetSession()->SendDiscoverNewTaxiNode(191);
                player->GetSession()->SendDiscoverNewTaxiNode(192);
                player->GetSession()->SendDiscoverNewTaxiNode(248);
                player->GetSession()->SendDiscoverNewTaxiNode(249);
                player->GetSession()->SendDiscoverNewTaxiNode(254);
                player->GetSession()->SendDiscoverNewTaxiNode(256);
                player->GetSession()->SendDiscoverNewTaxiNode(257);
                player->GetSession()->SendDiscoverNewTaxiNode(258);
                player->GetSession()->SendDiscoverNewTaxiNode(259);
                player->GetSession()->SendDiscoverNewTaxiNode(260);
                player->GetSession()->SendDiscoverNewTaxiNode(323);
                player->GetSession()->SendDiscoverNewTaxiNode(324);
                player->GetSession()->SendDiscoverNewTaxiNode(337);
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
