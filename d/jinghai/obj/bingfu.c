#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(HIW"����ʮ��·ˮկ����"NOR,({ "bing fu", "fu" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����糤������,���������������[������]��\n");
                set("value", 10);
        }
}

