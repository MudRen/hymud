// feng.c ������

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
	set("title", "��ɽ��ʮ�������ڳ���");
	set("long", 
"����ǵ������𽭺��Ļ�ɽ���޷�������������ۣ��������������ֽ��
����ݳ���ü���һֱ������һ�ɵ�����������ɫ����Ȼ�Ե���Ľ�������
֮��һֱ����������\n");
	set("gender", "����");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 130);
	set("int", 140);
	set("con", 130);
	set("dex", 130);
	
	set("qi", 359800);
	set("max_qi", 359800);
	set("jing", 358600);
	set("max_jing", 358600);
	set("neili", 354400);
	set("max_neili", 354400);
	set("jiali", 1300);

	set("combat_exp", 9050000);
	set("score", 200000);

	set_skill("cuff", 1200);
	set_skill("force", 1180);
	set_skill("blade", 1300);
	set_skill("dodge", 1180);
	set_skill("parry", 1000);
	set_skill("sword", 1320);
	set_skill("strike", 1200);
	set_skill("zixia-shengong", 980);
	set_skill("poyu-quan", 980);
	set_skill("fanliangyi-dao", 980);
	set_skill("huashan-sword", 980);
	set_skill("hunyuan-zhang", 980);
	set_skill("lonely-sword", 980);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 1200);
        set_skill("zhengqijue",300);
        
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("��ɽ��", 12, "����");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);

	setup();
    carry_object("/p/item/ritemtz3/wsword51")->wield();
    carry_object("/p/item/ritemtz3/ahands29")->wear();
}

