 inherit NPC;
#include <ansi.h>  
void create()
{
        object armor;
        set_name("老花匠", ({ "old gardener","gardener"}) );
        set("gender", "男性" );
        set("age", 60+random(10));
        set("long",
                "一个老态龙钟的花匠，正在给谷里的花草树木浇水剪枝。\n");
        set("attitude", "friendly");
        set("class","wudang");  
        set("combat_exp", 2700000);
        set("cor",40);
        set("cps",30);
        set("neili",800);
        set("max_neili",800);
        set("force_factor",50);
        
        set_temp("xinyoulingxi", 1);
        set("marks/悟出灵犀",1);       
        
        set_skill("dodge",150);
        set_skill("dodge",150);
        set_skill("force",120);

        set_skill("sword",150);
        set_skill("taiji-jian",160);
        set_skill("parry",170);

        

        map_skill("sword", "taiji-jian");
        map_skill("parry","taiji-jian");

        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30); 
   setup();
        
        armor=new("/clone/misc/cloth");
        armor->set_name(RED"杂役服"NOR,({"cloth"}) );
        armor->move(this_object());
        armor->wear();
        carry_object(__DIR__"obj/b_scissor")->wield();
}     
