// ��ֵ����
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("��ֵ����", ({ "yuezhi gongcao", "yue", "month",
"gongcao" }) );
        set("gender", "����" );
        set("long","
��ֵ��������������������ǰ�ͽ������鲻���
��սʧ��������ΪѲ�߹١�������Ϊ־ͬ���Ͻ�Ϊ
�����ֵܡ���ֵ���������϶�������ʦ�¹���һ��
����ѩɽ���������ڰٻ������м������ּ��\n"
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
                "name" : "���¾�����ֵ���ܣ�������������ǰ�󽫡�",
                "here" : "��������칬���¹ٷ���������ڴ�Ѳ�顣",
        ]) );
        setup();
        carry_object(__DIR__"obj/qingfeng")->wield();
        carry_object(__DIR__"obj/yinjia")->wear();
}
�
