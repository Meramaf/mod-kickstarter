CREATE TABLE IF NOT EXISTS `kickstarter_tokens` (
	`account_id` INT(10) UNSIGNED NOT NULL,
	`tokens` INT(10) UNSIGNED NOT NULL,
	PRIMARY KEY (`account_id`) USING BTREE
)
COLLATE='utf8mb4_general_ci'
ENGINE=InnoDB
;
