// Npc: xinghu.c
//by trill 02/04/97

inherit NPC;



void create()
{

    set_name( "�ϻ�", ({"xing hu", "robber"}) );
    set("long", @LONG
һ�����꺺�ӣ����ӽ�Ϊ�������Ĳ��ߣ�һͷ�ҷ������ϵ��·��ƾ�
���ҡ�
LONG
    );
    set( "gender", "����" );
    set( "attitude", "heroism" );

    set( "age", 24 );
    set( "qi",1000 );
    set( "max_kee", 500 );
    set( "eff_kee", 500 );
    set( "jing",500 );
    set( "max_sen", 500 );
    set( "eff_sen", 500 );
    set( "combat_exp", 80000 );

    set_skill( "unarmed",250 );


    setup();
    carry_object( "/clone/misc/cloth")->wear();
}

