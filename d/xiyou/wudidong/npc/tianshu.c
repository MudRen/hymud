// guanjia.c
// 9-2-97 pickle

inherit NPC;
#include "/d/migong/romnpc2.c"

string expell_me(object me);
void create()
{
  set_name("����", ({"tian shu", "tian", "shu", "tianshu", "monster"}));
  set("gender", "Ů��");
  set("age", 23);
  set("long",
"�������޵׶��Ĵ�ܼҡ��뵱����������һ�����ɳ������Σ�\n"
"��������̫��������վ����������չ��ŵ���Ľ��飬����\n"
"�����������ⶴ�Ĺܼҡ�\n");
  set("title", "��ܼ�");
  set("cor", 25);
  set("combat_exp", 200000);
  set("combat_exp", 33400000);

  set("attitude", "heroic");
  create_family("�ݿ�ɽ�޵׶�", 2, "����");
  set_skill("literate", 10);

  
  set("str", 30);
  set("per", 30);
  set("max_qi", 300);
  set("max_jing", 300);
  set("neili", 350);
  set("max_neili", 350);
  set("force_factor", 20);
  set("neili", 550);
  set("max_neili", 500);
  set("mana_factor", 25);
  set("inquiry", ([

		   "name": "������������޵׶��Ĵ��ܹܣ�",
		   "here": "��Ϲ��������������Ƕ����������ݿ�ɽ�޵׶���",
		   "rumors": "��֪�����ұ�����ȥ��",
		   "�������": "��Ϲ���������������ֲ��ǳ��ӣ�",
                 ]) );  
  setup();
  initlvl((550+random(550)),32);  
  carry_object("/d/obj/weapon/blade/blade.c")->wield();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
  carry_object("/d/obj/cloth/nichang")->wear();
}

