// mai.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("��", ({ "mai jing", "mai", "jing" }));
	set("title", HIC"�޾������"NOR);
	set("long", 
"�����߰����𣬱㳣�굽��������׽з��ˮ�Լ��ߣ���һ���㲻
��ˮ�棬Ҳ����������\n");

	set("gender", "����");
	set("age", 52);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("qi", 11000);
	set("max_qi", 11000);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 1600);
	set("max_neili", 1600);
	set("combat_exp", 170000);
	set_skill("parry", 160);
	set_skill("unarmed", 160);
	set_skill("changquan", 160);
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
