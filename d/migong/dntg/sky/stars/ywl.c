//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("ҵ����ϵ",({"star ywl","ywl","star"}));
  set("gender", "����");
  set("title", "��ľ�ǹ�");
  set("age", 59);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1726225);
  set("daoxing", 1726225);
  set("qi", 1205);
  set("max_qi", 1205);
  set("jing", 2001);
  set("max_jing", 2001);
  set("neili", 5555);
  set("max_neili", 2778);
  set("mana", 7837);
  set("max_mana", 3919);
  set("force_factor", 145);
  set("mana_factor", 196);
  set("str", 30);
  set("per", 10);
	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );
  set("inquiry", ([
]));


setup();
carry_object("/clone/misc/cloth")->wear();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/ring")->wear();

}


void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="waist",armor2_id="ring";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"Ц��"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"����"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"��ʯ������"NOR);
}


