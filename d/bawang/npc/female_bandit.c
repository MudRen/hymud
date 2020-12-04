#include <ansi.h>
inherit NPC; 
 
void create() 
{ 
    set_name("女土匪", ({ "female tufei" }) );
    set("nickname", HIM "绿林巾帼 不让须眉"NOR);
    set("title",  "饿虎寨 压寨夫人"NOR);
        set("gender", "女性"); 
    set("per", 5);
        set("age", 19); 
        set("long",      
                "恶虎岗自然也有女人，多是不爱红装爱刀枪。她们大都个个青春年少，\n身材健美。她们正在进行日光浴，一边朝你抛媚眼儿。\n"); 
        set("combat_exp", 11000); 
        set("score", 100); 
        set("attitude", "friendly"); 
     set_skill("strike",270);
        set_skill("finger",270);
        set_skill("dodge",280);
        set_skill("force", 270);
	set_skill("canhe-zhi", 300);
	set_skill("murong-jianfa",250);       
        set_skill("shenyuan-gong", 250);
	set_skill("yanling-shenfa", 250);   
	set_skill("xingyi-zhang",280);
        set_skill("douzhuan-xingyi", 280);
	set_skill("parry", 280);
	set_skill("sword", 260);
	set_skill("literate", 280);
        set_skill("murong-daofa", 280);
        set_skill("blade",260);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");
         map_skill("strike", "xingyi-zhang");
	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");
        

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                 (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.qixing" :),
 		(: command("unwield sword") :),
		(: command("wield sword") :),           
                (: perform_action, "dodge.yanling" :),                
                   (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
        }));
        set("chat_chance",1); 
        set("chat_msg","今天阳光真好......\n"); 
        setup(); 
        carry_object(__DIR__"obj/doudu")->wear(); 
        add_money("silver", 6); 
} 
