// �˱�ӡ�� /d/city/chuzhou/npc/obj/babao_yinni.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( REV RED"�˱�ӡ��"NOR, ({"babao yinni", "yinni", }));
        set_weight(50);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
���Ǹ������ݵ��ز����ǲ������㡢���顢ɺ������觵Ȱ������ԭ�Ͼ��ƶ���
�ġ�����Ϊ�����鷨������ϲ�ã�������Ϊ�ʼҹ�͢��Ʒ���ں���ųơ�����֮
�⡱��
LONG
    );
                set("unit", "��");
                set("value", 700);
        }
        setup();
}
