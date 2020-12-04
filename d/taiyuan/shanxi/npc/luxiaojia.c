 inherit NPC;
//inherit F_MASTER;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("·С��", ({ "lu xiaojia", "lu" }) );
        set("gender", "����" );
    	set("age", 25);
    	set("title", "���п�" );
    	set("nickname", HIR"���⽭��"NOR );
        set("int", 35);
        set("per", 30);
        set("npc_difficulty",10); 
        set("organization/����","а");
        set("quest_npc",1);
        set("class","assassin");
        set("resistance/kee",60);
        set("resistance/gin",60);
        set("resistance/sen",60);
        set("long",
                "���Ǹ������ˣ�һ����ֵ������ˣ�����˫��ֵ��۾�������Ц��ʱ����˫�۾���
������ģ����������˵��۾���û����У�Ҳû�б��顣
\n"
                );
        set("max_gin", 300000);
        set("max_kee", 300000);
        set("max_sen", 300000);
        set("eff_gin", 300000);
        set("eff_kee", 300000);
        set("eff_sen", 300000);
        set("gin", 300000);
        set("kee", 300000);
        set("sen", 300000);
        set("max_force", 4000);
        set("force", 4000);
        set("force_factor", 100);
        set("cor",80);
        set("str",50);
        set("combat_exp", 80000000);
        set("score", 3000);
        set("agi",25);
        set("int",30);
        set("chat_chance",10);
                set("chat_msg",({
"·С������һ�Ż���������������Ȼ������Ż����䵽�Լ���������۾���
������̾�˿�������ʼ�����׽���\n",
"·С�Ѻ�ȻЦЦ ��˵������ɱ���Ǽ��ɾ�ʹ������顣��������һ�٣���˵����
��������ɱ��֮ǰ����һ��Ҫϴ���衣��\n",
        })      );
set("qi", 18000);
	set("max_qi", 18000);
	set("jing", 18000);
	set("max_jing", 18000);
	set("neili", 39000);
	set("max_neili", 39000);
	set("jiali", 100);

	set("combat_exp", 8500000);
	set("score", 200000);
	        set_skill("claw", 220);
        set_skill("throwing", 220);
        set_skill("goplaying", 100);
        set_skill("luteplaying", 100);
        
        set_skill("painting", 100);
        set_skill("medicine", 100);
        set_skill("construction", 100);
        set_skill("horticulture", 100);
        set_skill("dramaturgy", 100);

	set_skill("yangyanshu", 380);
	set_skill("force", 200);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",350);
	set_skill("strike", 250);
        set_skill("sword",250);
	set_skill("sword",200);
	set_skill("strike", 260);
	set_skill("sword", 260);
	set_skill("hand", 360);
	set_skill("qingyun-shou", 380);
	set_skill("panyang-zhang", 380);
	set_skill("liuyue-jian", 380);

	set_skill("wuzhan-mei",380);
	set_skill("zhemei-shou",380);
	set_skill("liuyang-zhang",380);
        set_skill("tianyu-qijian",380);
	set_skill("yueying-wubu",380);
	set_skill("bahuang-gong", 380);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                	(: exert_function, "shield" :),
                	(: exert_function, "dunzun" :),	
                (: perform_action, "sword.kuangwu" :),
                	(: perform_action, "sword.qing" :),
                		(: perform_action, "sword.ju" :),
               
                (: perform_action, "sword.san" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/lusword")->wield();
}   
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>175) {
                                if (this_object()->query_temp("weapon")){
                                command( "say �ÿ���Ӳ�������ҵģ�");
                                command("unwield all");
                                }
                        } else  command("wield all");
                        
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else this_object()->smart_attack();
                        
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.sharenruma");      
        }    
