#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;  
int kill_him(); 
void create()
{ 
        set_name("Ѧ��",({"xuebin"}));
        set("title",YEL"�ú�ׯ��ׯ��"NOR);
        set("long", "Ѧ��̧������ס�죬����ؿ����ţ��������������ϣ���Ȼ��ֻ�����Ǹ���������
���⣬�������о��У�ȴ������Ϧ�������Լ�ȴ��Ϧ�����޺õ�ʱ�ⶼ�ѹ�ȥ����
�������ѵ�����ҹ����\n");
        set("age",59);
        set("combat_exp", 5500000);
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
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//         defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        

        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
int kill_him()
{
        object me, another;
        
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"Ѧ������û�ջش��㡣\n");
                return 1;
                }
        message_vision(CYN"$N�������Ǵ����������£���Ȼ�����������䣬���������ص�ʮ����ǰ����
���ǻ���ͬ�����ġ���������Ϊ������ʵ�ڲ��Ǹ���������\n",this_object());
        return 1;
}     
