// qslist50000.c

inherit SKILL;
#include <ansi.h>;
mapping *quest = ({
([ "quest":  "�ʷ�", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ո���" ]),
([ "quest":  "�ܼ�", "quest_type":"ɱ", "time":   280, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ո���" ]),
([ "quest":  "���ͷ", "quest_type":"ɱ", "time":   480, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ո���" ]),
([ "quest":  "��������", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ո���" ]),
([ "quest":  "Сɽ��", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ո���" ]),
([ "quest":  "ɽ��", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ո���" ]),
([ "quest":  "������", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ո���" ]),
([ "quest":  "�ܼ�", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ո���" ]),

([ "quest":  "��Ա��", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ݸ���" ]),
([ "quest":  "��å", "quest_type":"ɱ", "time":   280, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ݸ���" ]),
([ "quest":  "��åͷ", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ݸ���" ]),
([ "quest":  "���ϰ�", "quest_type":"ɱ", "time":   580, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ݸ���" ]),
([ "quest":  "С����", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ݸ���" ]),

([ "quest":  "С��å", "quest_type":"ɱ", "time":   280, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"��������" ]),
([ "quest":  "��Ʀ", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"��������" ]),

([ "quest":  "��ƽͨ�ھ֡���ͷ", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"������" ]),
([ "quest":  "��ū", "quest_type":"ɱ", "time":   480, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"������" ]),
([ "quest":  "����", "quest_type":"ɱ", "time":   480, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"������" ]),
([ "quest":  "�κ�ҩ", "quest_type":"ɱ", "time":   680, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"������" ]),
([ "quest":  "��˾", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"������" ]),

([ "quest":  "��ũ�����", "quest_type":"ɱ", "time":   300, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"����ɽ����" ]),
([ "quest":  "����������", "quest_type":"ɱ", "time":   300, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"����ɽ����" ]),

([ "quest":  "�����", "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"����ׯ����" ]),
([ "quest":  "����", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"����ׯ����" ]),

([ "quest":  "����", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���̸���" ]),
([ "quest":  "����", "quest_type":"ɱ", "time":   500, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���̸���" ]),

([ "quest":  "������", "quest_type":"ɱ", "time":   500, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�ƺӾ�������" ]),
([ "quest":  "������", "quest_type":"ɱ", "time":   500, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�ƺӾ�������" ]),
([ "quest":  "����", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�ƺӾ�������" ]),
([ "quest":  "������", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�ƺӾ�������" ]),
([ "quest":  "���ı�", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�ƺӾ�������" ]),

([ "quest":  "������̽�ͽ", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"��ľ�¸���" ]),

([ "quest":  "������", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"��ɽ�帽��" ]),

([ "quest":  "Уξ", "quest_type":"ɱ", "time":   500, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ݸ���" ]),
([ "quest":  "һƷ����ʿ", "quest_type":"ɱ", "time":   600, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���ݸ���" ]),
	
([ "quest":  "����Ů����", "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"����������" ]),
	
([ "quest":  "��ϲ��", "quest_type":"ɱ", "time":   500, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"��ٹȸ���" ]),

([ "quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�䵱ɽ����" ]),
([ "quest":  "����ͷ", "quest_type":"ɱ", "time":   600, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�䵱ɽ����" ]),
([ "quest":  "С����", "quest_type":"ɱ", "time":   300, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�䵱ɽ����" ]),

([ "quest":  "����", "quest_type":"ɱ", "time":   300, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"��ɽ����" ]),

([ "quest":  "����������", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���޺�����" ]),
([ "quest":  "�ɻ���", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���޺�����" ]),
([ "quest":  "�����ɹ���", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���޺�����" ]),
([ "quest":  "�����ɺ���", "quest_type":"ɱ", "time":   380, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"���޺�����" ]),

([ "quest":  "����ɮ��", "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"ѩɽ�¸���" ]),
([ "quest":  "С����", "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"ѩɽ�¸���" ]),

  (["quest":  "��ɣ",  "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�߲��Ǹ���" ]),
 (["quest":  "������",  "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�߲��Ǹ���" ]),
 (["quest":  "�䳤",  "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"�߲��Ǹ���" ]),

 (["quest":  "�Ű���",  "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"����򸽽�" ]),
 (["quest":  "����",  "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"����򸽽�" ]),
 (["quest":  "�蹤",  "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"����򸽽�" ]),

 (["quest":  "κ�޼�",  "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"ѩͤ�򸽽�" ]),
 (["quest":  "������",  "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"ѩͤ�򸽽�" ]),
 (["quest":  "����һ��",  "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"ѩͤ�򸽽�" ]),

(["quest":  "���ɩ", "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"ʢ������" ]),    	
(["quest":  "���ĳ�", "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"ʢ������" ]),    	
(["quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":50, "pot_bonus":30, "score" : 20,"quest_city":"ʢ������" ]),    	
});

mapping query_quest()
{
   return quest[random(sizeof(quest))];
}
