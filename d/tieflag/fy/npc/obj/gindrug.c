 // medicine.c
inherit ITEM; 
void create()
{
        set_name("������",({"hugu"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ�Ż����裬 �����ã������磩������ ��\n");
            set("unit","��");
            set("value", 2000);
        }
        setup();
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
        if(value > diff) value = diff;
            
        message_vision("$N�û����貹�� ��\n",this_player());
        this_player()->add("eff_jing",value);
        destruct(this_object());
        return 1;
}      
