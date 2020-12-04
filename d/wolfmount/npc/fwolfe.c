#include <ansi.h>
inherit NPC; 
void create()
{
//      string *name = ({"��","��","��","��"});
//      set_name("��"+name[random(sizeof(name))], ({"fighter wolf"}) );
        set_name("����",({"fighter wolf"}));
        set("gender", "����" );
        set("nickname", HIR"��ɽ����"NOR);
        set("long", "����һ��������ʢ����ɽ��ʿ��������ɽ��������Ѳ�ӡ�\n");
        set("attitude", "friendly");
/*      set("max_jing", 400);
        set("max_qi", 400);
        set("max_jing", 400); */
        set("age", 18+random(10));
        set("str", 20+random(10));
        set("cor", 20);
        set("cps", 25);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ɽ�����������촽���þ�û�гԵ���Ұ�����ˣ�\n",
        }) );
        set("combat_exp", random(80000)+100000);
        create_family("��ɽ", 1, "���Ĵ�����");
        set_skill("blade", 50+random(20));
        set_skill("parry", 50+random(20));
        set_skill("dodge", 50+random(20));
        set_skill("move", 50+random(20));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/wolfblade")->wield();
        add_money("silver", random(100));
} 
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
           call_out("greeting", 2, ob);
        }
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;
   
        if (ob->query("class") != "wolfmount")
        {
        message_vision("$N��Ȼ����������ɽ�ж���������������ĺ��ӣ�\n",this_object());
                return;
        }
        else
        {
        message_vision("$N��$nһ���ֵ�����λͬ�������ˣ���ɽ�����˲��ٷ����? \n", this_object(), ob);
                return;
        }
} 
int accept_object(object me, object obj)
{       
        object npc;
        npc = this_object();
        if( obj->query("name") == "��Ұ����" )
        {
                command("say �ã��ã���л�㣡\n");
                command("whisper "+me->query("id")+" ��ɽ�Ƚ�Σ�գ�������߾���ɽ�ɣ�\n");
                me->set_temp("marks/��ɽ�ο�",1);
                return 1;       
        }
        else
        {
                command("shake "+me->query("id"));
                return 0;
        }
        return 1;
}       
