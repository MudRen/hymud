// blade_book.c

inherit ITEM;

void create()
{
	set_name("���Ƶ���", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"���ƺ���һ��ʲ�ᵶ�׵�ǰ��ҳ����Ȼ��û�й����ʽ����ϸ��˵������\n"
			"ǰ���йص������ܸ��뾫�嵹�ǲ��١�\n");
		set("value", 260);
		set("material", "paper");
		set("skill", ([
			"name": 		"blade",		// name of the skill
			"exp_required":	1000,			// minimum combat experience required
											// to learn this skill.
			"sen_cost":		30,				// gin cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	40				// the maximum level you can learn
											// from this object.
		]) );
	}
}
