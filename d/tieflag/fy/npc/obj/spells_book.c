 // spells_book.c
inherit ITEM; 
void create()
{
        set_name("������", ({ "spellsbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"���ƺ���һ������ļ�飬���滭��һЩϡ��Źֵķ���\n"
                );
                set("value", 260);
                set("material", "paper");
		set("skill", ([
			"name":	      "spells",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	39
	
		]) );
        }
        setup();
}
       
