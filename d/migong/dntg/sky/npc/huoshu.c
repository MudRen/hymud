//created by vikee
//2000.10

#include <ansi.h>

inherit NPC;

void create()
{
   set_name("����", ({ "huo shu","shu","rat" }) );
   set("race", "Ұ��");
   set("age", 500);
   set("long", "̫���Ͼ��Ļ����֮����.\n");
   
   set("str", 40);
   set("per", 400);
   set("cor", 26);   
   set("combat_exp",1355000);
   set("daoheng",955000);
   set("max_neili",1550);
   set("neili",2000);
   set("max_mana",1800);
   set("mana",2000);
   set("max_qi",1600);
   set("max_jing",1800);
   set("attitude", "aggressive");
   set_skill("dodge",140);
   set_skill("dragon",340);
   set_skill("dragon",380);
   set_skill("unarmed",380);
   set_skill("spells",150);
   
   
   map_skill("unarmed","dragon");
   map_skill("parry","dragon");
   map_skill("dodge","dragon");
   set("limbs", ({ "ͷ��", "����", "��", "β��",}) );
   set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
(: perform_action, "unarmed.tuwu" :),               
    (: perform_action, "unarmed.penhuo" :),               
    (: perform_action, "unarmed.yaoyao" :),

 }) );


   setup();
}

void die()
{
            if( environment() ) 
        message("sound", ""HIY"������ʧ�ڻ��֮�С�"NOR"\n", environment());        
                destruct(this_object());
}


