#include <ansi.h>
inherit NPC;
void create()
{
    set_name("С��ȸ", ({ "yellow bird", "bird" }) );
    set("race", "Ұ��");
    set("age", 1);
    set("gender", "����");
    set("long", "����һֻС��ȸ��ԭ����������ë���Ҳ�����
��������׵�ץס����������裩��\n");
    set("attitude","peaceful");
    set("limbs", ({ "ͷ��", "����","β��" }) );
    set("verbs", ({ "bite","claw" }) );
//    set("unique_amount", 1);  
//    ITEM_D->setup_unique(this_object());  
    set("eff_qi", 1);
        set("weight", 200);
        set("no_get", 1);
        set("no_give", 1);
        set("no_drop", 1);
    setup();
}  
int kill_ob(object me){   
    message_vision("$N�鴤�˼��£��;�ֹ�����ˡ� \n",this_object());
    me->set("marks/����", 1);
    ::die();
    return 1;
}
void init() {
    ::init();
        if (this_player() == environment()) {
                add_action("do_release", "release");
        }
        add_action("do_catch", "catch");
        call_out("not_cured", 60);
} 
void not_cured(){
//    if(!userp(environment(this_object()))){
        if(query("eff_qi") == 1){
                message_vision("$N�鴤�˼��£���һ�������ˡ� \n",this_object());
                   set("long", "����һֻС��ȸ��ԭ����������ë���Ҳ�����\n");
                ::die();
        }
} 
void Cured(object bird){
    set("long", "����һֻС��ȸ����������һȦ�ۻ�ɫ����������Ƶ��۾��������µĴ����㡣
��������Ű������ˣ� �������壩��\n");  
    set("rescue_time", time());
} 
int do_catch(string arg) {
        object me, bird;
        
        me = this_player();
        bird = present("yellow bird", environment(me));
        if(!arg || (arg != "yellow bird" && arg != "bird")) {
                return 0;
        }
        if(!present("yellow bird", environment(me))){
                return 0;
        }
        message_vision("\n$NС�ĵ�����֣�����İ�$n����������\n$n����ë΢΢�����ţ�����������$N�����ġ�\n", me, bird);
        bird->move(me);
        return 1;
}
int do_release(string arg) {
        object me;
        int i;
        me = this_player();
    i = query("rescue_time");
        if (!arg || (arg != "bird" && arg != "yellow bird")) {
                return 0;
        }
        if(environment(me)->query("indoors")) {
            return notify_fail("Ҫ��С����ȥ����ɡ�\n");
        }
    if(time() - i > 1440) {
                message_vision("$N��$n�������У�$n���߷ɣ���$Nͷ����������Ȧ��\nȻ����������ش��ƶ�ȥ��\n"
                        , me, this_object());
        if(!me->query("marks/��ɽ_��ȸ")) {
                        set("marks/��ɽ_��ȸ", 1);
           }
                if(!me->query("m_success/��ɽ_��ȸ")){
            me->set("m_success/��ɽ_��ȸ",1);
            me->add("score",500);
                }
                destruct(this_object());        
                return 1;
        } else {
            message_vision("$N��$n�������У�$n���˶����û�ܷ����������˵�����ë�ƺ���û�г��á�\n", me, this_object());
                return 1;
        }       
        return 1;
} 
       
