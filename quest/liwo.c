#include <ansi.h>
inherit ITEM;

void create()
{
    int i; 
    string *names = ({
        WHT"����"NOR,RED"���"NOR,MAG"���"NOR,HIG"����"NOR,HIW"ɺ��"NOR,HIR"è����"NOR,GRN"��ĸ��"NOR
    });
    i = random(7);
    set_name( names[i], ({ "treasure stone" }));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long", "�����챦����ֵ���ǣ��������ۺ찡��\n");
                set("value", 50000);
                set("material", "paper");
		 
         }
}
