// shiban.c

inherit ITEM;

string *name = ({"ʯ����","�ϻ���","ƽ��","����","�ƻ���"});

void create()
{
        set_name(name[random(sizeof(name))], ({ "sea fish", "fish" }) );
        set_weight(1000);

	set("unit", "β");
	set("long", sprintf("����һβ�ھ���һ��ˮ�ﳣ����%s��\n",query("name")));
	set("value", 100);
}

int is_jinghai_fish() { return 1; }
