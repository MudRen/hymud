inherit NPC;
void create()
{
   set_name("��",({"rui dong"}));
   set("gender","����");
   set("age",36);
   set("dex",100);
   set("nickname","�������ܹ�");
	set("shen_type",-1);
   set("combat_exp",3000000);
  set("max_qi", 25000);
	set("max_jing", 25000);
	set("neili",28000);
	set("max_neili", 28000);
set("str",100);
set("dex",100);
        set_skill("force", 480+random(180));

        set_skill("unarmed", 380+random(180));
        set_skill("blade", 380+random(180));
        set_skill("parry", 380+random(180));
        set_skill("dodge", 380+random(180));
        set_skill("kuang-blade", 320+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );
   set("inquiry",([
   "̫��":"��ҪΪ̫��������,Ҳ������ϧ.\n",
   "ΤС��":"��Ҳ��������С��.\n",
   ]));
  set("chat_chance",15);
  set("chat_msg",({
  "�𶰵�:�ⲿ[��ʮ���¾�]��̫��Ը�Ҫ��,�ɲ��ܶ���.\n",
  "�𶰵�:�������ִ̿�,��˵���˺ü�������.\n",
  "�𶰵�:���ϴ�,����̫���?�ǵ�Ȼ��̫�����.\n",
                (: random_move :),
  }));
   
   setup();
   add_money("silver",10);
  carry_object("/clone/weapon/gangdao")->wield();
  carry_object("d/city/npc/obj/tiejia")->wear();
  carry_object("d/city/npc/obj/toukui")->wear();
  carry_object("/d/city2/obj/book14_4");
  carry_object(__DIR__"obj/yaoshi");
}
