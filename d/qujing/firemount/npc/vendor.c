// rewritten by snowcat on 4/12/1997

inherit NPC;inherit F_DEALER;

void create()
{
  ("firemount_vendor");
  set_name("С��", ({"vendor"}));
  set("shop_id", ({"xiaofan", "vendor"}));
  set("gender", "����");
  set("age", 18);
  set("long","һλ�������ӣ�������һ���쳵����\n");
  set("attitude", "peaceful");
  set("combat_exp", 15000);
  set_skill("dodge", 30);
  set("vendor_goods", ({
         "/d/obj/food/watermelon",
         "/d/obj/food/kaoji",
         "/d/obj/food/putaogan",
         "/d/obj/food/hulu",
         "/d/obj/food/niupi-jiudai",
       }));
  set("chat_chance",40);
  set("chat_msg",({ 
        "�����ϣ�����\n",
        "������������\n",
        "�����Ѹɣ�����\n",
        "����«������\n",
        "���ƴ�������\n",
        (:random_move:)
      }));
  setup();

  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 500);

}

void init()
{
  object ob;

  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

