 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("���ϸ���", ({ "old woman" }) );
        set("nickname",HIR "������" NOR);
        set("gender", "Ů��");
        set("age", 85);
        set("long",
"��������������Ԫ����ˣ���������Ȼ���ݲ��ϣ���˫Ŀȴ����ӥ��������
֮�䣬ɢ����һ����������Ĺ�ʣ������ľ���\n"
); 
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ϸ������������۹⿴���㣬��ֻ���ò���������\n",
        }) );
          
        set("attitude", "friendly");
        set("score", random(20000));
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 5);
        set("combat_exp", 4800000);        
        set("int", 30);
        set("cps", 40);
        set("spi", 30);
        set("fle",50);
        set("resistance/gin",40);
        set("resistance/kee",40);
        set("resistance/sen",40);
        
        set("neili", 1000);
        set("max_neili",1000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 800);
        set("max_mana", 800);
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );
         
        set_skill("dodge", 200);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic",150);     
        set_skill("throwing",200);            

	set("max_qi", 25000);
	set("max_jing", 23000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 100);
	set("combat_exp", 8000000);
	set("score", 600000);

		set_skill("zhuihun-biao", 380);
		set_skill("liuxing-biao", 380);
	set_skill("pili-biao",380);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 380);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 380);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 380);
	set_skill("parry", 280);
	set_skill("throwing", 380);
	set_skill("zimu-zhen", 380);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	

	set("class", "tangmen");

	set("chat_chance_combat", 98);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
                (: perform_action, "throwing.qizigangbiao" :),
                (: perform_action, "throwing.tanghua" :),
		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(5));
        carry_object(__DIR__"obj/b_stone")->wield();
        carry_object(__DIR__"obj/b_skirt")->wear();
        if (!random(5)) carry_object(__DIR__"obj/throwbook");
} 
 
smart_fight()
{
        int i;
        object *enemy, who;
   who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1) {
                who->perform_action("throwing.mantianhuayu");
                return;
        }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->is_busy()&& !who->is_busy()) {
                                this_object()->smart_attack();
                        }
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<3*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("throwing.tanzhijinghun");
} 
smart_attack() {
        this_object()->perform_action("throwing.mantianhuayu"); 
        }       
