//modified from pingding/npc/yao1.c 
// created by smile 12/10/1998

inherit NPC;

void create()
{
  object me=this_object();
  int i = random(9)+10;
  string str;
  set_name("���ñ�", ({"kulou bing","bing"}));
  set("gender", "����");
  set("age", 30);
  set("combat_exp", 25000*i);
  set("attitude","aggressive");
  set("per", 8);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("staff", 10*i);
  set_skill("club", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("staff", 10*i);
  set_skill("staff", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_jing",1000*i);
  set("max_qi",1000*i);
  set("max_jing",1000*i);
  set("neili",1000*i);
  set("max_neili",1000*i);
  set("max_neili",1000*i);
  set("force_factor",10*i);
  set("chat_chance",10);
  set("chat_msg",({
       "���ñ��ݺݵ�˵���ұ��˳��˲ű�������ģ���ҲҪ�Ա��ˣ�\n",
       "���ñ��е���������ԩ������\n",
       "���ñ����ĵ�̾��һ����������ʲôʱ������ػ�������\n",
       "���ñ��ٺ���Ц�����������������ȥ���ã�\n",
  }));

  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/baigudong/obj/armor")->wear();
  str = "/d/qujing/baigudong/obj/weapon0";
  str[strlen(str)-1] = '0'+random(10);
  carry_object(str)->wield();
}
