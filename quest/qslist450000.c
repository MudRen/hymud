// qslist450000.c

inherit SKILL;
#include <ansi.h>;
mapping *quest = ({
 ([ "quest":  "�ʷ�", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ո���" ]),
 ([ "quest":  "�ܼ�", "quest_type":"ɱ", "time":   280, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ո���" ]),
 ([ "quest":  "���ͷ", "quest_type":"ɱ", "time":   480, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ո���" ]),
 ([ "quest":  "��������", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ո���" ]),
 ([ "quest":  "Сɽ��", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ո���" ]),
 ([ "quest":  "ɽ��", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ո���" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ո���" ]),
 ([ "quest":  "�ܼ�", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ո���" ]),
 ([ "quest":  "����",  "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ո���" ]),
  	
 ([ "quest":  "��Ա��", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "��å", "quest_type":"ɱ", "time":   280, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "��åͷ", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "���ϰ�", "quest_type":"ɱ", "time":   580, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "С����", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   200, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "�⹭Ӱ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "ŷ����", "quest_type":"ɱ", "time":   200, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "��ͷ��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 
 ([ "quest":  "С��å", "quest_type":"ɱ", "time":   280, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "��Ʀ", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"��������"]),
 ([ "quest":  "��ͷ��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "���Ʋֹ�ʦ", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),

 ([ "quest":  "��ƽͨ�ھ֡���ͷ", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "��ū", "quest_type":"ɱ", "time":   480, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   480, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "�κ�ҩ", "quest_type":"ɱ", "time":   680, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "��˾", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "�����ϼ�˾", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "��ͷ��", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "�峤", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "����η", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
 ([ "quest":  "�ϼ�˾", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),

 ([ "quest":  "��ũ�����", "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����ɽ����" ]),
 ([ "quest":  "����������", "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����ɽ����" ]),
 
 ([ "quest":  "�����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����ׯ����" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����ׯ����" ]),
 
 ([ "quest":  "����", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "��ɽ��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),

 ([ "quest":  "������̽�ͽ", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ľ�¸���" ]),
 
 ([ "quest":  "������", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "Ǯ�ཡ", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "�����", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "���ı�", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "��ͨ��", "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   200, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),
 ([ "quest":  "ɳͨ��", "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ƺӾ�������" ]),

 ([ "quest":  "������", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ�帽��" ]),
 
 ([ "quest":  "Уξ", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "һƷ����ʿ", "quest_type":"ɱ", "time":   600, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "ʯ����ʿ", "quest_type":"ɱ", "time":   600, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"���ݸ���"]),
 ([ "quest":  "Уξ", "quest_type":"ɱ", "time":   600, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "�ʹ���ʿ", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "�Ϻ�����", "quest_type":"ɱ", "time":   600, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "���к�", "quest_type":"ɱ", "time":   600, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 	
 ([ "quest":  "����Ů����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����������" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����������" ]),
 ([ "quest":  "½����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����������" ]),
 ([ "quest":  "�޸�����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����������" ]),
 ([ "quest":  "��ѩͤ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����������" ]),
 ([ "quest":  "���", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����������" ]),
 ([ "quest":  "�ŵ���", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����������" ]),

 ([ "quest":  "��ϲ��", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ٹȸ���" ]),
 
 ([ "quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�䵱ɽ����" ]),
 ([ "quest":  "����ͷ", "quest_type":"ɱ", "time":   600, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�䵱ɽ����" ]),
 ([ "quest":  "С����", "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�䵱ɽ����" ]),
 
 ([ "quest":  "����", "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 
 ([ "quest":  "����������", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���޺�����" ]),
 ([ "quest":  "�ɻ���", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���޺�����" ]),
 ([ "quest":  "�����ɹ���", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���޺�����" ]),
 ([ "quest":  "�����ɺ���", "quest_type":"ɱ", "time":   380, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���޺�����" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���޺�����" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���޺�����" ]),
 ([ "quest":  "ʨ����", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���޺�����" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���޺�����" ]),

 ([ "quest":  "����ɮ��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ѩɽ�¸���" ]),
 ([ "quest":  "С����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ѩɽ�¸���" ]),
 
 ([ "quest":  "�͵�ŵ", "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"��ɽ����"]),
 ([ "quest":  "��ƽ֮", "quest_type":"ɱ", "time":   200, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 	
 ([ "quest":  "���״�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"���⸽��"]),
 ([ "quest":  "���׶���", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"���⸽��"]),
 ([ "quest":  "��������", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���⸽��" ]),
 ([ "quest":  "�����Ļ�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���⸽��" ]),
 ([ "quest":  "�ֻ�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"���⸽��"]),
 
 ([ "quest":  "���պ���", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ྩ����" ]),
 ([ "quest":  "���տ�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�ྩ����" ]),
 	
 ([ "quest":  "��Բ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"���ݸ���"]),
 ([ "quest":  "�����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"���ݸ���"]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),
 ([ "quest":  "�̳���", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ݸ���" ]),

 ([ "quest":  "������", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"���ɽ����"]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ɽ����" ]),
 ([ "quest":  "����Ӣ", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"���ɽ����"]),
 ([ "quest":  "����ͨ", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ɽ����" ]),
 ([ "quest":  "���˴�", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ɽ����" ]),
 ([ "quest":  "���˽�", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ɽ����" ]),
 ([ "quest":  "���˿�", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ɽ����" ]),
 ([ "quest":  "���˺�", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ɽ����" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���ɽ����" ]),
 
 ([ "quest":  "��ë��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"̨�帽��"]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"̨�帽��" ]),
 
 ([ "quest":  "��Ī��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���˸���" ]),

 ([ "quest":  "��Ѷ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"Ȫ�ݸ���" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"Ȫ�ݸ���" ]),
 	
 ([ "quest":  "�߿���", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"��ɽ����"]),
 ([ "quest":  "½��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 ([ "quest":  "ɳ�콭", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 ([ "quest":  "ʷ�Ǵ�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 ([ "quest":  "��Ӣ��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 ([ "quest":  "���ƽ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20 ,"quest_city":"��ɽ����"]),
 ([ "quest":  "�ֺ�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 
 ([ "quest":  "����ͤ", "quest_type":"ɱ", "time":   200, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ľ�¸���" ]),
 
 ([ "quest":  "³����", "quest_type":"ɱ", "time":   300, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 
 ([ "quest":  "��������", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���չ�����" ]),
 ([ "quest":  "���ϴ�", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���չ�����" ]),
 
 ([ "quest":  "�׹���", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����ɽ������" ]),
 	
 ([ "quest":  "��ɽ��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "��ǫ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "����ԫ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "��Ө��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "˵����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "�ذ�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "��Ȼ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "��ԫ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "���޸�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "����»", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "������", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "��Ұ��", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "�ܵ�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 ([ "quest":  "ׯ�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"���̸���" ]),
 
 ([ "quest":  "����", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 ([ "quest":  "�˰���", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 ([ "quest":  "����", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 ([ "quest":  "�ѱ�", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 	
 ([ "quest":  "���о�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ؤ�︽��" ]),
 ([ "quest":  "ȫ����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ؤ�︽��" ]),
 	
 ([ "quest":  "�����", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"Ѫ���Ÿ���" ]),
 
 ([ "quest":  "����", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"Ѫ���Ÿ���" ]),
 ([ "quest":  "ʤ��", "quest_type":"ɱ", "time":   500, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"Ѫ���Ÿ���" ]),

 (["quest":  "��Ӣ",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 (["quest":  "����",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 (["quest":  "��Ө",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 (["quest":  "�չ�",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 (["quest":  "��ݦ",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),
 (["quest":  "�׻�",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��ɽ����" ]),    
 	
 (["quest":  "��ɣ",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�߲��Ǹ���" ]),
 (["quest":  "������",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�߲��Ǹ���" ]),
 (["quest":  "�䳤",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�߲��Ǹ���" ]),
 	
 (["quest":  "�Ű���",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����򸽽�" ]),
 (["quest":  "����",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����򸽽�" ]),
 (["quest":  "�蹤",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"����򸽽�" ]),
 	
 (["quest":  "κ�޼�",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ѩͤ�򸽽�" ]),
 (["quest":  "������",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ѩͤ�򸽽�" ]),
 (["quest":  "����һ��",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ѩͤ�򸽽�" ]),
 	
 (["quest":  "��ķ",  "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��һ�򸽽�" ]),
 	
(["quest":  "���Ҿ�",   "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
(["quest":  "��ʦү",   "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),
(["quest":  "����ǿ",   "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"��������" ]),		 
	
(["quest":  "��ľ��ӹ",   "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�����򸽽�" ]),
(["quest":  "Ҷ��ʿ",   "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�����򸽽�" ]),
(["quest":  "�·���",   "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�����򸽽�" ]),
	
(["quest":  "�·���",   "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�¼ұ�����" ]),
(["quest":  "�·���",   "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�¼ұ�����" ]),
(["quest":  "����",   "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"�¼ұ�����" ]),
	
(["quest":  "����ɩ", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ʢ������" ]),    	
(["quest":  "���ĳ�", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ʢ������" ]),    	
(["quest":  "����", "quest_type":"ɱ", "time":   400, "exp_bonus":120, "pot_bonus":68, "score" : 20,"quest_city":"ʢ������" ]),    	

});

mapping query_quest()
{
   return quest[random(sizeof(quest))];
}

