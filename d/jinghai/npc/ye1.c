// /d/jinghai/npc/ye1.c 

inherit NPC;
void create()
{
      set_name("Ұ��",({"wolf"}));
      set ("long","һֻ���Ż���ɫƤë����¶�׹���ǡ�\n");

      set ("race","Ұ��");
      set ("age",8);
      set ("cor",30);
      set ("con",30);
      set ("str",50);
      set ("max_sen",450);
      set ("max_qi",500);
      set ("max_jing",450);

      set("chat_chance", 10);
      set ("chat_msg",({
      "���������͵��۾�ֱ�����㡣\n",
      "���Ƿ���һ������ë����Ȼ���ƽС�\n",
      (: random_move :),
}));

      set_skill("unarmed",1);
      set_skill("dodge",1);
      set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
      set ("verbs",({"bite"}));
      set ("combat_exp",500000+random(100000));

      set("attitude", "killer");
      set_temp("apply/attack",30);
      set_temp("apply/defense",40);

      setup();
}

