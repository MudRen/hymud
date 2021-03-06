#include <ansi.h>
inherit NPC;
int do_jie(string arg);
void create()
{
        set_name("金狮子", ({ "jin shizi", "jin" }) );
        set("long",
                "他狮鼻阔口，相貌丑陋。尤其是一只大鼻子，占了半张脸的地方，让\n人不觉得恐怖，只觉得可笑。\n");
        set("chat_chance",1);
        set("chat_msg", ({
                        "金狮子上上下下打量着你，粗声道：“别乱走，这些天大盗凤栖梧出\n没无常，小兔崽子还是回家乖乖呆着去。”\n",
                                })  ); 
        set("combat_exp", 300000);
        set("max_jing",1000);
        set("max_qi",1200);
        set("max_jing",900);
        set("max_neili",800);
        set("force",1500);
                
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // 基本内功
	set_skill("huntian-qigong", 380);    // 混天气功
	set_skill("unarmed", 260);           // 基本拳脚
	set_skill("xianglong-zhang", 380);   // 降龙十八掌
	set_skill("dodge", 260);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 380);        // 逍遥游
	set_skill("parry", 260);             // 基本招架
	set_skill("staff", 380);             // 基本棍杖
	set_skill("dagou-bang", 380);        // 打狗棒法
	set_skill("begging", 380);           // 叫化绝活
	set_skill("checking", 380);          // 道听途说
	set_skill("training", 380);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        setup(); 
        carry_object("/clone/misc/cloth")->wear();
} 
int do_jie(string arg){
        
        object ob, me, yaopai;
        me= this_player();
        
        if (arg == "gaoshi"&&  environment(this_object())->query("gaoshi")) {
                if (!ob=present("yao pai",me)) {
                        if (this_player()->query_temp("yaopai")) {
                           command("say 你的腰牌呢？丢了腰牌可是重罪！");
                                command("say 朝廷用人之际，我就再给你个机会吧。");
                                if (!yaopai=present("yao pai",this_object())) {
                                        yaopai = new(__DIR__"obj/yaopai");
                                        yaopai->move(this_object());
                                }
                                command("give yaopai to "+me->get_id());
                                return 1;
                        }
                                                                        
                        if( time()-(int) this_player()->query("marks/last_time_jiegaoshi") < 1200 ) {
                                command("say 你刚刚试过没多久，等会儿再来吧！");
                        } else if(present("jia gun", environment())) {
                                command("point jia gun");
                                command("say 你要证明你的实力，就和他过几招吧，你同意（ａｃｃｅｐｔ）吗？");
                                this_player()->set_temp("jiegaoshi",1);
                                this_player()->set("marks/last_time_jiegaoshi",time());
                        } else {
                                message_vision("$N对$n道：夹棍不在，你等会儿再来吧。\n", this_object(), this_player());
                        }
                } else if (this_player()->query_temp("yaopai")) 
                                command("say 不是已经给过你腰牌了吗？");        
                else 
                        command("say 这腰牌是哪里偷来的？快快从实招来，否则就把你抓牢里去！");
                return 1;
        
        }
        return 0;
} 
void die()
{
        object ob;
        object *enemy;
        ob = query_temp("last_damage_from");
        if(!ob) { 
                enemy = this_object()->query_enemy();
                if(sizeof(enemy))
                        ob=enemy[0];
        } else {
                if(userp(ob))   ob->set_temp("marks/killjin",1);
   }
        ::die(); 
}                                  
