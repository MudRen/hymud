
inherit NPC;
void create()
{
  set_name("����", ({"dragon"}));
  set("gender", "����");
  set("long", "һ��������צ�Ķ���������ʮ�ֿ��¡�\n");
  set("attitude", "aggressive");
  set("combat_exp", 50000+random(1000000));
  set("combat_exp", 88500000);

  set("age", 100);
  set("per", 100);
  set("str", 30);
  set("int", 30);
  set("cor", 30);
  set("cps", 30);
  set("con", 30);
  set("max_qi", 500+random(1500));
   set("qi",180000);
	       set("eff_qi",180000);
	       set("max_qi",180000);
set("jing",180000);
  set("eff_jing",180000);
  set("max_jing",180000);
set("neili",189999);
  set("max_neili",189999);
  set("max_jing",189999);
  set("max_mana",189999);
  
      set("dex",80);
      set("con",80);
      set("int",80);
     set("str" ,80);
       set("no_get",1);
    set("age", 999);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 25000000);
            set_temp("apply/attack", 100);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",100);
      set_skill("dodge", 500);
      set_skill("force", 500);
      set_skill("unarmed", 500);
      set_skill("dragon",1850);
      set_skill("spells",1850);
     set_skill("magic-old",1800);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
    (: perform_action, "spells.magic1" :),
    (: perform_action, "spells.magic2" :),
    (: perform_action, "spells.magic3" :),
    (: perform_action, "spells.magic4" :),
    (: perform_action, "spells.magic5" :),
    (: perform_action, "spells.magic6" :),
    (: perform_action, "spells.magic7" :),
            	
 }) );


  setup();
}

void die()
{
    object rope;
    string rp="/d/qujing/pingding/obj/shengreal";

	rope = new(rp);
    if( environment() ) {
	message("vision", "һ�����������������ڵ��ϡ�����һ����ԭ�������Ѿ���ȥ������ֻ����һ��������\n", environment());
    }
    rope->move(environment(this_object()));
    destruct(this_object());
}
