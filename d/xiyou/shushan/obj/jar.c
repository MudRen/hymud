//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit ITEM;
void init();
void create()
{
        set_name(HIM"��ֵ�ƿ��"NOR, ({"jar"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ֵ��飬����������ס��ʲô����������Դ���(dapo)����\n");
                set("value", 1);
                set("material", "paper");
        }
        setup();
}

