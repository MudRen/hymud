// 西域记 /d/city/chuzhou/xiyu_ji.c
// by lala, 1997-12-13

inherit ITEM;

void create()
{
    set_name( "「大唐西域记」", ({ "xiyu ji", "ji", "book", "shu" }));
    set_weight(300);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set( "unit", "本" );
        set( "long", "这是一本记叙唐朝时西域风物的「大唐西域记」。\n" );
        set( "value", 4000 );
        set( "material", "paper" );
        set( "skill", ([
            "name"                      :   "literate",  
            "xiuwei_required"           :   0,
            "literate_required"         :   60,
            "gin_cost"                  :   30+random(10),
            "max_lingwu"                :   90,
            "bonus_jilei"               :   5,
            "bonus_social_exp"          :   10,
            "max_social_exp"            :   10000,
        ]) );
    }
}

   