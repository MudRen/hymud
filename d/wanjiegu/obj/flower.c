// flower.c

inherit ITEM;

void create()
{
        set_name("���黨", ({ "jueqing hua" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ɢ���Ŵ̱�ζ��Ұ����\n");
                set("unit", "��");
                set("value", 0);
        }
}

