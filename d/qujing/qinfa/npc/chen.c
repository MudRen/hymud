// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("qinfa_chen_xiaoer");
  set_name("��С��", ({"chen xiaoer", "chen", "xiaoer", "xiao", "er"}));
  set("gender", "����");
  set("shop_id", ({"xiaoer", "xiao", "er"}));
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
    "/d/obj/food/rice",
    "/d/obj/food/salt",
  }));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init ()
{
  ::init();
add_action("do_buy", "buy");add_action("do_list", "list");
}
