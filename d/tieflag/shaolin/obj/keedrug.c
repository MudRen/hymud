 // medicine.c
inherit ITEM; 
void create()
{
        set_name("����ɢ",({"sanbaosan"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ�豻��Ϊ����֮��������ɢ��\n");
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
        if(value > diff) value = diff;
            
        message_vision("$N������ɢ���ˣ�\n",this_player());
        this_player()->add("eff_qi",value);
        destruct(this_object());
        return 1;
}       
