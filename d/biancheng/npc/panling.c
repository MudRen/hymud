#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{ 
        set_name("潘伶",({"pan ling","pan"}));
        set("title",WHT"江湖五毒"NOR);
        set("long", "这人虽然衣袖又脏、又油、又腻，却有一只很好看的手，手指很长，也很干净。\n");
        set("age",39);
        set("gender","男性");
        set("combat_exp", 7000000);
         set("attitude", "aggressive");
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("class","assassin");

        set_skill("sword", 450);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("literate", 100);
        set_skill("dodge", 200);
        set_skill("sharen-sword", 180);
        map_skill("sword", "sharen-sword");
        map_skill("parry", "sharen-sword");
        set("reward_npc", 1);
        set("difficulty", 5);

        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: perform_action, "sword.sharenruma" :),

        }) );
         
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/biancheng/npc/obj/paper_2");
        carry_object("/d/loulan/npc/obj/sword2")->wield();
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        object another;
        message("vision",name() + "诡异地一笑，又成了那个老实的不能再老实的面馆老板。\n", 
                environment(),this_object() );
        another = new(__DIR__"bosszhang");
        another->move(environment(this_object()));
        destruct(this_object());
}  
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if(me->query("wanma/棺材之谜"))
                        me->set_temp("wanma/江湖五毒a",1);
        ::die();
}      
