//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("����",({"star lovesky","lovesky","star"}));
  set("gender", "����");
  set("title", "��ˮ�ǹ�");
  set("age", 51);
  set("long", "    \n������,��ȡ����Ի:�����б�����ʦ֮��.\n");

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 1546018);
  set("daoxing", 1546018);
  set("qi", 1043);
  set("max_qi", 1043);
  set("jing", 1785);
  set("max_jing", 1785);
  set("neili", 3959);
  set("max_neili", 1980);
  set("mana", 7179);
  set("max_mana", 3590);
  set("force_factor", 98);
  set("mana_factor", 180);
  set("str", 31);
  set("per", 11);

       set_skill("lamaism", 250);
        set_skill("literate", 280);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("blade", 250);
        set_skill("sword", 220);
        set_skill("dodge", 280);
        set_skill("longxiang", 380);
        set_skill("shenkong-xing", 380);
        set_skill("hand", 280);
        set_skill("dashou-yin", 380);
        set_skill("mingwang-jian", 280);
        set_skill("xue-dao", 380);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );

setup();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"������"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"������"NOR);
}

