#include <ansi.h>
inherit NPC; 
void special_smart_fight(); 
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("long", "这孩子生得眉目清秀，但却面黄肌瘦，像是发育不全的模样，看神气
像是十五六岁。他缩着脖子，驼着背，一双眼睛，却又不时偷偷在你
胸前瞟来瞟去。\n"); 
        set("age",16);
//      set("attitude", "aggressive");
        
        set("combat_exp", 5500000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 1500);
        set("atman", 1500);
        set("max_mana", 1500);
        set("mana", 1500);
        set("max_neili",3000);
        set("neili",3000);
        set("force_factor",60);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        

        set_name("江玉郎",({"jiang yulang"}));
   setup();
        
        carry_object(__DIR__"obj/g_armor")->wear();
} 
void special_smart_fight(){
        
        object ob, room;
        
        ob=this_object();
        if (ob->query("qi")<ob->query("max_qi")/3
                || ob->query("jing")<ob->query("max_jing")/3
                || ob->query("jing")<ob->query("max_jing")/3) {
                message_vision("$N说：“英雄。。。饶命啊。。。“\n",ob);
                message_vision("$N向南落荒而逃了。\n",ob);
                ob->remove_all_killer();
                room=find_object("/d/eren/eren2/innerroom");
                if(!objectp(room)) 
                        room = load_object("/d/eren/eren2/innerroom"); 
                ob->move(room);
        }
        
}       
            
