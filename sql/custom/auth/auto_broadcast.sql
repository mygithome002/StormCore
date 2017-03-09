DELETE FROM `autobroadcast` where realmid = 3 AND `id` BETWEEN 100 AND 150;

INSERT INTO `autobroadcast` (`realmid`, `id`, `weight`, `text`) VALUES ('3', '100', '2', 'For all workaround type .ex. This will display all workaround commands!');
INSERT INTO `autobroadcast` (`realmid`, `id`, `weight`, `text`) VALUES ('3', '101', '2', 'To report a buggy quest just type .report quest [Shift-Left Click on Quest], Your errormessage ');
INSERT INTO `autobroadcast` (`realmid`, `id`, `weight`, `text`) VALUES ('3', '102', '2', 'To change your XP Rate just type .xprate. ');