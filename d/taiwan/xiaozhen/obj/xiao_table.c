inherit ITEM;

void create()
{
        set_name("����С����", ({ "table" }));
        set_weight(20000);
	set("long", "��������Ƕ���ķ�С���ӡ�\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
		set("value", 2000);
                set("mask","ׯ");
        }
        setup();
}

