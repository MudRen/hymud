// zhuling.c ��ȸ������
#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(RED"��ȸ������"NOR, ({ "zhu ling", "ling" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����糤������,���������������[��ȸ]��\n");
        }
}

