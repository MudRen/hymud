 inherit NPC;
 
#include <ansi.h> 
void create()
{
        set_name("����", ({"wuqing", "wu", "qing"}));
        set("long",
                "һ�������ܸɣ��书��ǿ���ͷ���������\n");
        set("gender","����");
        set("title", HIR "��Ǯ���ͷ�������"NOR);
        set("class", "legend");
        
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 1300);
        set("neili", 1300);
        set("max_mana", 300);
        set("mana", 300);
        set("force_factor", 20);
        
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set("combat_exp", 5000000);
        
        
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("force", 150);
        set_skill("qidaoforce", 150);
        set_skill("fall-steps", 120);
        set_skill("move",200); 
        map_skill("unarmed", "qidaoforce");
        map_skill("dodge", "fall-steps");
        map_skill("force","qidaoforce");
        map_skill("move","fall-steps"); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng" :),
        }) ); 
        setup();
        carry_object(__DIR__"obj/tangfu")->wear();
}
 
int accept_object(object who, object ob)
{
            command("grin");
            command("say Ϲ���۵Ĺ��ţ����һ�¸�ң���");
            kill_ob(who);
            return 0;
}
    
