// by snowcat 12/8/1997         

inherit NPC;

string *names = ({
  "书院和尚",
  "客家和尚",
  "修行和尚",
  "大和尚",
  "胖和尚",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({"he shang"}));
  set("gender", "男性");
  set("combat_exp", 1000+random(50000));
  set("age", 40+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set("max_jing",300);
  set("max_qi",300);
  set("max_jing",300);
  set("max_neili",400);
  set("max_neili",400);
  set_skill("unarmed", 10+random(90));
  set_skill("dodge", 10+random(90));
  set_skill("parry", 10+random(90));
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
}

