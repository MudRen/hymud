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

	set("combat_exp", 9500000);
	set("score", 400000);
	set_skill("art", 380);
	set_skill("goplaying", 380);
	set_skill("taxue-wuhen", 380);
	set_skill("luteplaying", 380);
        set_skill("literate", 300);
	set_skill("force", 250);
	set_skill("xuantian-wuji", 380);
	set_skill("dodge", 280);
	set_skill("kunlun-shenfa", 380);
	set_skill("strike", 380);
	set_skill("kunlun-zhang", 380);
set_skill("mantian-huayu", 380);
set_skill("qixian-jian", 380);
	set_skill("chuanyun-tui", 380);
	set_skill("zhentian-quan", 380);
	set_skill("parry", 250);
	set_skill("sword", 300);
        set_skill("cuff", 250);
	set_skill("leg", 250);

        set_skill("finger", 280);
	set_skill("hand", 250);
set_skill("qidao", 380);
set_skill("music", 380);

	set_skill("liangyi-jian", 380);
	set_skill("throwing", 380);
	set_skill("taiji-shengong", 180);
	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("strike", "kunlun-zhang");
	map_skill("parry", "qixian-jian");
	map_skill("parry", "art");
	map_skill("sword", "qixian-jian");
	//prepare_skill("strike", "kunlun-zhang");
	
	map_skill("finger", "qidao");
	map_skill("hand", "music");
	prepare_skill("finger", "qidao");
	prepare_skill("hand", "music");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "hand.gong" :),
                	(: perform_action, "hand.libie" :),
                 	(: perform_action, "hand.lv" :),
                (: perform_action, "finger.xb" :),                		
                (: perform_action, "strike.diezhang" :),
                	(: perform_action, "throwing.huayu" :),
                 	(: perform_action, "strike.liuyun" :),
                (: perform_action, "strike.yixing" :),                		
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.ni" :),
                (: perform_action, "sword.shan" :),
                (: perform_action, "sword.yin" :),
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),
                (: perform_action, "sword.zhu" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );

setup();

carry_object(__DIR__"loginload/skirt.c")->wear();
carry_object(__DIR__"loginload/shoes.c")->wear();
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

