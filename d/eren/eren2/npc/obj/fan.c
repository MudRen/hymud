 // silencer@fengyun.com
#include <ansi.h>
inherit ITEM; 
void create()
{       set_name("������",({ "fan" }) );
        set_weight(10000);
        set("unit", "��");
        set("long", "һ�������ӱ�ɵĴ����ȡ�\n");
        set("value", 1000);
        
} 
void init(){
        add_action("do_wave", "wave");
} 
int do_wave(string arg){
        
        object me;              
        me = this_player();
        if (!arg && arg!="fan" && arg!="������") {
                tell_object(me,"��Ҫ��ʲô��\n");
                return 1;
                }
        if( me->is_busy() ){
                tell_object(me,"��������æ��\n");
                return 1;
        }
        message_vision("������һ�Ѵ����ȣ����������˼��£�����ϰϰ�������ʱ�泩����ࡣ\n",me);
        if (me->query("bellicosity")>50)
                me->add("bellicosity",-50);
                else me->set("bellicosity",0);
        me->start_busy(1);      
        return 1;
}
