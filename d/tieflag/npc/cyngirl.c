 // CYNGIRL.C
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(CYN"青衣少女"NOR, ({ "cyan girl","girl" }) );
        set("long", "她身穿轻纱柔丝，白足如霜，青丝飘扬。\n");
        set("age", 16);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("combat_exp", random(500000));  
        set("qi", 3000);
        set("eff_qi", 3000);
        set("max_qi", 3000);
        setup();
        armor=new(__DIR__"obj/corclot");
        armor->set_name(CYN"青衣"NOR,({"cyan cloth","cloth"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corclasp");
        armor->set_name(CYN"青镯"NOR,({"cyan bangle","bangle"}) );
        armor->move(this_object());
        armor->wear();  
        armor=new(__DIR__"obj/corgirt");
        armor->set_name(CYN"青带"NOR,({"cyan belt","belt"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corhat");
        armor->set_name(CYN"青帽"NOR,({"cyan hat","hat"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corboot");
        armor->set_name(CYN"青鞋"NOR,({"cyan boot","boot"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corribb");
        armor->set_name(CYN"青巾"NOR,({"cyan ribbon","ribbon"}) );
        armor->move(this_object());
        armor->wear();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
   mixed foo;
   object *inv;
   object dress; 
   int i; 
     if (random(victim->query("combat_exp"))<100000) 
        {  
           inv = all_inventory(victim);
           if (sizeof(inv)==0) return;
           for (i=0;i<sizeof(inv);i++){
             dress=inv[i];
             if ((string)dress->query("equipped")=="worn" ) break;
            }
           if ((string)dress->query("equipped")=="worn" )
           {
                                dress->unequip();
              victim->set_temp("mark/striped",1);     
              return victim->name()+YEL "身上的"+dress->name()+"被$N脱了下来。\n"NOR;
           } 
          }; 
            
           
        return;
}  
