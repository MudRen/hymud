// shoujuan.c
// by dicky

inherit ITEM;

void create()
{
        set_name("�־�", ({ "nvren shoujuan", "shoujuan" }) );
	set("long", "����һ��Ů���õ��־�, ������������ԧ�졣\n");
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        setup();
}

