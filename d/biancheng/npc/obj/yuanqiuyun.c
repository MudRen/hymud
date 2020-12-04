#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
int kill_him(); 
int wieldsword();
void create()
{ 
        set_name("Ԭ����",({"yuan qiuyun","yuan","qiuyun"}));
        set("title",WHT"����ɽׯׯ��"NOR);
        set("long", "���˵�Ȼ���Ǹ����ˣ��Ǹ��������ǵ����ˡ�������Ҳ��������̬��ȴ����������
����������\n");
        set("age",59);
        set("combat_exp", 6400000);
        set("attitude", "friendly");
        
        set("inquiry", ([
             "������" : (: kill_him :),
        ]));
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",100); 
        set("str",100);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("reward_npc", 1);
        set("difficulty", 10);
        
        set_skill("move", 150);
        
        set_skill("parry", 180);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 180);
        set_skill("sword", 240);
        set_skill("unarmed",100);

        set_skill("feixian-steps",220);
        set_skill("feixian-sword",200);
        
        
        set_skill("magic",150);
        set_skill("painting",160);
        map_skill("magic","music");
        map_skill("literate","chess");
        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");
        map_skill("force", "painting");
        map_skill("parry", "calligraphy");
        map_skill("unarmed", "calligraphy");
        map_skill("move","feixian-steps"); 

        
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
                 (: wieldsword  :),

        }) );
         
        CHAR_D->setup_char(this_object());
       // auto_npc_setup("xuebin",250,180,1,"/obj/weapon/","fighter_w","taiji");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/loulan/obj/sword");
}  
int kill_him()
{
        object me, another;
        
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"Ԭ��������û�ջش��㡣\n");
                return 1;
                }
        message_vision("$N��Ц��ͻȻͣ�٣�Ŀ���к�Ȼ¶���־�֮ɫ��һ�����������ҲͻȻ���Ť
�����Σ�ʧɫ���������ǰס����״�����ʲô�ˣ���\n"NOR,this_object());
        message_vision("$N���ߡ���һ��������Ȼ���㣡��\n\nֻ��$N���б���һ��������������\n\n"NOR,me);
        message_vision("Ѫ������������������$NĿ����ɢ���������������ɫ��\n��������һ�仰�������졣�����ң����ڡ�����÷�����⡣������\n"NOR,this_object());
        me->set_temp("killed_yuan_ma",1);
        this_object()->die();
        return 1;
}
  
int wieldsword()
{
command("wield sword");
perform_action("dodge.tianwaifeixian");
command("unwield sword");
return 1;
}
