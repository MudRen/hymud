// by snowcat 12/8/1997

inherit NPC;inherit F_DEALER;

void create()
{
  ("jinping_dian_zhu");
  set_name("����", ({"dian zhu", "zhu"}));
  set("shop_id", ({"dianzhu", "zhu"}));
  set("gender", "����");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/qujing/jinping/obj/hulu",
        "/d/qujing/jinping/obj/ji",
        "/d/qujing/jinping/obj/doufu",
        "/d/qujing/jinping/obj/mianjin",
        "/d/qujing/jinping/obj/gao",
        "/d/qujing/jinping/obj/bing",
        "/d/qujing/jinping/obj/guan",
      }));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

