 // medicine.c
inherit ITEM; 
void create()
{
        set_name("С����",({"xiaodan"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ�豻��Ϊ����֮����С������ֻ��������С��\n");
            set("unit","��");
            set("value", 20000);
        }
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine(string arg)
{
        object victim;
        if(!arg || !objectp(victim=present(arg,environment(this_player()))))
        victim = this_player();
        if(this_player()->is_fighting() || environment(victim)->query("no_magic"))
            return notify_fail("���ڲ�����ҩ����\n");
        if(victim != this_player() && random((int)victim->query("combat_exp")) >
        (int)   this_player()->query("combat_exp"))
        {
                message_vision("$N��$n�ȵ����󵨣����Ҷ����¶�����\n",victim,this_player());
                victim->kill_ob(this_player());
                this_player()->kill_ob(victim);
                this_player()->start_busy(2);
        }
        tell_object(this_player(),"����ָ�׽�С������ɷ�ĩ������ص���"+
        victim->name()+"���ϡ�\n");
                victim->apply_condition("unknown",random(20)+5);
        destruct(this_object());
        return 1;
}      
