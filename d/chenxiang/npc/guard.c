#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("���������", ({ "guard" }) );
        set("long",
                "����һλ������ר�ŵ��ο���֮��ĵ��ӡ�\n");
        set("attitude", "killer"); 
        set("str", 30);
        set("cor", 30);
        set("cps", 25);
        
        set("combat_exp", random(200000)+500000);
        set_skill("sword", 100+random(50));
        set_skill("parry", 70+random(50));
        set_skill("dodge", 70+random(50));
        set_skill("move", 100+random(50));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}   
