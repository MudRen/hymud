#include <ansi.h>
inherit NPC;
string *name=({"����","����","����","����","����","����"});
void create()
{     
	set_name(YEL+name[random(sizeof(name))]+NOR, ({ "fish","yu" }) );
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һ�������ڳ����е�Ұ�㡣\n");
	
	set("str", 23);
	set("dex", 36);

	set("limbs", ({ "ͷ��", "����","β��" }) );
	set("verbs", ({ "bite"}) );

	set("chat_chance", 6);
	set("chat_msg", ({
		this_object()->name()+"���еô�����ǰ�ι���\n",
		this_object()->name()+"ҡ��ҡβ��,�������³�һ�����ݡ�\n",
           }));		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}
