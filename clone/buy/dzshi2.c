// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

mapping valid_typesw = ([
	"sword":	"sword",
	"blade":	"blade",
	"hammer":	"hammer",
	"whip":     "whip",
	"club":     "club",
	"staff":     "staff",
	"throwing":     "throwing",
	"dagger":     "dagger",			
"axe":     "axe",				
]);

mapping valid_typesa = ([
	"hands":	"hands",
	"cloth":	"cloth",
	"armor":	"armor",
	"boots":     "boots",
	"head":     "head",
	"neck":     "neck",
	"surcoat":     "surcoat",
	"shield":     "shield",			
"waist":     "waist",		
"wrists":     "wrists",			
]);


void create()
{
	set_name(HIR "ұ��ʯ" NOR, ({ "duanlian shi", "shi"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵ�ұ��ʯ����˵��(use)�ڹ����������������벻����Ч����\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "use");
}

int do_eat(string arg)
{
	object me;

        if (! arg)
                return notify_fail("��Ҫ��ʲô����ģ�\n");

        me = this_player();


	switch(arg){
case "sword":	me->set_temp("buyweaponlbw","sword"); break;
case "blade":	me->set_temp("buyweaponlbw","blade");  break;
case "hammer":	me->set_temp("buyweaponlbw","hammer");  break;
case "whip":	me->set_temp("buyweaponlbw","whip");  break;
case "club":	me->set_temp("buyweaponlbw","club");  break;
case "staff":	me->set_temp("buyweaponlbw","staff");  break;
case "throwing":	me->set_temp("buyweaponlbw","throwing");  break;
case "dagger":	me->set_temp("buyweaponlbw","dagger");  break;
case "axe":	me->set_temp("buyweaponlbw","axe");  break;
	}

	switch(arg){
case "hands":	me->set_temp("buyweaponlba","hands"); break;
case "cloth":	me->set_temp("buyweaponlba","cloth"); break;
case "armor":	me->set_temp("buyweaponlba","armor"); break;
case "boots":	me->set_temp("buyweaponlba","boots"); break;
case "head":	me->set_temp("buyweaponlba","head"); break;
case "neck":	me->set_temp("buyweaponlba","neck"); break;
case "surcoat":	me->set_temp("buyweaponlba","surcoat"); break;
case "shield":	me->set_temp("buyweaponlba","shield"); break;
case "waist":	me->set_temp("buyweaponlba","waist"); break;
case "wrists":	me->set_temp("buyweaponlba","wrists"); break;
	}


        if (! me->query_temp("buyweaponlba") && ! me->query_temp("buyweaponlbw"))
{
message_vision( "��������ѡ�� ��(sword) ��(blade) ��(hammer) ��(whip) ��(club) \n"
		"��������ѡ�� ��(staff)  ����(throwing)  ذ��(dagger) ��(axe)\n"
		"���߿���ѡ�� ����(hands) ��װ(cloth) ����(armor) ѥ��(boots) ͷ��(head)��\n"
		"���߻���ѡ�� ����(neck)�Ǵ�(surcoat)����(shield) ����(waist) ����(wrists)��\n"
    "��úÿ�һ�°ɣ�\n", this_player());
                return notify_fail("����ȷѡ����Ҫ��ʲô����ģ�\n");
}


        message_vision("$N��" + this_object()->name() +
                       "�ó�����ɷۡ�\n", me);

                tell_object(me, HIR "����Щ�ۣ��´ι�������֪����ʲô�ˡ���\n" NOR);
//                me->set_temp("dlwok",1);

        destruct(this_object());
	return 1;
}
