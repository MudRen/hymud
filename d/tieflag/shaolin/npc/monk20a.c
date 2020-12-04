 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�������", ({ "shaolin monk", "monk"}) );
        create_family("������", 20, "����");
        set("gender", "����" );
        set("class", "shaolin");
        set("age",random(20)+ 32);
        set("nickname",HIY"��ɮ"NOR);
        set("long", "���Ƕ����µĹ�ɮ��\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", 4000000);
        set("cps",80);
        set("attitude", "friendly");
        
        set_skill("staff", 150);
        set_skill("pudu-zhang",200);
        set_skill("move",200);
        set_skill("dodge",200);
        set_skill("force",200);
        set_skill("parry",200);
        set_skill("unarmed",200);
        set_skill("jingang-quan",200);
        map_skill("unarmed","jingang-quan");
        map_skill("staff", "pudu-zhang");
        map_skill("parry", "pudu-zhang");
        map_skill("dodge","shaolin-shenfa");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                name()+"Ц�����ڶ�������Ұ��\n",
                (: perform_action, "staff.hequhecong" :),
        }) );
        
        set("neili",1000);
        set("max_neili",1000);
   set("force_factor",40);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/sen",10);
        set("resistance/gin",10);
        set("resistance/kee",10);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"ͷһƫ�������˲��˯���ڵ��ϡ�\n",
                name()+"��ɫ��ׯ�����������дǡ�\n",
                name()+"˫��΢�գ��촽΢��������\n",
                name()+"ȫ�����һ��ʯͷһ����һ��������\n"
        }) );
        setup();
        carry_object(__DIR__"obj/monk20_cloth")->wear();
        carry_object(__DIR__"obj/stick")->wield();
}   
