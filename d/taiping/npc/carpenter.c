#include <ansi.h>
inherit NPC;
 
void create()
{
    set_name("��ľ��",({"carpenter li","carpenter","li"}));
    set("title","С³��");
    set("long","
��ľ������������̫ƽ�����ǳ������ģ���������ļҾߣ�����ɥ��Ĺײģ�
������һ�Ұ��졣\n");
        set("gender","����");
        set("age",32);
                
        set("combat_exp",2200000);  
        set("attitude", "friendly");
        
        set("death_msg",CYN"\n$N������ˮ�ؿ���һ��������ļҾߡ������� \n"NOR);
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n��ľ���е������ӽ����������һ���ײģ�����\n",
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
                "��ľ���ֳ��ٸ������²�������������æµ�š�\n",
        }) );                   
        
          
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object(__DIR__"obj/paxe")->wield();  
    
}      
