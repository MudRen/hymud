#include <ansi.h>
inherit NPC;  
void create()
{
        set("long", "����һ�����̵����ˣ����Ǹ��ض��У��糾���͡�\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("dungeon_npc","eren");
                
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30);
        
        set_skill("unarmed", 200);
        set_skill("iron-cloth", 150);

        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����˵�������ɱ�������˲źá�\n"
                "����˵�����ǽ�Ӷ��У���ǿ���͸���ƴ����\n"
        }) );

        set_name("��Į����",({"traveler","desert traveler"}));
        set("force_factor",40);
        setup();
        add_money("silver", 50);
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/towel");
}  
