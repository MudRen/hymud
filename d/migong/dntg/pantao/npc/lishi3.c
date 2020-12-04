// by snowcat 5/29/1997

#include <ansi.h>

inherit NPC;

void create()
{
  set_name("ÐÞÌÒÁ¦Ê¿",({ "li shi", "shi" }) );
  set("gender", "ÄÐÐÔ" );
  set("long", "Ò»Î»×Ïç·½ðÕÂÜ½ÈØ¹ÚµÄ´óÁ¦Ê¿£¬ÎªÆß´óÁ¦Ê¿Ö®Ò»¡£\n");
  set("age", 100+random(100));
  set("attitude", "peaceful");
  set("str", 60);
  set("per", 60);
  set("combat_exp", 500000);
  set("daoxing", 200000);

  set("neili",600);
  set("max_neili",600);
  set("force_factor", 100);
  set("max_gin", 5000);
  set("max_qi", 5000);
  set("max_jing", 5000);
  set("max_mana", 5000);
  set("mana", 500);
  set("mana_factor", 20);
  set_skill("unarmed",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_skill("spear",100);
  set_skill("force",100);
  setup();
  carry_object(__DIR__"xianpao")->wear();
}
ÿ