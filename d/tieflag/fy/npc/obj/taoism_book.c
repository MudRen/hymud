 // taoism_book.c
inherit ITEM; 
void create()
{
        set_name("��ʦ��������", ({ "taoismbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"����һ����ʦ���������ţ�ֻ��ѧ����ʦ����������ܽ�һ�����éɽ���ĵȼ�.\n"
                );
                set("value", 8260);
                set("material", "taoism");
		set("skill", ([
			"name":	      "literate",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29
	
		]) );
        }
        setup();
}
    
