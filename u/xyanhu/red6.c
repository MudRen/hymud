// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
      add_action("do_eat", "smile")
;

}
void create()
{
    set_name(HIC"兜兜兜"NOR, ({"duu"}))
;
	if (clonep())
		set_default_object(__FILE__);
	else {
//      set("no_give","每个人只有一个，你都这么大方！\n");
      set("value", 100);
//  set("liwu",1);
//  set("no_steal",1)
//  set("no_beg",1)
//      set("no_get","每个人只有一个，不要这么贪心！\n");
//      set("no_drop","这么珍贵的东西你也扔？！\n");

                set("unit", "个");
set("long", "这是一个可爱无敌的兜兜兜(duu),她正对你笑呢，\n你不想对她也微笑(smile)吗？\n")
;

                  set("value", 100);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
      return notify_fail("你要对谁微笑？\n")
;
        this_player()->start_busy(20);
        this_player()->add("max_neili",10);
        this_player()->add("potential",500);
        this_player()->add("combat_exp",1000);
  this_player()->add("expmax",389)
;
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
