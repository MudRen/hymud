//���ڴ���

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���ڴ���", ({"bowl","wan" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "����һֻ��ʢˮ�Ĵִɴ��롣\n");
		set("value", 0);
		set("max_liquid", 6);
        }
        set("liquid", ([
            "name" : "��ˮ",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}
