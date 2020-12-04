#include <ansi.h> 

inherit NPC;
inherit F_UNIQUE;

void create()
{
        set_name("������", ({ "wu liupo", "liupo", "wu"}));
        set("title", HIC "�������" NOR);
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 10000);
        set("max_jing", 5000);
        set("max_neili", 8000);
        set("neili", 8000);
        set("jiali", 50);

        set("combat_exp", 50000 + random(50000));

        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.baibu" :),
        }) );

        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("throwing", 120);
        set_skill("xuanyuan-arrow", 120);
        set_skill("changquan", 120);
        set_skill("lingxu-bu", 120);
        set_skill("force", 120);
        set_skill("hunyuan-yiqi", 120);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "lingxu-bu");
        map_skill("parry", "changquan");
        map_skill("throwing", "xuanyuan-arrow");
        map_skill("unarmed", "changquan");

        setup();

        carry_object("/clone/misc/cloth")->wear();

        set_temp("is_riding", BLK "ѩ����" NOR);

        
}
