/* teacher.c ������
 * from XO Lib
 * a npc of gaochang
 * copied from yangzhou 19980430
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980430
 */


#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
    set_name(YEL "������" NOR,({ "lao xiansheng","xiansheng", "teacher"}) );
    set("gender", "����" );
    set("age", 55);
    set("long", @LONG
��������æ�Ž̼������������ڶ��飬ҡͷ���Եؿ�������֮����Ҳ������
LONG
    );
    set( "rank_info/respect","������" );
    set("attitude", "peaceful");
    set("combat_exp", 10);
    set("social_exp", 100000);
    set("positive_score",100);
    set("str", 15);
    set("cor", 18);
    set("cps", 20);
    set("per", 21);

        set("vendor_goods", ({
                "/clone/book/lbook1",
                "/clone/book/lbook2",
                "/clone/book/lbook3",
//                "/clone/book/lbook4",
        }));


    set_skill("literate", 150);
    set("inquiry", ([
         "literate" : "����ѧ����ʶ���𣿸��������ӾͿ����ˡ�",
         "����ʶ��" : "����ѧ����ʶ���𣿸��������ӾͿ����ˡ�",                
    ]));
    setup();
    carry_object( "/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int valid_teach( object me, string skill )
{
    if( !me->query( "hydra/gaochang/������" ) )
    {
        command( "say ��û���չ���������Ӱ�������" );
        return 0;
    }
    if ( skill != "literate" || me->query_jibie( "literate" ) > 49 )
        return 0;
    return 1;
}

int accept_object( object me, object ob )
{
    if ( ob->value() >= 2000 )
    {
        me->set( "hydra/gaochang/������",1 );
        message_vision("��������$NЦ������Ȼ���������ѧ֮�ģ��Ҿͽ���ɡ�\n", me);
        return 1;
    }
    return 0;
}


