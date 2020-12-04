 inherit NPC;
void create()
{
        set_name("御厨", ({ "cooker" }) );
        set("gender", "男性" );
        set("age", 43);
        set("long", "一个本是紫禁城皇宫御膳房的大厨，后来被快活王抓到楼兰地宫做饭烧菜。\n");
        set("combat_exp", 1000000);
        set("force", 500);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force_factor", 12);
        set_temp("apply/attack", 150);
        set_temp("apply/dodge",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "御厨汗流浃背得忙着烧清蒸鲈鱼，香味四溢。。。\n",
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您一定会在这儿玩的开心的！");
        return 1;
}    
