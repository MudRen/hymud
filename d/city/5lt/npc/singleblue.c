// singleblue.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("ϸ�첲¹", ({ "singleblue" }));
	set("title", HIM"����̨����"NOR);
	set("shen_type", 1);

	set("gender", "Ů��" );
	set("long", @LONG
ϸ�첲¹�������㣬������ͷд��ҵ��
LONG);
	set("nickname", HIW"������С��"NOR);
	set("age", 20);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
	]));                 

	set("combat_exp", 1000000);
	setup();

	carry_object("/clone/cloth/female1-cloth")->wear();
        carry_object("/clone/cloth/female-shoe")->wear();
}