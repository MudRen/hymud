
// magistrate_waiter.c

#include <command.h>
inherit NPC;


void create()
{
	set_name("��ǰ����", ({ "magistrate waiter","waiter" }) );
	set("gender", "����" );
	set("age", 24);
	set("str", 45);
	set("cor", 28);
	set("cps", 18);
	set("int", 10);
	set("per", 10);
	set("long", @LONG
   �������Ĵ��������̳����ĸ�ͽ.
LONG
);
	set("combat_exp", 28000);
	set("attitude", "heroism");
	set_skill("parry", 80);
    set_skill("dodge", 80);
	set_skill("unarmed",100);
	set("pending/charge",0);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",40);
}

