inherit NPC;
void create()
{
   set_name("����",({"shu chi"}));
   set("gender","����");
   set("long","��ľ��Ĵ����,����������,������թ!\n");
   set("shen",-20000);
   set("combat_exp",70000);
   
set("age",39);
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);
        set("qi", 32000);
	set("max_qi", 32000);
	set("jing", 38000);
	set("max_jing", 38000);
	set("neili", 32000);
	set("max_neili", 32000);
	set("jiali", 200);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set("shen", 100000);
	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // �����ڹ�
	set_skill("huntian-qigong", 330);    // ��������
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 320);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("hand", 200);              // �����ַ�

	set_skill("blade", 180);             // ��������
	set_skill("liuhe-dao", 280);       // �������ϵ�
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 200);          // ����;˵
	set_skill("training", 200);          // Ԧ����
	set_skill("strike",285);  // �����Ʒ�

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // �򹷰���
	set_skill("suohou-gong", 380);        // �򹷰���
set_skill("chansi-shou", 380);        // �򹷰���
set_skill("claw", 380);        // �򹷰���
set_skill("hand", 380);        // �򹷰���	
set_skill("club", 380);        // �򹷰���		
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

   set("chat_chance",5);
   set("chat_msg",({
"����ٺ���Ц����:���̨�Ǹ�����,��[��]��λ�ó������ҵ�.\n",
"����������ϵĽ���,��Ѫɫ�����Ѿ�һ������.\n",
}));

   setup();
   add_money("silver",30);
carry_object(__DIR__"obj/tiejia")->wear();
carry_object(__DIR__"obj/jinqiang")->wield();
}
//void init()

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book594",1);
		


	::die();
}