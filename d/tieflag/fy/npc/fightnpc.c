#include <ansi.h>
inherit NPC;
void auto_smart_fight();
void ask_help();
void auto_npc_setup(string name, int basic, int special, int self_weapon, string weapon_dir, string char_type, string my_char); 
void create()
{
        set_name(HIY"��絶"NOR,({"guardian"}));
        set("title",YEL"���˿�����"NOR);
        set("long", "����һλ���˿�ר�ŵ���Ѳ��֮��ĵ��ӡ�\n");
        set("age",30+random(20)); 
        set("combat_exp", 5500000);
        set("dungeon_npc","test");
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",60);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        

        setup();
        
   carry_object("/clone/misc/cloth")->wear();
}  
 
void die(){
        object *inv, ob;
        int i;
        message_vision(HIR"\n$N�ҽ�һ��������ȥ������һ��������ʧ�ˡ�\n"NOR,this_object());     
        destruct(this_object());        
}     

