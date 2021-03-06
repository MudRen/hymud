//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("寻欢",({"star sigh","sigh","star"}));
  set("gender", "男性");
  set("title", "奎木星官");
  set("age", 40);
  set("long", "    \n为期待而绝望 为绝望而期待\n绝望是最完美的期待\n期待是最漫长的绝望\n期待不一定开始\n绝望也未必结束\n或许召唤只有一声——\n最嘹亮的, 恰恰是寂静\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1016851);
  set("daoxing", 1016851);
  set("qi", 1217);
  set("max_qi", 1217);
  set("jing", 1892);
  set("max_jing", 1892);
  set("neili", 5099);
  set("max_neili", 2550);
  set("mana", 6639);
  set("max_mana", 3320);
  set("force_factor", 115);
  set("mana_factor", 167);
  set("str", 23);
  set("per", 15);


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
carry_object("/clone/misc/cloth")->wear();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","叶子");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"流云"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"秋风"NOR);
}

