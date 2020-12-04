 inherit NPC;
void create()
{
        set_name("金童", ({ "jin tong" }) );
        set("gender", "男性" );
        set("age", 14);
        set("long",
                "一个天真无邪，未懂世事的小金童\n");
        set("combat_exp", 900000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",150);
        set_skill("jingang-quan",120);
        set_skill("dodge",150);
        set_skill("wuxing-dun",150);
        map_skill("dodge","wuxing-dun");        
        map_skill("unarmed","jingang-quan");
        setup();
        carry_object(__DIR__"obj/yellow_cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
message_vision("$N看了$n一眼，然后捂住嘴开始＂吃吃＂的笑。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N盯了$n身上一眼，然后害羞地转过身，开始＂吃吃＂的笑。\n",this_object(),ob);
                        break;
                case 2:
                   command("snicker");
        }
}       
