#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("����ս��", ({ "zhanpao" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ��ɫ�����޵�ս��\n");
                set("value", 7000);
                set("material", "cloth");
                set("skill", ([
                        "name":                 "parry", 
                        "exp_required": 0,                              
                        "jing_cost":             20,                             
                        "difficulty":   20,             
                        "max_skill":    5               
                ]) );
                set("armor_prop/armor",10);
                }
        
}