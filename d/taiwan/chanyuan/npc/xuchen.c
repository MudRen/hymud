
inherit NPC;
inherit F_MASTER;

#include <ansi.h>


void create()
{
   set_name("虚尘",({ "xu chen","xu","chen"}));
        set("gender", "男性" );
        set("age",26);
   set("long", "这是净念禅院的高僧之一。\n");
   set("class","bonze"); 
   set("combat_exp", 100000);
   set("str", 28);
   set("per", 22);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("cuff",100);
   set_skill("force",100);
   
       set("force_factor",30); 
        set_skill("unarmed", 200);
        set_skill("dodge", 100);
		set_skill("move", 100);
        set_skill("staff", 200);
        set_skill("force", 180);
        set_skill("parry", 150);
        set_skill("literate", 140);
        set_skill("iron-cloth", 230);
        set_skill("bloodystrike", 150);
        set_skill("lamaism", 200);
        set_skill("jin-gang", 200);
        set_skill("spells",200);

        
        
        map_skill("unarmed", "bloodystrike");
        map_skill("iron-cloth", "jin-gang");
        
        set_temp("apply/iron-cloth",200); 
        
	set_skill("iron-cloth", 150);

	set_skill("bloodystrike", 300);
	set_skill("cloudstaff", 300);
	set_skill("bolomiduo", 300);
	set_skill("buddhism", 300);
        set_skill("jin-gang", 350);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);    
   
   set("jing",1000);
   set("max_jing",1000);
   set("qi",800);
   set("max_qi",800);
   set("sen",800);
   set("max_sen",800);
   set("neili",1000);
   set("max_neili",1000);
   

     
   create_family("净念禅院",7,"僧人");
   setup();
  
}

