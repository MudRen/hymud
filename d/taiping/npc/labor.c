#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("���",({"labor",}));
        set("long","��վ�����򣬵�λ��Ȼ��΢��ȴ�ǹ�ϵ����վ�����Ĳ�ʹ��\n");
        set("gender","����");
        set("int",22);
        set("cor",30);
        set("cps",20);
        
        set("combat_exp",1500000);  
        set("attitude", "friendly");
        

        set_skill("parry",200);
        set_skill("dodge",200);
        
        set("inquiry", ([
                "��������" :    "�ðѶ��Ұ��Ƕ��������������һ�°ɡ�\n\n",
                "����" :        "�ðѶ��Ұ��Ƕ��������������һ�°ɡ�\n\n",
                "��������":     "�ðѶ��Ұ��Ƕ��������������һ�°ɡ�\n",
        ]));
        
        set("death_msg",CYN"\n$N˵�������ˣ�����ɱͷ�ɡ��� \n"NOR);
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n���е������˰���ɱ����������\n",
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "�����æ���ҵش�ɨ���������ﲻ�鲻Ը������š�\n",
                "���˵����˭�ܰ��Ұ���Щ��������һ���أ���\n",
                "�����������ԡ��������ԡ���������\n",
                
        }) );                   
           
        
        setup();
        carry_object(__DIR__"obj/ycloth")->wear();      
        carry_object("/d/taiping/obj/brokenrake")->wield();
}     
