inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
        set_name("中年汉子", ({ "hou", "hou er"}) );
        set("gender", "男性" );
        set("age", 50);
        set("int", 25);
        set("per", 23);
        set("long",
                "一个身形瘦削的中年汉子。\n"
                );
        
         set("inquiry", ([
                "五大掌门": 
"他们是昆仑派卓腾，点苍谢长卿，崆峒厉鹗，峨嵋苦庵和武当赤阳，不过听说主谋只是其中三人，另两人还罪不致死。\n",
        ]));
                
        set("max_jing", 10000);
        set("max_sen", 10000);
        set("jing", 10000);
        set("sen", 10000);
        set("max_neili", 3000);
        set("neili", 3000);
        set("force_factor",120);
        set("combat_exp", 20000000);
    set("qi", 29000);
    set("max_qi", 29000);
    set("jing", 18000);
    set("max_jing", 18000);
    set("neili", 53500);
    set("max_neili", 53500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 9000000);
    set("score", 0);
	 
    set_skill("leg", 380);             // 基本内功
    set_skill("force", 280);             // 基本内功
    set_skill("bibo-shengong", 380);     // 碧波神功
    set_skill("claw", 200);              // 基本爪法
    set_skill("hand", 320);              // 基本手法
    set_skill("finger", 320);            // 基本指法
    set_skill("tanzhi-shentong", 380);   // 弹指神通
    set_skill("unarmed", 280);           // 基本拳脚
    set_skill("strike", 280);            // 基本拳脚
    set_skill("luoying-zhang", 380);     // 落英神剑掌
    set_skill("xuanfeng-leg", 380);      // 旋风扫叶腿
    set_skill("dodge", 280);             // 基本躲闪
    set_skill("anying-fuxiang", 380);    // 暗影浮香
    set_skill("parry", 200);             // 基本招架
    set_skill("sword", 320);             // 基本剑法
    set_skill("luoying-shenjian", 380);  // 落英神剑
    set_skill("yuxiao-jian", 380);       // 玉箫剑法
    set_skill("lanhua-shou", 380);       // 兰花拂穴手
    set_skill("qimen-wuxing",380);       // 奇门五行
    set_skill("count",380);              // 阴阳八卦
    set_skill("literate",380);           // 读书识字
	  set_skill("chixin-jian", 380);             // 基本内功
    set_skill("canglang-bian", 380);             // 基本内功
    set_skill("whip", 380);             // 基本内功
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("whip"   , "canglang-bian");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "chixin-jian");
    map_skill("parry"  , "luoying-zhang");    	

if (random(3)==0)
{
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");
}
else
{
	prepare_skill("finger", "tanzhi-shentong");
	prepare_skill("hand", "lanhua-shou");	
}
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "qimenzhen" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
		(: command("unwield yuxiao") :),
		(: command("wield yuxiao") :),
		(: command("unwield bian") :),
(: command("wield bian") :),
(: perform_action, "finger.ding" :), 
	(: perform_action, "finger.zhuan" :), 
(: perform_action, "sword.muyu" :),                
	(: perform_action, "sword.nosword" :),                
		(: perform_action, "sword.trhy" :),                
		(: perform_action, "whip.duoming" :),                
		(: perform_action, "whip.lang" :),                
		(: perform_action, "whip.tlyj" :),                
		(: perform_action, "whip.yljx" :),                									
 
        }));

        
        
        set("chat_chance", 1);
        set("chat_msg", ({
        
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield(); 
} 
void init(){
        object ob;
        
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
    }
} 
void greeting(object ob){
        message_vision("$N打量了$n一下，脸上丝毫没有任何表情。\n", this_object(), ob);
        if(ob->query("marks/梅山民")) {
        if(ob->query("m_killer/厉鹗") && ob->query("m_killer/赤阳道长")
                && ob->query("m_killer/苦庵上人") && ob->query("marks/谢长卿"))
                tell_object(ob, "你听一个微小的声音说道：“去书房，推开花纹砖（ｐｕｓｈ　ｓｔｏｎｅ）向下，你可以学
到无敌的功夫。\n");             
}
}           