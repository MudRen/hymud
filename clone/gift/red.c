// 红包

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"黄金蛋"NOR, ({"gold egg"}));
	set_weight(10);
    set("value", 0);
set("no_steal",1);
set("liwu",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一个"+HIY"黄金蛋，"NOR+"似乎可以兑换(duihuan)。\n");
                set("unit", "个");
	}
}
  void init()
{
  add_action("do_open","duihuan");
}
int do_open()
{
	int exp,pot,score;
object corpse;
object ob;
int i,j;
        object me = this_player();

        this_player()->start_busy(30);

	exp = 500+random(388);
	             pot = exp*0.8;
             score = random(20)+10;
        me->add("max_neili", 1);
        me->add("combat_exp", exp);
        me->add("potential", pot);
tell_object(me,HIY"你被奖励了：一点内力上限\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" NOR);

i=random(8)+1;
j=random(18)+1;
//tell_object(me,HIY"你找到了一些黄金!\n"+NOR);
if (random(5)==0)
{
ob=new("/clone/money/gold");
ob->set_amount(j);
ob->move(me);
message_vision(HIY"$N兑换了一个黄金蛋，$N换到了"+j+"两真的黄金. \n"NOR, this_player());
}
else
if (random(8)==0)
{
ob=new("/clone/money/1000-cash");
ob->set_amount(i);
ob->move(me);
message_vision(HIY"$N兑换了一个黄金蛋，但$N换到了"+i+"张一千两银票. \n"NOR, this_player());
}
else

{
ob=new("/clone/money/silver");
ob->set_amount(j);
ob->move(me);
message_vision(HIY"$N兑换了一个黄金蛋，$N换到了"+j+"两真的白银. \n"NOR, this_player());
}




	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
