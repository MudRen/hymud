#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
//      set("title",YEL"���˿�����"NOR);
        set("long", "����һ��ר�Ŵ�����̵�������\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1500000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );

        set_name("����",({"bandit"}));
        set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/oldcloth")->wear();
        
}  
void init() {
   
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
         add_action("do_kill", "kill");
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() ) return;
        if (ob->query("gender")=="Ů��") {
                message_vision(CYN"$N����$n�е������ˣ����¸��Ŵ�ү��������ɣ�\n"NOR,this_object(),ob);
                return;
                }
        else    {
                message_vision(CYN"$N�е����ٲƲ�������ʶ��ľͰѽ������£���ү����һ����·��\n"NOR,this_object());
                kill_ob(ob);
                }
} 
int do_kill(string arg){
        
        
        if ( (arg=="bandit" || arg=="bandit 2") && !this_object()->is_fighting()
                && this_player()->query_temp("eren/bandit_2") 
                && this_player()->query("combat_exp")>=2500000){
                message_vision(CYN"$N���һ�������ã��������֣�������\n"NOR,this_object());
                message_vision("$Nһ���̵������汳���ܵ��ˡ�\n",this_object());
                this_player()->set_temp("eren/bandit_around",1);
                destruct(this_object());        
                return 1;
                }
        return 0;
}    
