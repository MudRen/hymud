 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(GRN"���令�ĵ�"NOR,({"cuixiu dan","dan"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "��˵���ǡ���ɽ���䡱�Ķ�����ҩ������ʮ������ҩ������ʮ������ɣ�\nɫ����̣��������������޷��� ��\n");
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
        diff = this_player()->query("max_jing")-this_player()->query("eff_jing");
        if(!(diff))    return notify_fail("��û�����ˣ�\n");
    if(value < diff) value = diff;
            
    message_vision("$N����һ�����令�ĵ���һ��ů����ס�����Ϣ��Ȼ��ͨ����������\n",this_player());
        this_player()->add("eff_jing",value);
        destruct(this_object());
        return 1;
}     