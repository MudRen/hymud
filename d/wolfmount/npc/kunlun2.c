#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("���ո�", ({ "wanyan gang" }) );
        set("gender", "����" );
        set("nickname", HIW"����ū"NOR);
        set("class","lama");
        set("age", 29);
        set("int", 30);
        set("agi",25);
        set("force",3000);
        set("max_neili",3000);
        set("long","��һ���ų߿���Ĵ󺺣����Ϻ��������ȫ�ޱ��飬����ϴ�������\n��Ľ𻷣�ͺ���������⡣��\n");
        set("combat_exp", 2000000);
        set_skill("unarmed", 150);
        set_skill("move", 200);
        set_skill("force", 100);
        set_skill("parry", 150);
        set_skill("iron-cloth", 150);
        set_skill("bloodystrike", 150);
        set_skill("bolomiduo", 100);
        set_skill("jin-gang", 150);
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        set("chat_chance", 1);
        set("chat_msg", ({
               (: perform_action,"iron-cloth.daoqiangburu"  :),
        }) ); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fefawubian" :),
                
        }) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}  
