// guiming.c ��ڤ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"��ڤ"NOR, ({"master guiming", "master"}));
       set("long", "�ǹ���ʦ�ܣ������������������������ʦ��ǿ���ˡ�\n");
       set("title", HIC"��ʬ��"NOR);
       set("per", 40);
       set("gender", "����");
       set("age", 40);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 300);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 270);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);



	create_family("����ɽ", 1, "��");
	
	set("inquiry", ([
	"name"     : "�Ϸ��˹�ڤ������ʦ�ܡ�\n",
	"here"     : "���˲�ʬ�أ�û��������������ܡ�\n",
	]));
	
	set("time", 1);
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
}

