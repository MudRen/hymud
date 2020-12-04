#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��һ��", ({ "yu yifei", "yu" }) );
        set("gender", "����" );
        set("age", 30);
                
        set("long", @LONG
һ����ɫ���Ƶĺ��ӣ��������ۡ�
LONG
);
        set("nickname", "�ؾ���");
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        
        set("neili",1000);
        set("max_neili",1000);
        set("str",30);
        
        set_skill("move", 120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("dodge", 120);
        set_skill("feixian-steps",350);
        set_skill("feixian-sword", 350);
        map_skill("sword", "feixian-sword");
        map_skill("parry", "feixian-sword");
        map_skill("dodge", "feixian-steps");
        map_skill("move", "feixian-steps");
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action ("dodge.tianwaifeixian") :),
        }) );
        
        set("inquiry_now", 0);
        set("youshan", 0);
        setup();
   carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
void init()
{       
        object me;
                
        ::init();
        me = this_player();
        if( interactive(me = this_player()) && !is_fighting() ) {
                if((me->query("����B/��Դ_����") || !random(200)) && !query("inquiry_now")) {
//              if(random(2) && !query("youshan")){             
                if(me->query("marks/��������")){
                        return 0;
                        }
                remove_call_out("do_ask");
                call_out("do_ask", 2, me);
                }
        }
        add_action("do_accept", "accept");
} 
int do_ask(object me){
        if(me->query("gender") == "����") {
                message_vision("$Ņͷ������һ��$n��", this_object(), me);
                message_vision("˵��������λ" + RANK_D->query_respect(me) + "��Ըһͬ��ɽ����
���������������󣯣�\n",
                                this_object());
                me->set_temp("marks/query_tongyou", 1);
                set("inquiry_now", 1);
                call_out("remove_ask", 20, me);
        } else {
        }       
} 
void remove_ask(object me) {
        if(interactive(me) && environment(me) == environment(this_object())){
                message_vision("$N˵��������Ȼ��λ" + RANK_D->query_respect(me) + "��ԥ�������Ǿ����ա���\n",
                                this_object());
           set("inquiry_now", 0);
                me->delete_temp("marks/query_tongyou");
        }
} 
int do_accept(string arg){
        object me;
        
        me = this_player();
        if(me->is_busy() || me->is_fighting() || !query("inquiry_now")){
                return 0;
        }
        if(!arg || arg != "yes" && arg != "no") {
                return 0;
        }
        if(!me->query_temp("marks/query_tongyou")) {
                return 0;
        }
        if(arg == "yes") {
                message_vision("$N����˵�������ã�������Ե�η�һͬ��ɽ����\n", me);
                set("youshan", 1);
                me->set_leader(this_object());
                me->command("follow yu yifei");
                this_object()->command("south");
                call_out("check_env", 5, me);
        } else {
                message_vision("$N���������м��������ʹ˱������\n", me);
        }
        remove_call_out("remove_ask");
        me->delete_temp("marks/query_tongyou");
        set("inquiry_now", 0);
        return 1;
} 
void check_env(object me){
        environment(this_object())->girl(me);
} 
