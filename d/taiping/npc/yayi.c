#include <ansi.h>
inherit NPC;
 
void create()
{
    set_name("����",({"yayi",}));
    set("title","̫ƽ��");
    set("long","
̫ƽ��Ĳ�����ʵ�����������Ĺٶ���ֻ�ǳ�פ���������˰��﷽Բ����ô
һ�������ǹټҵĵط�������������ɱ��Խ���Ĵ󰸻������ﳳ�ܵļ�ëС
�£������������վ��Ա�ܡ�\n");
        set("gender","����");
        set("combat_exp",4500000);  
        
        set("max_force",1700);
        set("force",1700);
        
        set("attitude", "friendly");
        set("group","taiping");
        set("inquiry", ([
                "����" :        "�������Ͼ���һֻ�������㲱�������أ�",
        ]));
        set("death_msg",CYN"\n$N˵�������ˣ�����ɱͷ�ɡ��� \n"NOR);
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n����е������˰���ɱ����������\n",
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
                "�����������˵����ط��������飬ʲôҲû�С�\n",
                "�������������һ��ˮ��һ�����Ӻ�����ȥ��\n",
        }) );                   
        
         
        setup();
           carry_object(__DIR__"obj/yblade")->wield();    
        carry_object(__DIR__"obj/ycloth")->wear();  
    
    
}
