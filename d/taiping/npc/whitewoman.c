#include <ansi.h>
#include <command.h> 
inherit NPC; 
void create()
{ 
        set_name("���¸���",({"white cloth woman","woman"}));
        set("title",WHT"���ׯ"NOR);
        set("long", "���¸��˵�����Ѳ��ᣬȴӦ���Ǿ��ϻ� �������ѻ��ţ������̴档���ǵ����
Ҳ���񻣬�ܶ��ˡ�\n");
        set("age",40);
        set("combat_exp", 9000000);
        set("gender","Ů��");   
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set_skill("iron-cloth",150);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
   
         set("gender","Ů��");  
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
}       
