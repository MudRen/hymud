#include <ansi.h>
inherit NPC;
void create()
{
	set_name("绿珠", ({ "greenpearl" }) );
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 50);
	set("long", @LONG
绿珠真是又漂亮又有一种诱人的女人味。你感兴趣的话，请（ｅｎｊｏｙ）．
LONG
);
	set("combat_exp", 1000000);
	set("attitude", "friendly");

	setup();
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}
void init()
{
	object me;
	me = this_player();
	if( me->query("gender") == "男性")
	add_action("do_enjoy","enjoy");
	else if (me->query("divorced"))
	{
	command("say 你这个不从一而终的东西！");
	kill_ob(me);
	me->kill_ob(this_object());

	}
}

int do_enjoy()
{
	object me;
	me = this_player();
	message_vision("$N轻飘飘地向$n走过来．．．．\n",this_object(),me);
	call_out("next_stage",3,me);
	return 1;

}
int is_ghost() {return 1;}
int next_stage(object me)
{
	if(objectp(me) && environment(me) == environment())
	{
        message_vision("$N狠狠地打了$n几个大耳光，骂道：都作鬼了，还那么猥琐，
那我就让$n在死几次！！\n", this_object(),me);
	add_temp("apply/attack",100);
	add_temp("apply/damage",50);
        kill_ob(me);
        me->kill_ob(this_object());
	}
        return 1;
}

