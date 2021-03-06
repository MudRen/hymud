// shenliwan.c 福缘丹

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
HIY"金"NOR,
CYN"木"NOR,
GRN"水"NOR,
RED"火"NOR,
YEL"土"NOR,
HIM"风"NOR,
HIW"雷"NOR,
HIB"电"NOR,
WHT"天"NOR,
BBLK"地"NOR,
HIC"人"NOR,
HIR"魔"NOR,
HIC"天灵"NOR,
CYN"天宇"NOR,
YEL"福源"NOR,
RED"绝代"NOR,
GRN"天渊"NOR,
HIG"天玄"NOR,
WHT"白石"NOR,
MAG"紫石"NOR,
HIC"闪电"NOR,
HIW"巧制"NOR,
HIR"体灵"NOR,
YEL"周天"NOR,
HIY"长生"NOR,
HIG"不老"NOR,
GRN"不灭"NOR,
BLU"威力"NOR,
});

void create()
{
	set_name(HIR "精炼石" NOR, ({ "duanlian shi", "shi"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一块七彩的精炼石，据说用(usejl)在购买升级玉石，会有意想不到的效果。\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "块");
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
                return notify_fail("你要买什么种类的？\n");

        me = this_player();

	switch(arg){
case "金":	me->set_temp("buyuplb",1); break;
case "木":	me->set_temp("buyuplb",2);  break;
case "水":	me->set_temp("buyuplb",3);  break;
case "火":	me->set_temp("buyuplb",4);  break;
case "土":	me->set_temp("buyuplb",5);  break;
case "风":	me->set_temp("buyuplb",6);  break;
case "雷":	me->set_temp("buyuplb",7);  break;
case "电":	me->set_temp("buyuplb",8);  break;
case "天":	me->set_temp("buyuplb",9);  break;
case "地":	me->set_temp("buyuplb",10);  break;
case "人":	me->set_temp("buyuplb",11);  break;
case "魔":	me->set_temp("buyuplb",12);  break;
case "天灵":	me->set_temp("buyuplb",13);  break;
case "天宇":	me->set_temp("buyuplb",14);  break;
case "福源":	me->set_temp("buyuplb",15);  break;
case "绝代":	me->set_temp("buyuplb",16);  break;
case "天渊":	me->set_temp("buyuplb",17);  break;
case "天玄":	me->set_temp("buyuplb",18);  break;
case "白石":	me->set_temp("buyuplb",19);  break;
case "紫石":	me->set_temp("buyuplb",20);  break;
case "闪电":	me->set_temp("buyuplb",21);  break;
case "巧制":	me->set_temp("buyuplb",22);  break;
case "体灵":	me->set_temp("buyuplb",23);  break;
case "周天":	me->set_temp("buyuplb",24);  break;
case "长生":	me->set_temp("buyuplb",25);  break;
case "不老":	me->set_temp("buyuplb",26);  break;
case "不灭":	me->set_temp("buyuplb",27);  break;
case "威力":	me->set_temp("buyuplb",28);  break;

	}




        if (! me->query_temp("buyuplb") )
{
                return notify_fail("请正确选择你要买什么种类的？种类有:金,木,水,火,土,风,雷,电,天,地,人,魔。\n天灵,天宇,福源,绝代,天渊,天玄,白石,紫石,闪电,巧制,体灵,周天,长生,不老,不灭。\n");
}


        message_vision("$N把" + this_object()->name() +
                       "拿出打碎成粉。\n", me);

                tell_object(me,  "用了这些粉，下次购买的是"+typeshi1[(me->query_temp("buyuplb",1)-1)]+NOR"属性的升级玉石。。\n" NOR);
//                me->set_temp("dlwok",1);

        destruct(this_object());
	return 1;
}
