// lingzhi.c

inherit ITEM;

void create()
{
	set_name("����֥", ({ "zi lingzhi"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",2000);
		set("unit", "֦");
		set("long", "����һ֦����֥��\n");
	}
}
/*
int valid_get(object me)
{
	object wg,env;

	if(!me)
		return 0;

	if(!(env = environment())
	|| !env->is_room()
	|| !(wg = present("hong wugong",env))
	|| !living(wg))
		return 1;

	message_vision(sprintf("$N����$nҪժ%s����������һ�³��˹�����\n",
		name()),wg,me);

	wg->kill_ob(me);
	me->kill_ob(wg);
	return 0;
}
*/
