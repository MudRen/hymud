// ���ӹ��� /d/city/chuzhou/npc/obj/songzi_guanyin.c
// by lala, 1997-12-16

inherit ITEM;

void create()
{
        set_name( "���ӹ���", ({"songzi guanyin", "guanyin", }));
        set_weight(50);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
һ������Ļ�����Ӥ���Ĺ�����ʿ�������������ز����Ǽ��͸��»�򸾵ĺ���
�
LONG
    );
                set("unit", "��");
                set("value", 250);
        }
        setup();
}
