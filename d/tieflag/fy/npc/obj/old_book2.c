 // force_book.c
inherit ITEM; 
void create()
{
        set_name("����", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�Ȿ�����ֽ�Ŷ��Ѿ������ˣ������Ȼ������������ڣ������񹦡�\n"+
                        "��˵����һ�ż�Ϊ�������ڹ���������Ϊֹ��ȴ�����ܹ����ɡ�\n"+
                        "�����ǡ�Ϊ�����ޡ���jiayi����ֻ��ʩչ��������֪����ʲô�ô���\n"
                );
                set("value", 70);
                set("material", "paper");
		set("skill", ([
			"name":	      "force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	59
	
		]) );
        }
        setup();
}       
