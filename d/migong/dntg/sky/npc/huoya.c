//created by vikee
//2000.10

#include <ansi.h>
inherit NPC;

void create()
{
   set_name("��ѻ", ({ "huo ya","ya","huoya" }) );
   set("race", "Ұ��");
   set("age", 500);
   set("long", "̫���Ͼ��Ļ����֮��ѻ.\n");   
   set("str", 40);
   set("per", 400);
   set("cor", 26);   
   set("combat_exp",500000);
   set("daoxing",1500000);
   set("max_neili",800);
   set("neili",800);
   set("max_mana",2000);
   set("mana",2000);
   set("max_qi",800);
   set("max_jing",800);
   set("attitude", "aggressive");
   set_skill("dodge",140);
   set_skill("dragon",540);
   set_skill("dragon",580);
   set_skill("parry",180);
   set_skill("unarmed",180);
   map_skill("unarmed","dragon");
   map_skill("parry","dragon");
   map_skill("dodge","dragon");
   set("limbs", ({ "ͷ��", "����", "��צ", "β��","���"}) );   
   setup();
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
(: perform_action, "unarmed.tuwu" :),               
    (: perform_action, "unarmed.penhuo" :),               
    (: perform_action, "unarmed.yaoyao" :),

 }) );

}


void die()
{
            if( environment() ) 
        message("sound", ""HIY"��ѻ��ʧ�ڻ��֮�С�"NOR"\n", environment());        
                destruct(this_object());
}

