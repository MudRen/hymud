//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("����",({"star yixue","yixue","star"}));
  set("gender", "Ů��");
  set("title", "�����ǹ�");
  set("age", 43);
  set ("long", @LONG
��ѩ�������Ŵ�ʦ�� �������� -- ������
   ����׷׷��д���������������
��   
ϵ   ��ħ��--С���
��   ���Ľ�--�˼�����
ѩ   ���ǽ�--���Ǻ�����
��
   ѩԭççѩ��������ѩԭӳ����
LONG);

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1753250);
  set("daoxing", 1753250);
  set("qi", 1363);
  set("max_qi", 1363);
  set("jing", 2125);
  set("max_jing", 2125);
  set("neili", 6519);
  set("max_neili", 3260);
  set("mana", 8039);
  set("max_mana", 4020);
  set("force_factor", 150);
  set("mana_factor", 202);
  set("str", 21);
  set("per", 20);


     set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
set("count",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);


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
       my_weapon->set("name",HIB"�������˽�"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIC"���¹�ڣ��"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIW"����ѩ����"NOR);
}

