#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
    set_name("����֩��",({"feitian zhizhu","feitian","zhizhu" }));
//    set("title","��׾޺�");
    set("long","��������֮�죬����֮�ܵ������治����ϸ����˿���������硯��˸��֡�\n");
        set("gender","����");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
                set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
set("class", "bat");
        
           set_skill("force", 120);
    set_skill("bibo-force", 100);
    set_skill("blade", 220);
    set_skill("wind-blade", 220);
    set_skill("unarmed", 150);
    set_skill("dodge", 150);
    set_skill("luoriquan", 220);
    set_skill("move", 320);
    set_skill("fengyu-piaoxiang", 320);
    set_skill("parry", 120);
    set_skill("literate",180);
    set_skill("stealing",320);
    
    map_skill("blade"  , "wind-blade");
    map_skill("force"  , "bibo-force");
    map_skill("unarmed", "luoriquan");
    map_skill("dodge"  , "fengyu-piaoxiang");
    map_skill("move"  , "fengyu-piaoxiang");


        
        set("attitude", "friendly");               
       // set("death_msg",CYN"\n$N�ûڲ��ѣ����ҡ������ǡ���������̫�������ˡ�������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	          (: perform_action, "unarmed.luori" :),

        }) );
       /* set("chat_chance",1);
        set("chat_msg",({
                "��������ɫ������ϴ������Ԫ������������ϴ���õġ���\n"
        }) );                   */
           
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        
    
}
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        me->set_temp("wanma/ɱ����a",1);
        ::die();
}  
