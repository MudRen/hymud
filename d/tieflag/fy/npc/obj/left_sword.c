 // sword_long.c
#include <weapon.h> 
inherit SWORD; 
void create()
{
        set_name("���ֽ�", ({ "left-sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��ֻ�ʺ���Ʋ���õĳ����������ᱡ\n");
                set("value", 80);
                set("material", "steel");
                set("wield_msg", "$N˫��һ�֣��ó�һ˫$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        } 
        ::init_sword(155);
}       
