#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{ 
        set_name("ʥ������",({"shengshou shusheng","shengshou","shusheng"}));
        set("title",WHT"�����嶾"NOR);
        set("long", "ʥ��������ʥ�ֲ��Ǿ�����ҽ��ʥ�֣�����Ⱦ���ƻ���Ů��Ѫ�֡�\n");
        set("age",29);
        set("gender","����");
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
            set("reward_npc", 1);
    set("difficulty", 10);
    
            set("resistance/gin",70);
    set("resistance/kee",70);
    set("resistance/sen",99);
    set("class","wudang");
    
    set_skill("unarmed", 220);
        set_skill("force", 200);
        set_skill("iron-cloth", 500);
        set_skill("yiqiforce", 10);

    map_skill("parry", "yiqiforce");
    map_skill("iron-cloth", "yiqiforce");
    map_skill("unarmed", "yiqiforce"); 
        
        set("no_fly",1);
        
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
   /*set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
 
            (: cast_spell, "jixing" :),
            (: perform_action, "sword.sancai" :),
             }) ); */

        
         
       /* CHAR_D->setup_char(this_object());
        auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
*/
        setup();
                
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/biancheng/npc/obj/paper_4");
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
        message("vision",name() + "�����һЦ���ֳ����Ǹ��������⣬����һ�Ѵ���ӵĺ��ƹ�\n", 
                environment(),this_object() );
        environment(this_object())->reset();
//      another = new(__DIR__"bosshu");
//      another->move(environment(this_object()));
        destruct(this_object());
}  
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if(me->query("wanma/�ײ�֮��"))
                        me->set_temp("wanma/�����嶾e",1);
        ::die();
}   
