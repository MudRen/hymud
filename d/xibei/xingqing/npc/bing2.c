//bing2.c.���ξ�
//date:1997.8.24
//by dan      

#include <ansi.h>
inherit NPC;         

void create()
{
    set_name(HIB"���ξ�"NOR, ({ "mayao jun" }));
    set( "age", 28 + random( 5 ) );
    set("title","");
    set("gender", "����");
    set("long", "����һ�����ξ����٣���������ΰ�Ѳ����¡�\n");
    set("str",40);
    set("per", 25);
    set("combat_exp", 50000);
    set("max_jing",300);
    set("max_qi",700);
      set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        "���ξ��ȵ������������һ����,�������������£�\n",
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
    setup(); 
    carry_object(__DIR__"obj/blade1")->wield();
    carry_object(__DIR__"obj/junfu")->wear();
    carry_object(__DIR__"obj/kaijia1")->wear();
    carry_object(__DIR__"obj/toukui1")->wear();
    carry_object(__DIR__"obj/zhan_pao")->wear();
    carry_object(__DIR__"obj/zao_sitao")->wear();
    carry_object(__DIR__"obj/pixue")->wear(); 
} 

void init()
{
    object ob;

    ::init();
    if ( interactive(ob = this_player()) && !is_fighting() )
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object who)
{
    if ( !present( who, environment( this_object() ) ) )
        return;
    if ( who->query_condition("kill_xingqing") )
    {
        message_vision("Ѳ�ߵ����ξ�����$N���һ������ɱ�˷Ż�ĵ��񣬿�������ɣ������� \n",who);
        kill_ob(who);
        who->fight_ob(this_object());
        return;
    }
}

int accept_fight(object me)
{
    command("say �ҿ�������ǻ�ò��ͷ���,"+ RANK_D->query_rude(me)+",ȥ���ɣ�\n");
    //me->apply_condition("kill_xingqing", 360);
    kill_ob(me);
    return 1;
}

