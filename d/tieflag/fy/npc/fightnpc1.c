#include <ansi.h>
inherit NPC;
void auto_smart_fight();
void ask_help();
void auto_npc_setup(string name, int basic, int special, int self_weapon, string weapon_dir, string char_type, string my_char); 
void create()
{ 
         set_name("С��",({"fighter"}));
        set("title",YEL"̽��¥"NOR);
        set("long", "����̽��¥�������ÿ��˵Ļ���\n");        
            set("str",30);
        set("force_factor",90);
        set("age",10+random(10)); 
        set("combat_exp", 1000000);
        set("dungeon_npc","test");
                
        set("max_atman", 500);
        set("atman", 500);
        set("max_mana", 500);
        set("mana", 500);
        set("max_neili",800);
        set("neili",800);
        set("force_factor",60);
        set("no_fly",1);
        
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
