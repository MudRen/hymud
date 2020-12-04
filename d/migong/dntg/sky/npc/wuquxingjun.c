//sgzl

inherit NPC;

void create()
{
  set_name("�����Ǿ�",({"wuqu xingjun","xingjun"}));
  set("gender", "����");
  set("age", 40);
  set("long", "    \n�칬�������Ǿ���\n");

  set("attitude", "peaceful");
  set("class", "xian");
  set("combat_exp", 9600000);
  set("daoxing", 800000);
  set("qi", 51400);
  set("max_qi", 51400);
  set("jing", 51600);
  set("max_jing", 51600);
  set("neili", 51500);
  set("max_neili", 51500);
  set("mana", 1600);
  set("max_mana", 1600);
  set("force_factor", 50);
  set("mana_factor", 40);
  set("str", 25);
  set("kar", 25);
	set_skill("cuff", 1250);
	set_skill("force", 1280);
	set_skill("blade", 1200);
	set_skill("dodge", 1180);
	set_skill("parry", 1200);
	set_skill("sword", 1380);
	set_skill("strike", 1250);
	set_skill("kuangfeng-jian", 1380);
	set_skill("zixia-shengong", 1380);
	set_skill("zixia-shengong", 1380);
	set_skill("ziyunyin", 1380);
	set_skill("zhengqijue", 1380);
	set_skill("fanliangyi-dao", 1380);
	set_skill("huashan-sword", 1380);
	set_skill("hunyuan-zhang", 1380);
	set_skill("lonely-sword", 1380);
	set_skill("feiyan-huixiang",1380);
	set_skill("literate", 1200);
        set_skill("zhengqijue",1380);
        set_skill("hunyuan-zhang", 1380);
        set_skill("poyu-quan", 1380);        
        set_skill("huashan-neigong", 1380);        
        set_skill("chongling-jian", 1380);
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


map_skill("sword", "xiaofeng-sword");
  set("inquiry", ([
  "name"   : "�����Ǿ���",
]));


setup();

	carry_object("/clone/weapon/changjian")->wield();
carry_object(__DIR__"obj/xianpao")->wear();

}
void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") )
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
if(wizardp(ob[i])) continue;
         if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        call_out("check",0);
        }
}