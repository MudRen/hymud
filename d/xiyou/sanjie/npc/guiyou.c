// guiyou.c ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"����"NOR, ({"gui you", "gui"}));
       set("long", "�ǹ�ڤ��ʦ�֣�����Ů�����Ǯ���书����ʦ�ܻ��\n");
       set("title", HIC"��ʬ��"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 46);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1200);
       set("max_force", 1200);
       set("force_factor", 120);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 120);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);


	create_family("����ɽ", 2, "��");

	set("inquiry", ([
	"name"     : "���ǲ�ʬ�ش���ӣ���������ʲô�£���\n",
	"here"     : "�����ǲ�ʬ�أ�����С�����ʲô��\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
}

