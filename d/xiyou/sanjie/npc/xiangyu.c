// xiangyu.c ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"����"NOR, ({"xiang yu", "xiang"}));
       set("long", "һ�����ۣ������������Թ�ޣ�ǧ����ԩ�겻Ϣ��\n");
       set("title", HIC"�׵���"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 30);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "���");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 240);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);


	create_family("����ɽ", 1, "��");
	


	set("inquiry", ([
	"name"     : "�������𣬵���ܸ��������Ҫ��\n",
	"here"     : "�������ڽ��ߣ���������ɱ�ĵط���\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/leidao")->wield();
}

