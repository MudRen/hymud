#include <ansi.h>
inherit NPC;
int wieldblade();
void create()
{
        set_name("é������", ({ "mr da" }) );
        set("gender", "����");
        set("age",35);
        set("combat_exp", 1000000);
        set("long",
                "һ���׷��ԲԵ����˶��ѣ�û��ʲô�ر�ĵط���\n"
        );
        set("max_neili",3000);
        set("str",40);
        set("neili",3000);
        set("force_factor",30);
        set_skill("move",100);
        set_skill("parry", 250);
        set_skill("sword",300);
        set_skill("dodge",1);
        set_skill("feixian-steps",250);
        map_skill("dodge","feixian-steps");
        set_skill("feixian-sword",120);
        map_skill("sword","feixian-sword");
        map_skill("parry","feixian-sword");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian");
}
int wieldblade()
{
command("wield sword");
perform_action("dodge.tianwaifeixian");
command("unwield sword");
return 1;
}       
