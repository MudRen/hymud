// hu.c
inherit NPC;
#include <ansi.h>
//int wieldblade();
 
void create()
{
        set_name("简二", ({ "mr jian", "jian er" }) );
        set("gender", "男性" );
        set("age", 52);
        set("str", 30);
        set("str", 99);
        set("cor", 40);
        set("cps", 1);
        set("no_busy", 99);
                 set("reward_npc", 1);
        set("difficulty", 10);

        set("class","huashan");
            set("resistance/kee",99);
    set("resistance/sen",99);
    set("resistance/gin",99);

    set("long",
"一个满身酸气的穷秀才，背负着双手，施施然地度着步。 \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
        set_skill("move",100);
        set_skill("force",100);
        set_skill("unarmed",999);
        set_skill("dodge",99);
        set_skill("throwing",999);
        set_skill("ill-quan",999);
        set_skill("tanzhi-shentong",999);
        
        
        //set_skill("tangforce",100);
        //set_skill("blade",180);
        //set_skill("tang-blade",180);        

        //set("skill_public",1);

        map_skill("unarmed", "ill-quan");
        map_skill("parry", "tanzhi-shentong");
        //map_skill("force", "tangforce");
        set("chat_chance", 1);
        set("chat_msg", ({
                "穷秀才慢声长吟“如此星辰如此夜，为谁风露立中窗？”\n",
                //"青枫道人凄然而笑，“这一子摆下，黑棋就不输了。”\n",  
                //"青枫道人忽然挥袖拂乱了这局残棋，悠悠慨叹，“人生岂非，也正如一局棋．输瀛又何必太认真呢？”\n",
        }));
        //set("skill_public", 1);
        set("chat_chance_combat", 99);
        /*set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );*/
        setup();
           carry_object("/clone/misc/cloth")->wear();

        //carry_object("/d/huashan/npc/obj/chickbone")->wield();
        
} 
/*
int wieldblade()
{
command("wield piece");
perform_action("throwing.tanzhijinghun");
command("unwield piece");
return 1;
}*/
