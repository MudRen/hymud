// һ�ź��� /d/city/chuzhou/npc/obj/yituanheqi.c
// by lala, 1997-12-16

inherit ITEM;

void create()
{
        set_name( "һ�ź���", ({"yituan heqi", "heqi", }));
        set_weight(50);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
һ������ֺ����ж���������˳����ˣ���������ز����ǲ�������
LONG
    );
                set("unit", "��");
                set("value", 170);
        }
        setup();
}
