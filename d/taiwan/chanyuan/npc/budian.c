
inherit NPC;

#include <ansi.h>


string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
   set_name("����",({ "bu dian","bu","dian"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ�ĸ�ɮ��\n");
   set("class","bonze"); 
   set("combat_exp", 200000);
   set("str", 28);
   set("attitude", "peaceful");
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("staff",100);
   set_skill("force",100);
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
   
   create_family("������Ժ",5,"ɮ��");
   set("target_id","###");

   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();
  
}

