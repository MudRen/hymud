 inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIG"����"+MAG"����"+HIG"��������"NOR, ({ "alien queen","queen" }) );
        set("gender", "Ů��" );
        
        set("age", 32);
        set("str", 25);
        set("dur",100);
        set("cor", 14);
        set("per", 4);
        set("cps", 29);
        set("int", 25);
        set("long", "���Թ����������ģ������������ѹ��\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "������������˵������һ�����ӣ�����һ�����ӡ�\n",               
                }) );   
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("max_neili", 500);
        set("neili", 500);
        set("force_factor", 10);

        set_skill("dodge",50);
        set_skill("move",50);
        set_skill("unarmed",50);
        set("skill_public",1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
