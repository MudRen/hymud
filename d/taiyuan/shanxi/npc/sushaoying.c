//weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("����Ӣ", ({ "su shaoying","su" }) );
        set("gender", "����" );
        set("title", "������ ����" );
        set("nickname", HIM"��Ӣ����֮"NOR );
        set("long",
        "һ���Ǹ������ѵ��ˣ���û���ḯ����Ҳ���������鵱��Ȥ���Ǹ���ѧ�ľ��ˣ�\n�������������������ȴ�·���ᡣ\n"
                );
        set("attitude", "peaceful");
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 300000);
        
        set("neili", 500);
        set("max_neili", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 20);
        set_temp("apply/armor",150);
        set_temp("apply/attack", 50);
        set_temp("apply/damage", 9999);

        set("chat_chance", 5);
        set("chat_msg", ({
                "����Ӣ̸Ц����������˵���������ķ������¡�����\n",
                "����Ӣ��ͷ���������Ǹ������ˣ�����������ף���Ȼû�����ܱȵ��ϡ������� \n",
                }) ); 
set("qi", 39800);
	set("max_qi", 39800);
	set("jing", 38600);
	set("max_jing", 38600);
	set("neili", 54400);
	set("max_neili", 54400);
	set("jiali", 200);

	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
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
        setup(); 
        carry_object("/clone/weapon/gangjian")->wield();
        add_money("gold",1);
        carry_object("/clone/misc/cloth")->wear();
} 