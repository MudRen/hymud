#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "songzhong" }) );
        set("gender", "����");
        set("combat_exp", 100000);
        set("title", HIR "һ������"NOR);
        set("long",
                "���У���һ�����գ���Ҷ���Ϊ���ν��Ķ����Ѿ��ȵ��Ͼ�������\n"
        );
        set_skill("move", 50);
        set_skill("dodge", 50);
        set_skill("sword",50);
        set_skill("lefthand-sword",20);
        map_skill("sword","lefthand-sword");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
        (: perform_action, "sword.duxin" :),
            }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}
