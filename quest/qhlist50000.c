// qhlist50000.c

inherit SKILL;
#include <ansi.h>;
mapping *quest = ({
 
(["quest_city":"���ո���", "quest": "���",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "�Ѹ�",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "��",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "�ϲ�",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "ũ��",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "�Է�",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "����",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "����ͯ��",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "������Ů",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "ũ�Ҹ�Ů",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "Ѿ��",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ո���", "quest": "����",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"���˸���", "quest": "�ϴ���",  "quest_type": "ɱ",  "time":  200,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"���ݸ���", "quest": "ʷ��ɽ",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "��ݺݺ",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"��������", "quest": "��������",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "ׯ����",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "���峬",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "�ذ���",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "���ƹ�",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "�͵���",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "���׳����",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "ҩ�̻��",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "������",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "����",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "Ϸ��",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"��������", "quest": "�����",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"������", "quest": "ʿ��",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "̨���̷�",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "��ɣŮ",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "������",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "�帾",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "��ɴŮ",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "̨�ĸ�Ů",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "��Ů",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "����Ů��",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "�Ϲ�����",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "��Ů",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "�ܼ�",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "̨�Ĺ���",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "����Ů",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "������",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "��������",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "������",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "ʢƤ�޿���",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "����С��",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "����",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "̨������",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "����Ů",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "������",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "ũ��",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "̨��ũ��",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "ũ��",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "��������",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "Ƥ����",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "����",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "����",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "��Ů",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "ʯ��",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "̨���̷�",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "������ʿ",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "������ʿ",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "������ʿ",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "�����̷�",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "С����",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "Ѧ�ϰ�",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "����Ů",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "�ο�",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"������", "quest": "���",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"��ɽ����", "quest": "�ų���",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��ɽ����", "quest": "�ſ�",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��ɽ����", "quest": "����ɩ",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��ɽ����", "quest": "��С��",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"���ݸ���", "quest": "�׶�",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "����",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "����ͷ",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "ʷ��ͷ",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "������",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "֣��ͷ",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"����ׯ����", "quest": "��ͯ",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"����ׯ����", "quest": "С��",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"����ׯ����", "quest": "С��",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"��Ĺ����", "quest": "������",  "quest_type": "ɱ",  "time":  400,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"���ݸ���", "quest": "�컨����",  "quest_type": "ɱ",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "��Ӫ����",  "quest_type": "ɱ",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "������",  "quest_type": "ɱ",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "ׯ�ʳ�",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"��ɽ����", "quest": "�Ƹ�",  "quest_type": "ɱ",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"��������", "quest": "��ݼ",  "quest_type": "ɱ",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "����",  "quest_type": "ɱ",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "������",  "quest_type": "ɱ",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��������", "quest": "�販ʿ",  "quest_type": "ɱ",  "time":  300,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"�ƺӸ���", "quest": "�����",  "quest_type": "ɱ",  "time":  500,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"��ɽ����", "quest": "С��",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"��ɽ����", "quest": "�仨",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"�����¸���", "quest": "ɨ��ɮ",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"�����¸���", "quest": "Сɳ��",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"�����¸���", "quest": "����ɮ",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"�����¸���", "quest": "����ɮ��",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"�����¸���", "quest": "ɨ��ɮ",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"���ݸ���", "quest": "С��",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "����Ů��",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "������Ů",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���ݸ���", "quest": "�η�����",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"���總��", "quest": "����ľ��",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���總��", "quest": "������",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���總��", "quest": "������",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"���總��", "quest": "��˹����",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"ѩɽ�¸���", "quest": "����",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"ѩɽ�¸���", "quest": "׿��",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"�����븽��", "quest": "����",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"����ɽ����", "quest": "����Сʦ��",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"����ɽ����", "quest": "�ķ�Сʦ̫",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"����ɽ����", "quest": "����Сʦ̫",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"����ɽ����", "quest": "����Сʦ̫",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"����ɽ����", "quest": "����Сʦ̫",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"ؤ�︽��", "quest": "������",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"ؤ�︽��", "quest": "�����",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"ؤ�︽��", "quest": "�ͷ",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"ؤ�︽��", "quest": "Ī����",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"ؤ�︽��", "quest": "�����",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"ؤ�︽��", "quest": "�Թ���",  "quest_type": "ɱ",  "time":  350,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 

(["quest_city":"�䵱ɽ����", "quest": "��ͯ",  "quest_type": "ɱ",  "time":  450,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"�䵱ɽ����", "quest": "����",  "quest_type": "ɱ",  "time":  450,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"�䵱ɽ����", "quest": "���",  "quest_type": "ɱ",  "time":  450,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
(["quest_city":"�䵱ɽ����", "quest": "��԰����",  "quest_type": "ɱ",  "time":  450,  "exp_bonus":  68,  "pot_bonus":  32,  "score" : 20 ]), 
});

mapping query_quest()
{
    return quest[random(sizeof(quest))];
}
