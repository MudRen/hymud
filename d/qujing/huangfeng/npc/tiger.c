//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
     set_name("����ͻ�", ({ "lao hu","tiger" }) );
   set("race", "Ұ��");
   set("age", 3);
   set("long", "���ǻƷ�ֵ�ǰ·�ȷ档\n");
   set("str", 32);
   set("max_qi",40000);
   set("max_jing",40000);
   set("jing",40000);
   set("qi",40000);
   set("dex", 36);

   set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
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
        message_vision(HIC"ֻ��$N�Ե��ڵأ���Ȼ�������Ρ�\n"NOR,ob);
        ob->set_name("ǰ·�ȷ�",({"xian feng","tiger"}));
        ::die();
}
