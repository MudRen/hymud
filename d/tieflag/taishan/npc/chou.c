#include <ansi.h>
inherit NPC;
int wieldblade();
void create()
{
        set_name("�������", ({ "mr er" }) );
        set("gender", "����");
        set("age",35);
        set("str",30);
        set("combat_exp", 600000);
        set("long",
                "��װ���ڣ����������������������԰׵������۽�������������˵�����İ�����
��������������һ���Ũü�䣬�ַ·�����˳�ޡ�\n"
        );
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",20);
        set_skill("move",100);
        set_skill("parry", 250);
        set_skill("sword",200);
        set_skill("dodge",1);
        set_skill("feixian-steps",150);
        map_skill("dodge","feixian-steps");
        set_skill("feixian-sword",100);
        map_skill("sword","feixian-sword");
        map_skill("parry","feixian-sword");
        set("chat_chance", 1);
/*        set("chat_msg", ({
        (: random_move :),
         }) );*/
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
