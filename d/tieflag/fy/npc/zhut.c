 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��������", ({ "zhu" }) );
        set("gender", "����" );
        set("age", 65);
        set("title", HIG "�꺮����"NOR);
        set("str", 6);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27); 
        set("attitude", "peaceful");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 3000);
        set("neili", 3000);
        set("max_mana", 300);
        set("mana", 300); 
        set("long",     "������̵����󻤷�֮һ\n");  
        set("combat_exp", 999999); 
        set_skill("throwing", 100);
        set_skill("force", 130);
        set_skill("literate", 70);
        set_skill("parry",200);
        set_skill("qidaoforce", 100);  
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
        if( (string) ob->query("name") == "��ɲ��")
        {
                who->set("marks/����˪",0);
                message_vision("$N��$n�����������ǵ�ǰ�Ӿ�Թ��һ��赣�������\n",this_object(),who);
                who->remove_all_killer();
                return 1;
        }
        return 0;
}
