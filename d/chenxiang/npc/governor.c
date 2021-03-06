 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int leave();
void create()
{
        set_name("卢定关", ({ "master lu", "master","lu" }) );
        set("long",
                "朝廷派驻在沉香的七品知县，进士出身，年轻有为，深得沉香百姓爱戴。\n");
        set("nickname", HIG"直宝章阁"NOR);
        set("attitude", "heroism");
            set("rank_nogen",1);
        create_family("朝廷命官",7,"大理评事 知沉香县");
 
    set("student_title","官员");
    set("ranks",({ "准备将","副将","正将","副统领","统领","御营副统制",
                       "御营统制","御营都统制","龙神卫四厢都指挥使","捧日天武四厢都指挥使",
                       "侍卫亲军步军都虞候","侍卫亲军马军都虞候","殿前都虞候",
                       "侍卫亲军步军副指挥使","侍卫亲军马军副指挥使","殿前副指挥使",
                       CYN"侍卫亲军步军都指挥使"NOR,CYN"侍卫亲军马军都指挥使"NOR,HIC"殿前都指挥使"NOR }));
    set("rank_levels",({ 32000,64000,128000,256000,384000,
                             512000,800000,1024000,1556000,
                             2048000,3652000,5000000,
                             6258000,8848000,10800000,
                             14580000,20048000,26244000 }));    
        set("inquiry", ([
                "leave": (: leave :),
        ]) );
    
        set("vendetta_mark", "authority");
        set("reward_npc", 1);
        set("difficulty", 5);
//        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 50);
/*        set("chat_msg_combat", ({
                (: perform_action, "" :),
        }) ); */
        set("combat_exp", 1000000);
        set_temp("apply/damage",500);
 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // 基本内功
	set_skill("huntian-qigong", 330);    // 混天气功
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 320);        // 逍遥游
	set_skill("parry", 150);             // 基本招架
	set_skill("hand", 200);              // 基本手法

	set_skill("blade", 180);             // 基本刀法
	set_skill("liuhe-dao", 280);       // 四象六合刀
	set_skill("begging", 200);           // 叫化绝活
	set_skill("checking", 200);          // 道听途说
	set_skill("training", 200);          // 驭兽术
	set_skill("strike",285);  // 基本掌法

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // 打狗棒法
	set_skill("suohou-gong", 380);        // 打狗棒法
set_skill("chansi-shou", 380);        // 打狗棒法
set_skill("claw", 380);        // 打狗棒法
set_skill("hand", 380);        // 打狗棒法	
set_skill("club", 380);        // 打狗棒法		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");


       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
        setup(); 
        carry_object(__DIR__"obj/guanfu")->wear();
} 

void init()
{       
        ::init();
        add_action("do_killing", "kill");
    
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "official"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N道：光天化日，朗朗乾坤，竟敢在衙门内狙杀朝廷官员，拿命来！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="official") return 0;
        message_vision(CYN"$N正色道，“报效朝廷乃忠君爱民之事，怎么能半途而废呢。“\n"NOR, this_object());
        message_vision(CYN"$N说：若执意要走我也不勉强，只是从此就是一介平民，朝廷之事再也无权过问。\n"NOR,this_object());
        message_vision(CYN"$N说：玉环鸳鸯拳也不能再使，慎思，慎思。\n"NOR,this_object());
   return 1;
}    
