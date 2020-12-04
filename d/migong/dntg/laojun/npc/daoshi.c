//sgzl

inherit NPC;

void create()
{
  set_name("道士",({"dao shi","dao","shi"}));
  set("gender", "男性");
  set("age", 55);
  set("long", "    \n兜率宫里看守八卦炉的道士。\n");

  set("attitude", "peaceful");
  set("class", "taoist");
  set("combat_exp", 20000);
  set("daoxing", 40000);
  set("qi", 400);
  set("max_qi", 400);
  set("jing", 400);
  set("max_jing", 400);
  set("neili", 400);
  set("max_neili", 400);
  set("mana", 400);
  set("max_mana", 400);
  set("force_factor", 5);
  set("mana_factor", 10);



  set_skill("dodge", 60);
  set_skill("parry", 40);
  set_skill("unarmed", 30);


  set("inquiry", ([
  "here"   : "这里就是兜率宫，你来这里干什么？",
]));


setup();

carry_object(__DIR__"xianpao")->wear();

}
