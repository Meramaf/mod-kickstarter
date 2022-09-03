SET
@Entry := 6000000,
@Model := 21697,
@Name  := "Ambert Mendenhall",
@Title := "Kickstarter",
@Icon  := "Speak",
@GossipMenu := 0,
@MinLevel := 60,
@MaxLevel := 60,
@Faction  := 35,
@NPCFlag  := 1,
@Scale    := 1.0,
@Rank     := 0,
@Type     := 7,
@TypeFlags := 0,
@FlagsExtra := 16777218,
@Script     := "npc_kickstarter";

DELETE FROM `creature_template` WHERE `entry`=@Entry;
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `unit_class`, `unit_flags`, `type`, `type_flags`, `RegenHealth`, `flags_extra`, `ScriptName`) VALUES
(@Entry, @Model, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, @Faction, @NPCFlag, 1, 1, @Scale, @Rank, 1, 2, @Type, @TypeFlags, 1, @FlagsExtra, @Script);

DELETE FROM `creature` WHERE `id1`=@Entry;
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 0, -8877.62, 633.311, 96.0921, 6.06048);
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 1, 1640.45, -4311.12, 1.44533, 5.24743);

