//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("���",({"star erica","erica","star"}));
  set("gender", "Ů��");
  set("title", "Σ���ǹ�");
  set("age", 47);
  set("long", "    \nһ�ж��Ƕ��ݵ�û�н���ȴ��Ҫ��ʼ��\nһ���ֶ���������û��ֹͣȴҲ������ɡ�\nΪ�˷�����������������Ҳ��ֻ��ʧȥ������ʧȥ��Ҳֻ�ܻӻ���˵���ټ�ȴ��\n�޾��׵�˲�䣬��㾭���̻��Ÿе�һ��ͻ�������ı�����\n�κε�·��ѡ��ֻ����ζ��ѡ��������·�Ĳ��ٿ��ܡ�\n���ս��¶���\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1335792);
  set("daoxing", 1335792);
  set("qi", 1185);
  set("max_qi", 1185);
  set("jing", 1869);
  set("max_jing", 1869);
  set("neili", 5099);
  set("max_neili", 2550);
  set("mana", 7099);
  set("max_mana", 3550);
  set("force_factor", 115);
  set("mana_factor", 178);
  set("str", 21);
  set("per", 22);


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

carry_object(__DIR__"obj/skirt")->wear();
carry_object(__DIR__"obj/shoes")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="waist",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"��"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"��������"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"��������"NOR);
}

