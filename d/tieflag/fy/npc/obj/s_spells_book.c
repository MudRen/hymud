 // s_spells_book.c
inherit ITEM; 
void create()
{
        set_name("茅山道术入门", ({ "necrobook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        
"这是一本茅山道术的入门，通过这本书，你可以初步领略到茅山术的奥妙\n"
                );
                set("value", 8260);
                set("material", "paper");
		set("skill", ([
			"name":	      "spells",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	49
	
		]) );
        }
        setup();
}
      
