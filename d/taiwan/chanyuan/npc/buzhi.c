#include <ansi.h>
inherit NPC;

string give_job();
int i=3;
void create()
{
   set_name("不智",({ "bu zhi","bu","zhi"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是静念禅院的得道高僧,他的佛经水平可是相当高的。\n");
   set("class","bonze"); 
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",80);
   set_skill("parry",90);
   set_skill("staff",90);
   set_skill("force",150);
   set_skill("blade",150);
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
    create_family("静念禅院",5,"僧人");
	set("inquiry",([

		"菩提本非树,明镜亦非台":"本来无一物,何处惹尘埃",
		"何名坐禅":"内见自性不动，名为禅",
		"何名禅定":"外禅内定，是为禅定",
		]));
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();
  
}

