 inherit NPC;
void create()
{
        set_name("试验品", ({ "tester" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "一个为生活而终日奔波的小商人．\n");
          set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
}  
