#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name(HIB"ս��֮��"NOR, ({ "tiger soul","soul" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ǵ�������ȵ�ս�������������İ���֮�ǣ�����֮����\n");
                set("rigidity", 5000);
                set("for_create_weapon",1);
                set("value", 1000);
                set("base_damage",60);
                set("material", "iron");
                set("max_enchant",8);
        } 
        ::init_hammer(60);
}      
