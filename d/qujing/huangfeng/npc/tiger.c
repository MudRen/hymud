//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
     set_name("斑斓猛虎", ({ "lao hu","tiger" }) );
   set("race", "野兽");
   set("age", 3);
   set("long", "他是黄风怪的前路先锋。\n");
   set("str", 32);
   set("max_qi",40000);
   set("max_jing",40000);
   set("jing",40000);
   set("qi",40000);
   set("dex", 36);

   set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
   set("verbs", ({ "bite", "claw" }) );
   set_skill("unarmed",500);
   set_skill("parry",500);
   set("attitude","aggressive");
   set("combat_exp",600000);

   set_temp("apply/attack", 20);
   set_temp("apply/armor", 10);
   setup();
}

void die()
{
        object ob = this_object();
        message_vision(HIC"只见$N卧倒在地，居然显了人形。\n"NOR,ob);
        ob->set_name("前路先锋",({"xian feng","tiger"}));
        ::die();
}
