#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{
        set_name("������ͷ",({"old bard","bard","oldman"}));
        set("title","˵���");
        set("long","������ͷ�����Ѿ���ʮ�����ˣ��ڱ߳���˵������Ϊ����������Ȼ��������������
�˺ܶ�п�ĺۼ���������ȴû�е�ͷ�����ı������䣬�ж�����̫��������
����ƾ���Լ���Ŭ��ȥ׬ȡ����ķ��á�\n");
        set("gender","����");
        set("age",72);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",35);
        
        set_skill("unarmed",100);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("force",180);
        set_skill("move",200); 
        set_skill("music",300); 
        set_skill("magic",300); 
        
       map_skill("magic", "music");

        
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",90);
        set("max_atman",5000);
        set("atman",5000);
        set("max_mana",5000);
        set("mana",5000);
        set("combat_exp",2000000);  
        set("attitude", "friendly");
        
        set("death_msg",CYN"\n$N�����ﹾ���������ƺ���˵ʲô��ȴ����û˵������ \n"NOR);
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n������ͷ�е���������Ϲ�ͷ����ƴ�ˣ�����\n",
        ]) );           
        set("chat_chance",1);
        set("chat_msg",({
                "������ͷ�������֨֨ѽѽ���˼�������:����ʻʣ��ػʻʡ�����Ѫ�����޹⡣
һ�������ã������У��˶ϳ�����\n",
                "������ͷ���ų���������ʻʣ��ػʻʡ�����Ѫ���˶ϳ���һ�������ã������
���硣��\n",
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",150,160,0,"/obj/weapon/","fighter_w","fumostaff",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object(__DIR__"obj/erhu")->wield();  
    
}    
