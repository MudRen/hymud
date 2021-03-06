 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("马秀真", ({ "ma xiuzhen","ma" }) );
        set("gender", "女性" );
        set("title", "峨嵋派 侠女" );
        set("nickname", HIC"三英四秀之"NOR );
        set("long",
"身材很高，细细长长的一双凤眼，在笑的时候仿佛也带着种逼人的杀气。\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("cps", 40);
        set("int", 50);
        set("per", 15);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 100000);
        
        set("force", 500);
        set("max_neili", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 10);
        set("inquiry",  ([
                "叶孤城" : "哼，什么一剑西来，天外飞仙，我看也不过如此，如果遇到我师傅他老人家，\n定叫他拱手让出天下第一剑的名头。\n",
                "master ye" : "哼，什么一剑西来，天外飞仙，我看也不过如此，如果遇到我师傅他老人家，\n定叫他拱手让出天下第一剑的名头。\n",
                  "西门吹雪" :" 这个冷血魔头，杀了我师兄苏少英，这血海深仇一定要报！\n",
                  "master ximen" : "这个冷血魔头，杀了我师兄苏少英，这血海深仇一定要报！\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "马秀真挑了挑丹凤眼，不屑道：白云岛也不过如此。\n",
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
        carry_object("/clone/weapon/changjian")->wield();
        add_money("gold",2);
        carry_object(__DIR__"obj/w_skirt1")->wear();
}   
