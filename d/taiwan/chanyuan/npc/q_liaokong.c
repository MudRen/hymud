
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("ľ��",({ "mu ren","ren"}));
        set("gender", "����" );
     
   set("class","bonze"); 
   set("combat_exp",1000000);
   
    set_skill("dodge",200);
    set_skill("parry",200);
    set_skill("force",200);
    set_skill("staff",200);
    set_skill("cuff",200);
    set_skill("finger",200);
    set_skill("strike",200);


    set_skill("literate",200);


    set("max_jing",3000);
    set("max_qi",3000);
    set("max_jingli",3000);
    set("max_neili",3000);
    set("neili",3000);

   setup();
  
}

string no_color(string arg)
{
        arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}


