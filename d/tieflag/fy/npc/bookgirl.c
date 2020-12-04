 // worker.c
inherit NPC; 
void create()
{
        set_name("雅芳", ({ "yafang", "shu" }) );
        set("gender", "女性" );
        set("age", 9);
        set("title","小书童");
        set("long", "天真的小书童正在整理房间。 \n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
        set_skill("dodge", 100);
        set_skill("throwing", 50);
        set("max_qi",400);
        set("eff_qi",400);
        set("qi",400); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/flower")->wield();
}  
