//Cracked by Roath
// jingu.c ������

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"������"NOR, ({ "jingu zhou" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ƪ");
        set("long",
        "�����䣬�ֻ������������ԡ���ײ����ͨ������ħ��ֻ�����õ�������һ��ܽ�������������\n");
        set("material", "paper");       
        }
	setup();
}

