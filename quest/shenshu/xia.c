#include <ansi.h>
inherit ITEM;
#include "/quest/givetaskgift.c"
void create()
{
    set_name("萧秋水传奇下册"NOR, ({ "xiabook" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
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
int do_cha()
{
	object me,corpse,ob;
	int exp,pot,score;
	me =this_player();
	exp = 12900+random(2900);
	             pot = exp*2/3;
             score = random(20)+20;

     	      message_vision("$N仔细地查阅了一遍"+this_object()->query("name")+"。\n", me);
        addnl(me,"exp",exp);
        addnl(me,"score",score);
if (random(3)==0)
{
        corpse=new("/clone/gem/gem");
if (corpse->query("level") >4
&& random(3)>0)
{
        corpse=new("/clone/gem/gem");
}

if (random(3)==1)
{
        ob=new(__DIR__"sdan");
        ob->move(me);
message("channel:chat", HIC"【江湖传闻】"GRN + me->query("name")+"得到一颗"+HIY":" + ob->query("name")+HIG"啦！\n"NOR,users() );
}

message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "通过神书任务找到了一颗"+corpse->query("name")+HIM"!"NOR"。\n", users());
             corpse->move(me);
}

	destruct(this_object());
return 1;
}
