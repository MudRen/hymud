#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
void auto_smart_fight();
object *resort_enemy(); 
void ask_help();
void magic_fight();
void do_defense(int n);
void do_remove_defense(int n);
void auto_npc_setup(string name, int basic, int special, int self_weapon, string weapon_dir, string char_type, string my_char); 
void create()
{ 
         set_name("���ܳ���beta����",({"fighter"}));
        set("title",YEL"̽��¥"NOR);
        set("long", "����̽��¥�������ÿ��˵Ļ�����һ����ȣ���Ѫ���٣��������ͣ�������
�������ӣ��ܹ���ս���и��������ͼ��ܣ��ܹ���ͬ�������ս��\n");
        set("str",45);
        set("force_factor",100);
        set("age",30+random(20));
        set("combat_exp", 5500000);
        set("dungeon_npc","test");
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000); 
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        
        
        set("no_fly",1);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi; 
        
        set("defense_type",random(4)+1);        
        set("zombie-killer",1);
   set("officer-killer",1); 
        setup();

        
        carry_object("/clone/misc/cloth")->wear();
} 
void die(){
        object book;
        int i;
        message_vision(HIR"\n$N�ҽ�һ��������ȥ������һ��������ʧ�ˡ�\n"NOR,this_object());     
        destruct(this_object());        
}     
