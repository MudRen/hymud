inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("古波儿西", ({"guboer xi", "xi"}));
        set("long", "他是乱石山碧波潭的老鳖精。\n");
        set("age", 30);
	set("title", "殿前右使");
        set("attitude", "peaceful");
        set("gender", "男性");
	set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",500);
        set("max_jing", 500);
        set("combat_exp", 45000);
  set("combat_exp", 60000);

        set("eff_dx", 20000);
        set("nkgain", 250);


        setup();
        initlvl((500+random(500)),53);
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

�