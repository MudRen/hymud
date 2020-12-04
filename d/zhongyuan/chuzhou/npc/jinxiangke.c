// 楚州进香客 /d/city/chuzhou/npc/jinxiangke.c

inherit NPC;

void create()
{
    set_name( "进香客", ({ "jinxiang ke", "ke", "pilgrim"}) );
    set( "long", "这是个楚州街道上常见的到上清宫来进香的进香客。\n");
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
    command("say 年景不利，要多求神仙保佑才是.");
    return 1;
}

