// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/huxianfeng.c

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("���ȷ�", ({"hu xianfeng", "hu", "xianfeng"}));
	set("gender", "����" );
	set("age", 43);
	set("per", 112);//no rongmao description.
	set("str", 50);
		set("long", "�Ʒ�������µ�ǰ·�ȷ棬�ǻƷ��������������֡�\n���ո�ǿ�����¸ɾ����䣬����������ƨ��\n������Ʒ�ɽ������һ��֮������֮�ϡ�\n");

	set("class", "yaomo");
	set("combat_exp", 800000);
	set("attitude", "peaceful");
	set_skill("unarmed", 130);


	set("max_qi", 1200);
	set("max_jing", 600);
	set("neili", 1600);
	set("max_neili", 800);
	set("neili", 800);
	set("max_neili", 400);	
	set("force_factor", 60);
	set("mana_factor", 20);

        set("eff_dx", -200000);
        

	setup();
	initlvl((200+random(200)),2);
	carry_object("/d/qujing/huangfeng/obj/hupi")->wear();
}
void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = new ("/d/qujing/huangfeng/obj/hupi");

  message_vision ("$N�ҽ����з����أ����̹�����ֻ����һ���ϻ�Ƥ��\n",me);
  ob->move(where);
  destruct(me);
}
