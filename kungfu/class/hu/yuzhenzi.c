//long.c
#include <ansi.h>
inherit NPC;

int ask_zhou();

void create()
{
        set_name("������", ( { "yu zhenzi", "yu" }) );
        set("title", HIR"�����Ű���"NOR);
        set("gender", "����" );
        set("age", 60);
        set("long",
              "ԭΪ�����ŵ��ӣ�����������;��ѧ��һЩа�ɵ��书������Ϊ��������\n��ʦ��ľɣ�����������δ�ս�����׻��ؾ�����֮�������Ϊ����צ����Ϊ����������\n"
        );

        set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);



     set("qi", 29800);
	set("max_qi", 29800);
	set("jing", 28600);
	set("max_jing", 28600);
	set("neili", 34400);
	set("max_neili", 34400);
	set("jiali", 200);

	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 300);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 300);
	set_skill("zixia-shengong", 300);
	set_skill("zixia-shengong", 300);
	set_skill("ziyunyin", 300);
	set_skill("zhengqijue", 300);
	set_skill("fanliangyi-dao", 300);
	set_skill("huashan-sword", 300);
	set_skill("hunyuan-zhang", 300);
	set_skill("lonely-sword", 300);
	set_skill("feiyan-huixiang",300);
	set_skill("literate", 200);
        set_skill("zhengqijue",300);
        set_skill("hunyuan-zhang", 300);
        set_skill("poyu-quan", 300);        
        set_skill("huashan-neigong", 300);        
        set_skill("chongling-jian", 300);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("������", 12, "����");

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

set("no_get",1);
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}


void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

who->set_temp("book134",1);
	::die();
}