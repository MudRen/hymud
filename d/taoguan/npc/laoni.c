 // laoni.c
#include <ansi.h> 
inherit NPC;
void create()
{
        set_name("��������" , ({ "lao ni" }) );
        set("long", 
"һ���������ϵ������ᣬ��ü��Ŀ����ϥ������ǰ�������ϣ���Ȼ�����ţ�
�̿ɿ�����ĺܸߴ������۾�����ȫ�ǻ�ɫ�ģ����ݷ���ˮ�еĺ�������
������������һ����ˮ��������ִ��ų������������
"
);
        set("attitude", "friendly");
        set("ill_boss",5);
        set("class","shenshui");
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("force", 180);
        set_skill("parry", 140);
        set_skill("dodge", 140);
        set_skill("literate", 140);
        set_skill("move",140);

        set_skill("nine-moon-steps", 150);
        set_skill("nine-moon-claw", 200);
        set_skill("nine-moon-force", 150);
        set_skill("nine-moon-sword", 200); 
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword"); 
        set_temp("apply/parry", 100);
        set_temp("nine-moon-force_poison", 340);
        
        set("reward_npc", 1);
        set("difficulty", 25);  
        
        set("age", 65);
        set("gender", "Ů��" );
        set("combat_exp", 6500000);
   set("per", 2);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.polu" :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/cyan_cloth")->wear();
}   
