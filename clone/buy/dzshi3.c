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

string *typeshi1=({
HIY"��"NOR,
CYN"ľ"NOR,
GRN"ˮ"NOR,
RED"��"NOR,
YEL"��"NOR,
HIM"��"NOR,
HIW"��"NOR,
HIB"��"NOR,
WHT"��"NOR,
BBLK"��"NOR,
HIC"��"NOR,
HIR"ħ"NOR,
HIC"����"NOR,
CYN"����"NOR,
YEL"��Դ"NOR,
RED"����"NOR,
GRN"��Ԩ"NOR,
HIG"����"NOR,
WHT"��ʯ"NOR,
MAG"��ʯ"NOR,
HIC"����"NOR,
HIW"����"NOR,
HIR"����"NOR,
YEL"����"NOR,
HIY"����"NOR,
HIG"����"NOR,
GRN"����"NOR,
BLU"����"NOR,
});

void create()
{
	set_name(HIR "����ʯ" NOR, ({ "duanlian shi", "shi"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵľ���ʯ����˵��(usejl)�ڹ���������ʯ���������벻����Ч����\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "usejl");
}

int do_eat(string arg)
{
	object me;

        if (! arg)
                return notify_fail("��Ҫ��ʲô����ģ�\n");

        me = this_player();

	switch(arg){
case "��":	me->set_temp("buyuplb",1); break;
case "ľ":	me->set_temp("buyuplb",2);  break;
case "ˮ":	me->set_temp("buyuplb",3);  break;
case "��":	me->set_temp("buyuplb",4);  break;
case "��":	me->set_temp("buyuplb",5);  break;
case "��":	me->set_temp("buyuplb",6);  break;
case "��":	me->set_temp("buyuplb",7);  break;
case "��":	me->set_temp("buyuplb",8);  break;
case "��":	me->set_temp("buyuplb",9);  break;
case "��":	me->set_temp("buyuplb",10);  break;
case "��":	me->set_temp("buyuplb",11);  break;
case "ħ":	me->set_temp("buyuplb",12);  break;
case "����":	me->set_temp("buyuplb",13);  break;
case "����":	me->set_temp("buyuplb",14);  break;
case "��Դ":	me->set_temp("buyuplb",15);  break;
case "����":	me->set_temp("buyuplb",16);  break;
case "��Ԩ":	me->set_temp("buyuplb",17);  break;
case "����":	me->set_temp("buyuplb",18);  break;
case "��ʯ":	me->set_temp("buyuplb",19);  break;
case "��ʯ":	me->set_temp("buyuplb",20);  break;
case "����":	me->set_temp("buyuplb",21);  break;
case "����":	me->set_temp("buyuplb",22);  break;
case "����":	me->set_temp("buyuplb",23);  break;
case "����":	me->set_temp("buyuplb",24);  break;
case "����":	me->set_temp("buyuplb",25);  break;
case "����":	me->set_temp("buyuplb",26);  break;
case "����":	me->set_temp("buyuplb",27);  break;
case "����":	me->set_temp("buyuplb",28);  break;

	}




        if (! me->query_temp("buyuplb") )
{
                return notify_fail("����ȷѡ����Ҫ��ʲô����ģ�������:��,ľ,ˮ,��,��,��,��,��,��,��,��,ħ��\n����,����,��Դ,����,��Ԩ,����,��ʯ,��ʯ,����,����,����,����,����,����,����\n");
}


        message_vision("$N��" + this_object()->name() +
                       "�ó�����ɷۡ�\n", me);

                tell_object(me,  "������Щ�ۣ��´ι������"+typeshi1[(me->query_temp("buyuplb",1)-1)]+NOR"���Ե�������ʯ����\n" NOR);
//                me->set_temp("dlwok",1);

        destruct(this_object());
	return 1;
}
