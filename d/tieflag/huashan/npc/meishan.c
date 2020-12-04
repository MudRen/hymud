 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
    set_name("��ʿ", ({ "wen shi", "zhen zhen"}) );
    set("gender", "����" );
    set("age", 35);
    set("int", 30);
    set("per", 30);
    set("long",
        "��ƽ����ѩ���ϣ���׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶġ���Ϣ���ƺ���û����Ϣ����֪������û�оȡ�\n"
        );
    set("max_jing", 3000);
    set("max_qi", 3000);
    set("max_sen", 3000);
    set("eff_jing", 30);
    set("eff_qi", 30);
    set("eff_sen", 30);
    set("jing", 3000);
    set("qi", 3000);
    set("sen", 3000);
    set("max_neili", 3000);
    set("neili", 3000); 
    set("combat_exp", 9999999);
         set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );


        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        set("disable_type", HIR "<���Բ���>"NOR); 
        set("cured", 0);
        set("answered", 0);
    setup();
    carry_object("/clone/misc/cloth")->wear();
    
        this_object()->disable_player("<���Բ���>");
    this_object()->set_temp("is_unconcious",1); 
} 
void init(){
        ::init();
        if(find_call_out("do_leave") == -1 && !query("cured")) { 
                call_out("do_leave", 120);
        } 
        if(find_call_out("do_selfcure") == -1 && !query("cured")) {
                call_out("do_selfcure", 30);
        }
} 
void do_selfcure(){
        if(query("cured")) {
                return;
        }
        this_object()->enable_player();
        message_vision("$N���ֱۻ����ض���һ�¡�\n", this_object());
        message_vision("$NŬ���ع������ľ�����վ������������Ȼվ�Ĳ��ȣ�������վ���ŵġ�\n",
                        this_object());
        set("long", 
                "��������ô����㲶�˥������׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶģ��������峿���͵ķ��ѩ��������ز��ȶ���
��Ȼ����ֱͦ��վ�ţ�Ȼ��ȴ����ʱ��������� \n"
        );
        set("cured", 1);
}
void do_leave(){
   if(environment(this_object())->query("meishan")) {
                message_vision("\n$N���ų��صĲ���������ȥ��ѩ��������һ��������㼣��\n", this_object());
                destruct(this_object());
        }
} 
int Cured(object me){
        if(!query("cured") && !me->query("marks/killed_mei")) {
                message_vision("$N��Ϊ���ѵ���������������������������$n��������֪������˭�𡣡� 
���������򡡣���󣯣�\n", 
                                this_object(), me);     
                set("long", 
                "��������ô����㲶�˥������׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶģ��������峿���͵ķ��ѩ��������ز��ȶ���
��Ȼ����ֱͦ��վ�ţ�Ȼ��ȴ����ʱ��������� \n"
                );
                add_action("do_answer", "answer");
                set("cured", 1);
                this_object()->enable_player();
                remove_call_out("do_leave");
                call_out("do_leave", 60);
        } else {
                message_vision("$N΢΢һЦ��������л����֮������\n", me);
                message_vision("\n$N���ų��صĲ���������ȥ��ѩ��������һ��������㼣��\n", this_object());
                destruct(this_object());
        }
} 
int do_answer(string arg) {
        object me;
        me = this_player();
        if(!arg || (arg != "yes" && arg != "no")) {
                return 0;
        }
        if(query("answered")){
                return 0;
        }
        if(arg == "yes") {
                message_vision("$N΢΢һЦ���������¾��������������\n", me);
                message_vision("$N�������ã���Ȼ��ˣ�����һ��Ҳ֪�����������ҡ�����һ�����ձص��ر�����\n",
                                this_object());
                me->set("marks/÷ɽ��", 1);
           do_leave();
        } else if(arg == "no") {
                message_vision("$N��ɫãȻ��ҡ��ҡͷ��\n", me);
//              if(me->query("title") == "��ͨ����") {
                        message_vision("$Nע����$n��Ц�������������$N˵����������Ը�������ң��ɵ����Ƴ������������ҡ�\n", this_object(), me);
                        tell_object(me, this_object()->name() + "�ֵ����������֣���һ�����ƿ���ԣ������衡�������򶫱��У�Ȼ�����ż��ɡ���\n");
                        me->set("marks/÷ɽ��", 3);
                        do_leave();
//              } else {
//                      message_vision("$N�������������������������Ե������л����\n", this_object());
//                      me->set("marks/÷ɽ��", 2);
//                      do_leave();
//              }
        }
        return 1;
} 
void die(){
        object me;
        if(objectp(me=query_temp("last_damage_from") )) {
                me->set("marks/killed_mei", 1);
        } 
        ::die();
} 
