 inherit NPC;
#include <ansi.h> 
void create()
{
    set_name("����", ({ "statue","����"}) );
    
    set("str", 6000);
    set("resistance/gin",100);
    set("resistance/kee",100);
    set("resistance/sen",100);
    set("combat_exp", 10000000);
        
    set_skill("sword",400);
       
    set("no_shown",1);
    
    setup();
} 
int recognize_apprentice(object ob)
{
        if(ob->query_skill("sword",1)>=200)
                return 1;
        else 
                tell_object(ob,"��Ľ�����������޷���һ�����Ե�����ں���\n");
                return 0;
} 
void init(){
        add_action("do_look", "look");
        ::init();
} 
int do_look(string arg) {
        if(arg == "����ĵ���" || arg == "����" || arg == "statue"){
                write("һ������ĵ����ܵ���һ���轣�ĵ��ˡ�\n");
                return 1;
        }
        return 0;
}      
