 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
    set_name("文士", ({ "wen shi", "zhen zhen"}) );
    set("gender", "男性" );
    set("age", 35);
    set("int", 30);
    set("per", 30);
    set("long",
        "他平卧在雪地上，面孔几乎没有一丝血色，像是刚从阴暗的坟
墓里走出来似的。鼻息间似乎已没有气息，不知道还有没有救。\n" 
        );
    set("max_jing", 3000);
    set("max_qi", 3000);
    set("max_sen", 3000);
    set("eff_jing", 30);
    set("eff_qi", 30);
    set("eff_sen", 30);
    set("jing", 3000);
    set("qi", 3000);
    set("sen", 3000);
    set("max_neili", 3000);
    set("neili", 3000); 
    set("combat_exp", 9999999);
    set_skill("unarmed", 100);
    set_skill("sword", 180);
    set_skill("force", 200);
    set_skill("move", 100);
    set_skill("literate", 100);
    set_skill("dodge", 100);
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
//              "风雪交加，文士仅穿着件单薄的文士衣衫，在寒风里不住地哆嗦着。\n", 
//              "看到你文士脸上泛出一丝笑意，那笑是亲切而温暖的。\n", 
        }) ); 
        set("cured", 0); 
        set("answered", 0);
    setup();
    carry_object("/clone/misc/cloth")->wear();
    
}
 
void init(){ 
        ::init();
        if(find_call_out("do_leave") == -1 && !query("cured")) {  
                call_out("do_leave", 120); 
        }  
        if(find_call_out("do_selfcure") == -1 && !query("cured")) { 
                call_out("do_selfcure", 30); 
        } 
} 
 
void do_selfcure(){ 
        if(query("cured")) { 
                return; 
        } 
        message_vision("$N的手臂缓缓地动了一下。\n", this_object()); 
        message_vision("$N努力地鼓着最后的精力，站立了起来。虽然站的不稳，但他是站立着的。\n", 
                        this_object()); 
        set("long",  
                "他人是那么的樵悴而衰弱，面孔几乎没有一丝血色，像是刚从阴暗的坟
墓里走出来似的，伫立在清晨抖峭的风和雪里，显那样地不稳定，
虽然他想挺直地站着，然而却像随时都会跌倒。 \n" 
   ); 
        set("cured", 1); 
} 
void do_leave(){ 
        message_vision("\n$N拖着沉重的步伐缓缓离去，雪地上留下一溜深深的足迹。\n", this_object()); 
        destruct(this_object()); 
} 
 
int Cured(object me){ 
        if(!query("cured")) { 
                message_vision("$N极为困难的挣扎着坐了起来，定定地望着$n道：“你知道我是谁吗。”  
（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ）\n",  
                                this_object(), me);      
                set("long",  
                "他人是那么的樵悴而衰弱，面孔几乎没有一丝血色，像是刚从阴暗的坟
墓里走出来似的，伫立在清晨抖峭的风和雪里，显那样地不稳定，
虽然他想挺直地站着，然而却像随时都会跌倒。 \n" 
                ); 
                add_action("do_answer", "answer"); 
                set("cured", 1); 
                remove_call_out("do_leave"); 
                call_out("do_leave", 60); 
        } 
} 
 
int do_answer(string arg) { 
        object me; 
        me = this_player(); 
        if(!arg || (arg != "yes" && arg != "no")) { 
                return 0; 
        } 
        if(query("answered")){ 
                return 0; 
        } 
        if(arg == "yes") { 
                message_vision("$N微微一笑道：“阁下就是七妙神君。”\n", me); 
                message_vision("$N道：“好！既然如此，阁下一定也知道到哪里找我。今日一别，它日必当重报。”\n", 
                                this_object()); 
                me->set("marks/梅山民", 1); 
                do_leave(); 
   } else if(arg == "no") { 
                message_vision("$N神色茫然地摇了摇头。\n", me); 
                if(me->query("title") == "普通百姓") { 
                        message_vision("$N注视着$n，笑容自嘴边漾开。$N说道：“你如愿跟随着我，可到where find me”\n", this_object(), me); 
                        me->set("marks/梅山民", 3); 
                        do_leave(); 
                } else { 
                        message_vision("$N道：“在下七妙神君，它日有缘定当重谢。”\n", this_object()); 
                        me->set("marks/梅山民", 2); 
                        do_leave(); 
                } 
        } 
        return 1; 
} 
     
