#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("��������",({"baimian langzhong","baimian","langzhong"}));
        set("title",YEL"����կ �϶�"NOR);
        set("long","
��������������կ�Ķ����ҡ������������ܰף�Ҳ��û�������У�����������
�ú���û��һ����������ţ��ǻ���ʲô���ֺú��������������ѽ��Լ�����
�������ˡ�\n");
        
        set("gender","����");
        set("group","longhuzhai");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",80);
        set("class", "tieflag");

        set("reward_npc", 1);
        set("difficulty", 1);
        
      set("combat_exp", 20000000);
        set("score", 200000);

        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword", 100);
	set_skill("unarmed",80);
	set_skill("changquan",200);
	set_skill("feixian-steps",200);
	set_skill("feixian-sword",250);
	set_skill("jingyiforce",200);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
        
        set("neili",2500);
        set("max_neili",2500);
        set("force_factor",20);
        set("max_atman",800);
        set("atman",800);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",2000000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("death_msg",CYN"\n$N˵�������߲��������߲��ư�����\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.chansi" :),
        }) ); 

        set("chat_chance",1);
        set("chat_msg",({
                "�������е���������������˱����Ͳ�ϲ����ܵġ���\n",
        }) );                   
        
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","fy-sword",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/gsword")->wield();    
    
}  
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {    
                if(owner=me->query("possessed")) me = owner;
                if(me->query("wanma/׼��ɱɽ��"))
                        me->set_temp("wanma/��������",1);
        }
        ::die();
}      
