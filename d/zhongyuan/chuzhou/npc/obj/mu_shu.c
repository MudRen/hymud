// ����ľ�� /clone/wear/head/mu_shu.c
// by lala, 1997-12-16

#include <armor.h>

inherit HEAD;

void create()
{
    set_name( "����ľ��", ({"mu shu", "mushu"}));
    set_weight( 200 );
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", query("name") + "�ǳ��ݵ��ز�֮һ��\n");
        set("unit", "��");
        set("value", 400 + random( 500 ) );
        set("armor_prop/personality", 10);
    }
}
