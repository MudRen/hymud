
//judge_man.c

#include <ansi.h>
#include <command.h>
#define THIEF 3
#define ROBBER 5
inherit NPC;

void settle_lawsuit(object);
void do_it(object);
void test_crime();
int do_charge(string);
int do_quit(string);

void create()
{
	set_name("�����", ({ "county magistrate","magistrate" }) );
	set("title", "��Զ���ع�");
	set("gender", "����" );
	set("age", 32);
	set("str", 22);
	set("cor", 25);
	set("cps", 20);
	set("int", 30);
	set("per", 23);
	set("con", 24);
	set("spi", 15);
	set("kar", 25);

	set("long",

"�㿴���Ŀ����¶�����������Ĵ���---��Զ��ĸ�ĸ�١�\n"
"����Ȼ����ƶ�����������̿࣬����̽����������ǲŸ߰˶�������\n"
"���ڣ�����ͨ����Ϊ��������ƶ���������˾�����\n"
);
	set("combat_exp", 200000);
	set("attitude", "friendly");

	set("max_atman", 1000);
	set("atman", 1000);     set("atman_factor", 3);
	set("max_force", 1000);
	set("force", 1000);     set("force_factor", 10);
	set("max_mana", 1000);
	set("mana", 1000);      set("mana_factor", 3);

	set_skill("buddhism",40);
	set_skill("unarmed", 100);
	set_skill("literate",100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set_skill("force", 100);
	set_skill("spells", 100);



///	set("chat_chance",90);
//	set("chat_msg",({
//			(: call_out,"test_crime",1 :),
//			}));
	setup();

	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 1);
	add_money("silver",10);
}

