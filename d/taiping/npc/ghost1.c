#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("���ӹ�ĸ", ({ "guimu","���ӹ�ĸ","��ĸ","ghost" }) );
        set("long","�����Ŀ�Ĺ�ĸվ���ھŸ���״���죬��Ŀ�����Ĺ���֮�䡣\n");
        set("gender", "Ů��" );
        set("age",220);
        set("no_arrest",1);
        set("int",22);
        set("cor",30);
        set("per",1);
        set("dex",800);
        set("str",800);
        set("max_qi",50000); 
        set("max_jing",50000); 
        set("neili",50000);
        set("max_neili",50000); 
        set("cps",20); 
        set("combat_exp",9500000);  
        set("attitude", "friendly");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             
        }) );
        set("chat_chance",1);
        set("chat_msg",({ 
        }) );
        setup();    
        carry_object(__DIR__"obj/ghostcloth")->wear();
} 
int is_ghost() { return 1; }        
