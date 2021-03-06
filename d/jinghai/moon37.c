// /d/jinghai/moon37.c

inherit ROOM;

void create()
{
        set("short", "海滩上");
        set("long", @LONG
这里是一片浅滩，由于附近一带海底水草丰盛，所以这里的
鱼虾很多，特别是一种海鱼每年都到这里来产卵，海鱼是一种淡
水鱼，它的肉质细嫩，味道非常的鲜美，附近鱼村里的孩子和女
人经常到这里来捞 (lao)海鱼，你也试试吧，据说有得地方专门
收购这种鱼。
LONG
);

	set("exits",([
	"northwest" : __DIR__"moon1",
]));

        set("outdoors", "jinghai");

        setup();
}

void init()
{
	add_action("do_lao","lao");
}

int do_lao(string arg)
{
        object me = this_player();

        if( !arg && arg != "鱼" && arg != "fish")
		return 0;

	if (me->query("class") != "jinghai")
		return notify_fail("边上跳出来一个水勇朝你喊道：“这是靖海的地盘！别人不许在这打鱼！”\n说着把你手中的渔网抢走了。\n");

	if (me->query("jing") < 10 || me->query("kee") < 10 || me->query("sen") < 10)
		return notify_fail("你试了试鱼网的重量，可是没什么力气了。\n");

	me->start_busy(3);
	message_vision("$N扭腰跨步，一使劲将渔网撒了出去。\n",me);
	call_out("finish_lao",3,me);

	return 1;
}

void finish_lao(object me)
{
	if(!objectp(me))
		return;

	me->receive_damage("jing",10);
	me->receive_damage("qi",10);
	me->receive_damage("qi",10);

	message_vision("$N好像有什么预感，迅速的将渔网拉了回来。\n",me);
	if(random(10) < 7)
	{
		object ob;
		int n;

		ob=new(__DIR__"obj/shiban");
		write(sprintf("你在渔网里翻了翻，发现捞上了一条%s。\n",ob->name()));

		if(!ob->move(me))
			ob->move(this_object());
		ob->set("time",time());
		if(me->query("combat_exp") < 25000)
		{
			n = 10 + random(30);
			write(sprintf("\n你得到了 %d 点经验。\n\n",n));
			me->add("combat_exp",n);
		}
	}
	else
		write("你在渔网里翻了半天发现什么也没有。\n");
	me->stop_busy();
}
