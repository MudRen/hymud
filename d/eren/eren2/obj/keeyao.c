 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(WHT"�����ܵ���"NOR,({"baiyun wan","wan"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "������ʢ��������ʥҩ�����۸񰺹���ͨ��ֻ��������̾��\n");
        set("unit","��");
        set("value", 5000);
        }
        
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{
        int value = 20;
        int diff; 
        if(this_player()->is_fighting())
            return notify_fail("ս���в�����ҩ����\n");
        diff = this_player()->query("max_qi")-this_player()->query("eff_qi");
        if(!(diff))    return notify_fail("��û�����ˣ�\n");
    if(value < diff) value = diff;
            
    message_vision("$N����һ�Ű����ܵ��裬�˿����������������������\n",this_player());
        this_player()->add("eff_qi",value);
        destruct(this_object());
        return 1;
}   
