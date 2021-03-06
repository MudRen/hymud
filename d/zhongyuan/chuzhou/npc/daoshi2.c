// 楚州小道士 /d/city/chuzhou/npc/daoshi2.c
// by lala, 1997-12-13

inherit NPC;

void create()
{
    set_name( "云清子", ({ "yunqing zi", "yunqing", "daoshi" }) );
    set( "title", "道士" );
    set( "gender", "男性" );
    set( "class", "taoist" );
    set( "age", 20 );
    set( "per", 25 );
    set( "long", "这是个年轻的道士，是玉虚子的徒弟，不过大家几乎都没有听说他会什么。\n" );        
    set( "inquiry", ([
        "玉虚子"    : "“那是我的师傅啊，他老人家的本事可大了，还上东京谒见过皇上。”",
        "here"      : "“这可是楚州赫赫有名的上清宫，你不知道吗？”",
    ]));            
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);

    set("combat_exp",6000);

    setup();
    carry_object( "/clone/misc/cloth" )->wear();

}

