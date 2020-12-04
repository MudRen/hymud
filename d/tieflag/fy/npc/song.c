 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��������", ({ "song" }) );
        set("gender", "����" );
        set("age", 66);
        set("str", 6);
        set("title", HIG "�꺮����"NOR);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("intellgent",1);
        set("attitude", "peaceful");
        set("fly_target",1);
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 500);
        set("neili", 500);
        set("max_mana", 300);
        set("mana", 300);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.dimo" :),
                (: perform_action, "unarmed.renmo" :),
                (: perform_action, "unarmed.tianmo" :),
                (: exert_function, "mihun" :),
        }) ); 
        set("long",     "������̵����󻤷�֮һ\n");  
        set("combat_exp", 999999); 
        set_skill("unarmed", 120);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70); 
        set_skill("demon-force", 100);
        set_skill("demon-strike", 80);
        set_skill("demon-steps", 10); 
        map_skill("unarmed", "demon-strike");
        map_skill("dodge", "demon-steps");
        map_skill("force","demon-force"); 
        setup(); 
        carry_object(__DIR__"obj/stone")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object me;
        me = this_player();
        if(interactive(me) && me->query("marks/����˪")
        && (int) me->query("combat_exp") > 20000) call_out("chase_him", 1,me );  
} 
int chase_him(object me)
{
        message_vision("$N��$n�ȵ�������͵�����̵���ɲ�ƣ�������\n",this_object(),me);
        set_leader(me);
        kill_ob(me);    
        me->kill_ob(this_object());
        return 1;
}
int accept_object(object who, object ob)
{
        if( (string)ob->query("name") == "��ɲ��")
        {
                who->set("marks/����˪",0);
                message_vision("$N��$n�����������ǵ�ǰ�Ӿ�Թ��һ��赣�������\n",this_object(),who);
                who->remove_all_killer();
                return 1;
        }
        return 0;
} 
