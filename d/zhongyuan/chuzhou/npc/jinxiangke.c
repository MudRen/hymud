// ���ݽ���� /d/city/chuzhou/npc/jinxiangke.c

inherit NPC;

void create()
{
    set_name( "�����", ({ "jinxiang ke", "ke", "pilgrim"}) );
    set( "long", "���Ǹ����ݽֵ��ϳ����ĵ����幬������Ľ���͡�\n");
    set( "age", 20 + random(65) );
    set( "attitude", "friendly" );
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);

    setup();
    carry_object( "/clone/misc/cloth")->wear();
    add_money( "coin", random(10) );
}

int query_answer( object who )
{
    command("say �꾰������Ҫ�������ɱ��Ӳ���.");
    return 1;
}

