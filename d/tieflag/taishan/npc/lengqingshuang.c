 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("����˪", ({ "leng qingshuang" }) );
        set("title",HIG "���㱤" NOR);
        set("gender", "Ů��");
        set("age", 28);
        set("long",
"һ���ֳ�������ɡ�İ���Ů�ӡ�\n"
);
        set("inquiry", ([
               
        ]) );
       
        set("chat_chance", 1);
        set("chat_msg", ({
                "����˪���ų���̾Ϣ�������ã��ѵ���Ҳ�����˴������µĵ��ӣ�
�ѵ���û�п�������ҵİ�������\n",
        }) );
       
        set("attitude", "friendly");
        set("score", 200);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 1);
        set("resistance/kee",20);
        
        set("combat_exp", 2000000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("per",50);
        set("str",26); 
        set("neili", 1000);
        set("max_neili",1000);
        set("force_factor", 80);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 300);
        set("max_mana", 300);
        
      	set("neili", 22400);
	set("max_neili", 22400);
	set("max_qi", 22000);
	set("max_jing", 21200);
	set("combat_exp", 8000000);
	set("shen_type", 1);

	set_skill("strike", 150);
	set_skill("kuaihuo-strike", 310);
	set_skill("sword", 350);
	set_skill("taishan-sword", 320);
	set_skill("shiba-pan", 320);
	set_skill("force", 150);
	set_skill("panshi-shengong", 350);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("fengshenjue", 310);
	set_skill("dramaturgy", 380);
	set_skill("horticulture", 380);
	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.heru" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
        
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(5));
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.yexuechuji");
}
