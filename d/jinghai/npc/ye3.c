// /d/jinghai/npc/ye3.c 

inherit NPC;
void create()
{
      set_name("�Ա�",({"lie bao","bao"}));
      set ("long","һֻ���Ż�ɫƤë����¶�׹��Ұ���ӡ�\n");

      set ("race","Ұ��");
      set ("age",8);
      set ("cor",30);
      set ("con",30);
      set ("str",50);
      set ("max_sen",550);
      set ("max_qi",600);
      set ("max_jing",550);

      set("chat_chance", 10);
      set ("chat_msg",({
      "�Ա����۾�ֱֱ�Ķ����㡣\n",
      "�Ա�����һ������ë����Ȼ���ƽС�\n",
      (: random_move :),
}));

      set_skill("unarmed",1);
      set_skill("dodge",1);
      set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
      set ("verbs",({"bite"}));
      set ("combat_exp",500000+random(100000));

      set("attitude", "killer");
      set_temp("apply/attack",80);
      set_temp("apply/defense",70);

      setup();
}

