// 镖局的总镖头 /d/city/chuzhou/npc/biaojuboss.c
// by lala, 1997-12-13

#include <ansi.h>

inherit NPC;

inherit F_VENDOR;

void create()
{
    set_name( "林一鸣", ({ "lin yiming", "lin", "master", }) );
    set( "title", REV BBLU WHT"扬威镖局"GRN"总镖头"NOR );
    set( "gender", "男性" );
    set( "age", 68 );
    set( "per", 22 );
    set( "long", @LONG
扬威镖局的总镖头，据说很有两下子，但是不知怎么的，他的镖局却经营的不怎
么样，大概是和官府以及江湖上的黑道人物关节打得不到吧。现在这老爷子年岁
大了，镖局生意也不行了，所以只好靠教人练功过日子。镖局里的几个镖头都是
他的儿子女儿，当然要说功夫，还是老爷子最好了。
LONG
    );
    set( "attitude", "friendly" );
    set( "talk_msg",({
    "现在我什么都不会说！",
    }));
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set("max_force", 1600);
    set("force",     1600);
    set("force_factor", 20);
    set("combat_exp", 100000);
    set("social_exp", 100000);
    set("positive_score", 5000);
    set("negative_score", 1000);


 
    setup();
      
    carry_object( "/clone/misc/cloth")->wear();
    carry_object( "/clone/weapon/gangdao")->wield();        
}          

