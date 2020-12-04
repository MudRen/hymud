#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"取经帐篷"NOR, ({ "zhangpeng" }) );
    set_weight(1);
            set("no_put", 1);
            set("value", 0);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
            set("no_steal", 1);
            //set("no_get", 1);
            set("no_beg", 1);
            set("value", 100000);
            set("unit", "座");
            set("material", "paper");
            set("long", "你可以用(usezp)来达到你西域的居所 或(homezp)来设置西域的居所。\n");
          }

    setup();
}
void init()
{
	add_action("do_eat", "usezp");
	add_action("do_set", "homezp");
}

int do_set(string arg)
{
        object me = this_player();
        string target;
 	if (!id(arg))
	return notify_fail("你要用什么？\n");

    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");
    if (me->query("neili")<3000)
	return notify_fail("你的内力不足!\n");
    if(environment(me)->query("outdoors")=="xy1"
       ||environment(me)->query("outdoors")=="xy2"
       ||environment(me)->query("outdoors")=="xy3"
       ||environment(me)->query("outdoors")=="xy4"
       ||environment(me)->query("outdoors")=="xy5"
       ||environment(me)->query("outdoors")=="xy6"
||environment(me)->query("outdoors")=="xy7"
||environment(me)->query("outdoors")=="xy8"
||environment(me)->query("outdoors")=="xy9"
||environment(me)->query("outdoors")=="xy10"
||environment(me)->query("outdoors")=="xy11"
||environment(me)->query("outdoors")=="xy12"
||environment(me)->query("outdoors")=="xy13"
||environment(me)->query("outdoors")=="xy14"
||environment(me)->query("outdoors")=="xy15"
||environment(me)->query("outdoors")=="xy16"       
||environment(me)->query("outdoors")=="xy17"
||environment(me)->query("outdoors")=="xy18"
||environment(me)->query("outdoors")=="xy19"
||environment(me)->query("outdoors")=="xy20"
||environment(me)->query("outdoors")=="xy21"
||environment(me)->query("outdoors")=="xy22"
||environment(me)->query("outdoors")=="xy23"
||environment(me)->query("outdoors")=="xy24"
||environment(me)->query("outdoors")=="xy25"
||environment(me)->query("outdoors")=="xy26"
||environment(me)->query("outdoors")=="xy27"
||environment(me)->query("outdoors")=="xy28"
||environment(me)->query("outdoors")=="xy29"
||environment(me)->query("outdoors")=="xy30"
||environment(me)->query("outdoors")=="xy31"
||environment(me)->query("outdoors")=="xy32"
||environment(me)->query("outdoors")=="xy33"
||environment(me)->query("outdoors")=="xy34"
||environment(me)->query("outdoors")=="xy35"
||environment(me)->query("outdoors")=="xy36")
{
        target=(string)file_name(environment(me));
        me->set("qjtarget",target);
        me->start_busy(8);
        message_vision(HIY "$N吃把取经帐篷拿出，一阵光辉笼罩了你!\n" NOR, me);
        message_vision(HIY "下次使用取经帐篷你将会直接来到这里!\n" NOR, me);
        me->add("neili",-2000);
}	
else 
{
        message_vision(HIG "$N这里不能使用!\n" NOR, me);
}
	return 1;
}


int do_eat(string arg)
{
        object me = this_player();
        object tarset;
 	if (!id(arg))
	return notify_fail("你要用什么？\n");

    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");
    if (me->query("neili")<3000)
	return notify_fail("你的内力不足!\n");

     if (!me->query("qjtarget"))
        return notify_fail("你没有设置西域的居所!\n");
        
     if (!me->query("qjtarget"))
       {
        me->move("d/city/guangchang");
       }
      else{
      tarset=me->query("qjtarget");
      me->move(tarset);
      }
        me->start_busy(8);
        message_vision(HIY "$N把取经帐篷拿出 并钻了进去，一阵光辉笼罩了你!\n" NOR, me);
        me->add("neili",-2000);
	destruct(this_object());

	return 1;
}

