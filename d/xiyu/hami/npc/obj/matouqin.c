// matouqin.c ��ͷ��
// Ffox 98-4-30 18:57

inherit ITEM;

void create()
{
    set_name( "��ͷ��", ({"matou qin", "qin"}));
    set_weight( 1000 );
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", query("name") + "�����һ�����������\n");
        set("unit", "��");
        set("value", 4500 );
    }
}

