// blade-book.c

inherit ITEM;

void create()
{
	set_name( "唐诗剑法",({ "tangshi jianpu","jianpu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("treasure",1);set("unit", "本");
                set("long","这是一本唐诗剑法。\n");
		set("value", 1000);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
                        "name":         "liancheng-jian",      //name of the skill
                        "exp_required": 300000 ,        //minimum combat experience required
			"jing_cost":    30+random(300),// jing cost every time study this
			"difficulty":	60,           // the base int to learn this skill
			"min_skill":	0,           // the minimum level you can learn
			"max_skill":	380            // the maximum level you can learn
		]) );
	}
}
