// blade-book.c

inherit ITEM;

void create()
{
	set_name( "������Ҫ",({ "tangshi jianpu","jianpu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("treasure",1);set("unit", "��");
                set("long","����һ��������Ҫ��\n");
		set("value", 10000);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
                        "name":         "sword",      //name of the skill
                        "exp_required": 300000 ,        //minimum combat experience required
			"jing_cost":    30+random(300),// jing cost every time study this
			"difficulty":	60,           // the base int to learn this skill
			"min_skill":	0,           // the minimum level you can learn
			"max_skill":	680            // the maximum level you can learn
		]) );
	}
}
