 inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name("��ֽƬ���Ͻ�", ({ "some paper","paper"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "һ��˺���˵�ֽƬ������д�š��״󾭡���\n");
        set("value", 2);
        set("lore",1);
        }
         
}  
 