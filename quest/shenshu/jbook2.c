#include <ansi.h>
inherit ITEM;
#include "/quest/givetaskgift.c"
void create()
{
    set_name(HIW"金庸全集下册"NOR, ({ "jin bookb" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("shenshu",1);
            set("unit", "本");
            set("no_put", 1);
            set("material", "paper");
            set("long", "一本由神书合并成的卷册，你可以用(chayue)来查阅它。\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
}
int do_cha(string arg)
{
	object me,corpse;
	int exp,pot,score;
	me =this_player();
 	if (!id(arg))
	return notify_fail("你要查什么？\n");

	exp = 18800+random(8000);
	             pot = exp*2/3;
             score = random(200)+100;

     	      message_vision("$N仔细地查阅了一遍"+this_object()->query("name")+"。\n", me);
        addnl(me,"exp",exp);
        addnl(me,"score",score);
if (random(2)==0)
{
        corpse=new("/clone/gem/gem");
if (corpse->query("level") >4
&& random(2)>0)
{
        corpse=new("/clone/gem/gem");
}


message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "通过神书任务找到了一颗"+corpse->query("name")+HIM"!"NOR"。\n", users());
             corpse->move(me);
}

	destruct(this_object());
return 1;
}
