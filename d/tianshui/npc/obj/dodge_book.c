// dodge_book.c

inherit ITEM;

void create()
{
	set_name("���Ṧ���š�", ({ "dodge book","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",
                        "�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
                        "�ᵽһЩ��������ʲ��ġ�\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	"dodge",
			"exp_required":	0,
			"sen_cost":	20,
			"difficulty":	20,
			"max_skill":	42,
		]) );
	}
}