 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��ʮһ��", ({ "xiao11","xiao" }) );
        set("gender", "����" );
        set("age", 25);
        set("per", 27);
        set("attitude", "peaceful");
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 2000);
        set("neili", 2000);
        set("max_mana", 300);
        set("force_factor",20);
        set("mana", 300);
        set("long",     "��ȫ���ָɾ������࣬����һ���ոհ��˿ǵļ�����\n");
        set("combat_exp", 9999999);
        set("reward_npc", 1);
        set("difficulty", 10);
    set("title", "���");
        set_skill("blade", 120);
        set_skill("unarmed",50);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);
        setup();
        carry_object(__DIR__"obj/gelu")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object me;
        add_action("do_answer","answer");
        me = this_player();
        if(interactive(me) 
        ) call_out("ask_him", 1,me );  
} 
int ask_him(object me)
{
   if(environment(me) == environment())
        tell_object(me,name()+"�ʵ�������˭�����ڵ������ˣ���answer��\n");
        return 1;
}
int do_answer(string arg)
{
object me;
me =this_player();
if(!arg )
return notify_fail(name()+"����������Ҳ�ﲻ���ң�\n");
if( arg == "lian" || arg == "lian cheng bi" || arg == "���Ǳ�")
{
if(me->query_temp("in_doubt") && me->query_temp("listened"))
{
        if(!me->query("m_success/ʶ������"))
        {
                me->set("m_success/ʶ������",1);
                me->add("score",300);
        }
command("unwield gelu");
command("give gelu to " + me->query("id"));
tell_object(me,name()+"����������һ����������ˣ��ã�\n");
return 1;
}
else
return notify_fail(name()+"���������û��֤��ѽ��\n"); 
}
else
return notify_fail(name()+"�����Ҿ��ò���\n");
} 
