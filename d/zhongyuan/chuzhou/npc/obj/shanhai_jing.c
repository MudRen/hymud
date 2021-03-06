// 山海经 /d/city/chuzhou/shanhai_jing.c
// by lala, 1997-12-13

inherit ITEM;

int do_read( string arg );

void create()
{
    set_name( "「山海经」", ({ "shanhai jing", "jing", "book", "shu" }));
    set_weight(300);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set( "unit", "本" );
        set( "long", "这是一本有名的「山海经」，不过就是比较旧了。\n" );
        set( "value", 1500 );
        set( "material", "paper" );
        set( "skill", ([
            "name"                      :   "literate",  
            "xiuwei_required"           :   0,
            "literate_required"         :   20,
            "gin_cost"                  :   20+random(10),
            "max_lingwu"                :   50,
            "bonus_jilei"               :   5,
            "bonus_social_exp"          :   5,
            "max_social_exp"            :   3000,
        ]) );
    }
}

    