//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("����",({"star lady","lady","star"}));
  set("gender", "Ů��");
  set("title", "�����ǹ�");
  set("age", 25);

  set("attitude", "heroism");
  set("class", "bonze");
  set("combat_exp", 2352571);
  set("daoxing", 2352571);
  set("qi", 1141);
  set("max_qi", 1141);
  set("jing", 2055);
  set("max_jing", 2055);
  set("neili", 6113);
  set("max_neili", 3057);
  set("mana", 8079);
  set("max_mana", 4040);
  set("force_factor", 153);
  set("mana_factor", 203);
  set("str", 20);
  set("per", 23);
set_skill("qixian-wuxingjian", 380);
set_skill("cuff", 300);
set_skill("cuff", 300);
set_skill("lingshe-quan", 380);
set_skill("zhaosheshu", 380);
set_skill("yangsheshu", 380);
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike",320);
	set_skill("hand",320);
	set_skill("training",380);
	set_skill("staff", 250);
	set_skill("hamagong", 380);
	set_skill("chanchu-bufa", 380);
	set_skill("shexing-diaoshou", 380);
	set_skill("lingshe-zhangfa", 380);
	set_skill("hamashengong", 380);
	set_skill("xiyu-tiezheng", 380);
set_skill("shentuo-zhang", 380);
	map_skill("strike", "hamagong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "xiyu-tiezheng");
	map_skill("parry", "hamagong");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shewu" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("zhaoshe") :),
                (: perform_action, "strike.hama" :),                
               (: perform_action, "strike.puji" :),                
	              (: perform_action, "strike.tui" :),                
		          (: perform_action, "strike.zhen " :),                
                (: perform_action, "hand.shewu" :),                
             
        }) );

setup();

carry_object(__DIR__"loginload/skirt.c")->wear();
carry_object(__DIR__"loginload/shoes.c")->wear();
carry_object(__DIR__"obj/staff")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="staff";
  string armor1_id="waist",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","�����");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","����ĺ");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name","��ˮ��");
}

