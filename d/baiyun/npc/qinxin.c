 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("琴心" , ({ "qin xin","qin" }) );
    set("nickname",HIC"枕琴囊"NOR);
    set("long", "一个白衣女子席地而坐，膝上放着一张焦尾琴，正自弹奏。身周树木上停满了\n和琴声或一问一答，或齐声和唱。\n");
        set("attitude", "friendly");
    set("age", 22);
    set("per",40);
        set("gender", "女性" );
        create_family("白云城",1, "才女");
    set("combat_exp", 2500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "琴心轻拂膝上瑶琴，琴音和鸟语互相应答，间间关关，宛转啼鸣。\n",
        "琴心柳眉微蹙，琴声忽高忽低，忽轻忽响，“铮”的一声，一根「徵弦」忽然断了。\n",
        }) );
    set_skill("persuading", 550);
        set_skill("throwing", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("finger", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("sword", 250);
        set_skill("blade", 200);
        set_skill("literate", 100);
        set_skill("mahayana", 500);
        set_skill("buddhism", 250);
        set_skill("jinding-zhang", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("huifeng-jian", 300);
        set_skill("yanxing-dao", 300);
        set_skill("zhutian-bu", 300);
        set_skill("linji-zhuang", 250);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) );  
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}      
