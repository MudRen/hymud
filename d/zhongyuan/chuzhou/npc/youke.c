// �����ο� /d/city/chuzhou/npc/youke.c
// by lala, 1997-12-14

inherit NPC;

void create()
{
        set_name("�ο�", ({ "you ke","ke"}));
        if ( random(10) < 7 )
            set("gender", "����" );
        else
            set("gender", "Ů��" );
        set("age", 15+random(50));
        set("long", "����һλ�ӳ���·�����ο͡�\n");
    set("no_leave_chuzhou", 1);
        set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :)
    }));
        set("combat_exp", 600+random(400));
    set("social_exp", 600+random(400));
        set("attitude", "friendly");

    set_temp("apply/attack",20+random(100) );
    set_temp("apply/defense",20+random(100) );
    set_temp("apply/damage",random(5) );
    set_temp("apply/armor",random(5) );
        setup();
        carry_object("clone/misc/cloth")->wear();

        add_money("coin", 100 + random( 100 ) );
        set("score",5-random(10));
}

