/* helpcommands */
DELETE FROM command WHERE `name`='ex';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('ex', 195, ''); 

DELETE FROM command WHERE `name`='ex skipcata';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('ex skipcata', 195, ''); 

DELETE FROM command WHERE `name`='ex skipmop';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('ex skipmop', 195, ''); 

DELETE FROM command WHERE `name`='ex skipwod';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('ex skipwod', 195, ''); 

DELETE FROM command WHERE `name`='ex skiplegion';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('ex skiplegion', 195, ''); 

DELETE FROM command WHERE `name`='ex startwod';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('ex startwod', 195, ''); 


/* Report Commands*/


DELETE FROM command WHERE `name`='report';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('report', 195, '');   

DELETE FROM command WHERE `name`='report quest';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('report quest', 195, '');   

DELETE FROM command WHERE `name`='report deactivate';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('report deactivate', 193, '');  

DELETE FROM command WHERE `name`='report activate';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('report activate', 193, '');  


/* Custom Xp Rate */
DELETE FROM command WHERE `name`='xprate';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('xprate', 195, '');  