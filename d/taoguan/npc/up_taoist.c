 // tao_2.c
inherit NPC; 
void create()
{
        set_name("��ɽʹ��", ({ "taoist guard", "guard" }) );
        set("gender", "����");
        set("age", 32);
        set("long",
"��ɽʹ�������幬�Ļ�������һ���ɫ�ĵ��ۡ�\n"
);
        set("combat_exp", 50000);
        set("score", 200); 
        set("class", "taoist");
        set("fly_target",1); 
        set("jing",1400);
        set("max_jing",1400);
        set("eff_jing",1400);
        
        set("atman", 1200);
        set("max_atman", 1200); 
        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("pursuer", 1); 
        set("force", 150);
        set("max_neili", 150);
        set("force_factor", 5); 
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5); 
        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );

        create_family("���幬", 7, "����"); 
      set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30); 
        setup(); 
        add_money("coin", 30);
        carry_object(__DIR__"obj/sword1")->wield();
        carry_object(__DIR__"obj/tcloth")->wear();
} 
int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="���幬" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say ���幬���ͱ��ɵ��˹��С�");
        return 0;
}
  
int heal_up()
{
        if(environment() && !is_fighting() 
                && query("startroom") 
                && file_name(environment()) != query("startroom")) {
//         command("say ok");
                return_home(query("startroom"));
                return 1;
        }
        return ::heal_up() + 1;
}      
