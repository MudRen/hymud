 // hu.c
inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name(HIW"白衣人"NOR, ({ "whitecloth man", "man" }) );
        set("gender", "男性" );
        set("age", 32);
        set("str", 30);
        set("int", 20);
        set("cor", 40); 
    set("long",
"清清爽爽的一身白衣裳，文文雅雅的一张笑脸，再加上秋星明月般的一对笑
眼，笑眼中还仿佛不时有白云飘过，悠悠远远的那么样一朵白云。 
\n"
    );
    set("max_jing", 6000);
    set("max_qi", 6000);
    set("max_sen", 6000);
        set("max_neili", 10000);
        set("force_factor", 100);
        set("combat_exp", 5000000+random(3000000));
        set("attitude", "friendly");
        set("str", 200);
     set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
      
        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
                setup();
        carry_object("/clone/misc/cloth")->wear();
}     
