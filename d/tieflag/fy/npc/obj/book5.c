 // magic_book.c
inherit ITEM; 
void create()
{
        set_name("魔法简介", ({ "magicbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        
"这似乎是一本魔法的入门书，里面说了一些稀奇古怪的和一般的武学不同的东西\n"
                );
                set("value", 260);
                set("material", "paper");
		set("skill", ([
			"name":	      "spells",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	19
	
		]) );
        }
        setup();
}
     
