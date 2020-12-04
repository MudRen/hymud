// ÏÄÖµ¹¦²Ü
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("ÔÂÖµ¹¦²Ü", ({ "yuezhi gongcao", "yue", "month",
"gongcao" }) );
        set("gender", "ÄÐÐÔ" );
        set("long","
ËÄÖµ¹¦²ÜÄËÊÇÍÐËþÀîÌìÍõÕÊÇ°ÃÍ½«¡£Òò¾­Ñé²»×ã¶ø
³öÕ½Ê§Àû£¬±»·£ÎªÑ²Âß¹Ù¡£ËÄÈËÒòÎªÖ¾Í¬µÀºÏ½áÎª
½ðÀ¼ÐÖµÜ¡£ÔÂÖµ¹¦²ÜÅÅÐÐÀÏ¶þ¡£Ëû³öÊ¦ÔÂ¹¬£¬Ò»ÊÖ
Áé»îµÄÑ©É½½£·¨£¬ÇÒÔÚ°Ù»¨ÕÆÉÏÓÐ¼«ÉîµÄÔìÖ¼¡£\n"
        );
        set("age",38);
        set("str",20);
        set("int",30);
        set("max_qi",1050);
        set("qi",1050);
        set("max_jing",900);
        set("jing",900);
        set("combat_exp",550000);
        set("daoxing",550000);
        set("neili",1500);
        set("max_neili",900);
        set("mana",1450);
        set("max_mana",850);
        set("force_factor", 60);
        set("mana_factor", 50);

        set("eff_dx", 200000);
        set("nkgain", 340);

   	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");


	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

        set("inquiry", ([
                "name" : "ÔÚÏÂ¾ÍÊÇÔÂÖµ¹¦²Ü£¬ÄËÍÐËþÌìÍõÕÊÇ°´ó½«¡£",
                "here" : "ÕâÀï¾ÍÊÇÌì¹¬¡£ÏÂ¹Ù·îÌìÍõ½«Áî£¬ÔÚ´ËÑ²²é¡£",
        ]) );
        setup();
        carry_object(__DIR__"obj/qingfeng")->wield();
        carry_object(__DIR__"obj/yinjia")->wear();
}
ÿ
