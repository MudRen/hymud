
#include <ansi.h>
inherit NPC;

string ask_liwu();

void create()
{
        set_name("��ʦ", ({ "chu shi" }) );
 //set("title", HIR "��������" NOR);
	set("gender", "����" );
	set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "
�Ŵ�ĳ�ʦ�����������Ҫ(yao)һЩ�Եġ�
\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);

	set_skill("unarmed", 1500);
	set_skill("blade", 1500);
	set_skill("parry", 1500);
	set_skill("dodge", 1500);


	setup();
	carry_object("clone/cloth/cloth")->wear();
}

