//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("冤魂", ({ "yuan hun", "yuanhun" }));
        set("title", "蜀山前辈");
        set("race","人类");
        set("age", 99);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 40);
        set("cor", 40);
        
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("force", 3000);
        set("max_force", 2000);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 2000);
        set("mana_factor", 60);
        set("combat_exp", 500000);
        set("daoxing", 700000);

     
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();

}

void die()
{
        object me = this_player();
        object ob = new("/d/xiyou/shushan/obj/qxsword");
        ob->move(environment(me));

        if( environment() ) {
        message("sound", CYN"\n冤魂散了...", environment());
        message("sound", "\n一个神秘女孩出现在烟雾里...", environment());
        message("sound", "\n女孩道：“几十年了，父亲终于可以安息了，这把七星剑就送给你啦。”", environment());
        message("sound", "\n女孩说完消失在迷雾中...\n"NOR, environment());
        }
        destruct(this_object());
}