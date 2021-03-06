#include <ansi.h>
inherit NPC;   
void create() 
{ 
        set_name("王一虎", ({ "wang yihu","yihu"}) );
        set("title", "饿虎寨 二当家" );
        set("nickname", HIY"大力金刚"NOR);
        set("gender", "男性");
        set("age", 33);
        set("long",
                "一条彪型大汉。顾名思义，此人力大无穷。手里提著把开山大斧，一\n条腿就比陈准整个人都重。\n" );
        set("combat_exp", 600000);
        set("score", 17000);
        set("cor",30);
        set("attitude","killer");
        set("bellicosity", 600); 
        set("max_neili", 1000);
        set("force", 1000);
        set("force_factor", 30); 
set_skill("force", 280);
	set_skill("guiyuan-tunafa", 380);
	set_skill("dodge", 300);
	set_skill("strike", 300);
	set_skill("hammer", 380);
	set_skill("axe", 380);
	set_skill("shuishangpiao", 380);
	set_skill("strike", 350);
	set_skill("tiezhang-zhangfa", 380);
	set_skill("parry", 200);
	set_skill("cuff", 300);
	set_skill("literate", 100);
	set_skill("tiexue-hammer",380);
	set_skill("duanyun-fu", 380);
	set_skill("tongbi-zhang", 380);
	set_skill("xuanyuan-axe", 380);
	set_skill("liumang-quan", 380);
		
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("cuff", "liumang-quan");
	map_skill("parry", "xuanyuan-axe");
	map_skill("axe", "xuanyuan-axe");
	prepare_skill("strike", "tiezhang-zhangfa");
	prepare_skill("cuff", "liumang-quan");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.pofuchenzhou" :),
                (: perform_action, "cuff.guguoshenyou" :),
                (: perform_action, "cuff.luori" :),
                (: perform_action, "axe.kaitianpidi" :),
                (: perform_action, "axe.sanbanfu" :),
                (: perform_action, "axe.jiuqipoxiao" :),
                (: perform_action, "axe.jiuqipoxiao" :),                	
                (: perform_action, "axe.jiuqipoxiao" :),                	                	
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bigaxe") :),
		(: command("wield bigaxe") :),			
        }) );
        setup(); 
        carry_object(__DIR__"obj/huge_axe")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();        
        add_money("gold", 1);
}   
void init() 
{ 
        object me;
        ::init();
        me = this_player();
   if(me && environment(me) == environment() && !me->is_fighting()) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}   
void greeting(object me) 
{
        if((string)me->name() !="老山东" ) 
        {
                command("say 来来来，让你看看老子的斧子有多快！\n");
                this_object()->kill_ob(me);
        }
        else
        {
                command("say 老山东，这次给老子带烧鸡了没有？\n");
        }
}       
