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
         set_name("���ܻ�¥����",({"fighter"}));
        set("title",YEL"̽��¥"NOR);
                set("long", "����̽��¥�������ÿ��˵Ļ�����һ����ȣ���Ѫ���٣��������ͣ�������
�������ӣ��ܹ���ս���и��������ͼ��ܣ��ܹ���ͬ�������ս��\n");
        set("str",40);
        set("force_factor",90);
        set("age",30+random(20)); 
        set("combat_exp", 3000000);
        set("dungeon_npc","test");
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",60);
        set("no_fly",1);
        
/*      set("resistance/gin",20);
        set("resistance/kee",20);
        set("resistance/sen",20);*/
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);


        setup();
       
        carry_object("/clone/misc/cloth")->wear();
}  

void die(){
        object book;
        int i;
        message_vision(HIR"\n$N�ҽ�һ��������ȥ������һ��������ʧ�ˡ�\n"NOR,this_object());     
        destruct(this_object());        
}      
