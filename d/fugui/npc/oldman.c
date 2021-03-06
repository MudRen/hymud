#include <ansi.h>
inherit NPC;
void create()
{
        set_name("落魄老者", ({ "oldman" }) );
        set("long","一个神情落魄的老人家，从他身上可以了解到你的将来。\n");
        
        set("age", 76);
        set("cor", 50);
        set("cps", 25);
        set("agi",40);
        set("int",40);
        set("per",20);
        set("con",25);
        set("fle",25);
        set("tol",30);
        
        set("chat_chance",1);
        
        set("chat_msg", ({
            "落魄老者捋了捋长须叹道：富贵山庄的故事真是太多了．．．但现在\n还有谁要听呢？\n",
         "落魄老者心驰道：据说这一带本是昔年岳武穆幼年故乡，岳爷爷真是了不起，山上\n那一片密林据说就是岳爷爷参研正反五行而布下的奇阵。。\n",
                })); 
        
        set("combat_exp", 500000);
        set("max_atman", 1000);
        set("atman", 1000);
        
        set("max_neili",500);
        set("force",500); 
        set_skill("unarmed", 100);
        set_skill("taiji-quan",200);

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move",100);
        set_skill("taiji-quan",385);
        
        map_skill("unarmed","taiji-quan");

   

        
        
        set("inquiry",  ([
                "故事" : "当年富贵山庄第六代庄主王潜石未过世时，富贵山庄
当真是富贵繁华，甲于天下，可这自从这不争气的‘王不动’继承家
业后，哎，真是一败涂地，一塌糊涂，拜访的人少了，结果这吉祥镇
也跟着衰败了许多。弄得大家的日子都举步艰难。\n",
                "story" : "当年富贵山庄第六代庄主王潜石未过世时，富贵山庄
当真是富贵繁华，甲于天下，可这自从这不争气的‘王不动’继承家
业后，哎，真是一败涂地，一塌糊涂，拜访的人少了，结果这吉祥镇
也跟着衰败了许多。弄得大家的日子都举步艰难。\n",
        ])                      );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}  
