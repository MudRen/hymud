 inherit ITEM;
void create()
{
        set_name("虬枝剑式", ({ "book", "qiuzhi sword", "qiuzhi" }));
        set_weight(600);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "本");
            set("long",
                    "书本首页用寥寥数笔勾画出一棵雪中盛开的寒梅。\n");
            set("value", 0);
            set("no_give", 1);
            set("no_drop", 1);
            set("no_sell",1);
            set("material", "paper");
		set("skill", ([
                        "name":         "sword",      //name of the skill
                        "exp_required": 100000 ,        //minimum combat experience required
			"jing_cost":    20+random(100),// jing cost every time study this
			"difficulty":	60,           // the base int to learn this skill
			"min_skill":	0,           // the minimum level you can learn
			"max_skill":	120            // the maximum level you can learn
		]) );
        }
} 
