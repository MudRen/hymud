#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("��ˮ�ĸ���",({"woman"}));
        set("long", "һ�����������ĸ��ˣ����ڷѾ�������Ƥ�ƴ���װˮ��\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 500000);
        set("gender","Ů��");
                
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����˵����Ҳ�����ˮ�ɣ����˹ؾͿ����ˡ�\n"
        }) );
                
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/guanwai/npc/obj/wineskin");
        carry_object(__DIR__"obj/bucket");
        
}    
