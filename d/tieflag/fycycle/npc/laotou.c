 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����ͷ", ({ "thin oldman","oldman" }) );
        set("gender", "����" );
        set("title", WHT"�������"NOR );
        set("age", 62);
        set("str", 15);
        set("cor", 14);
        set("per", 14);
        set("cps", 9);
       set("int", 5);
        set("long", "һ���ձ���������ͷ���뷢���ѻ��ף�������ȴʮ�ֹ������ڡ�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
     "����ͷ��������Ц��ô�����������ף�����δȢ�ޣ��ѵ��ұȲ��ã�\n",
                }) );
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set("max_neili", 500);
        set("neili", 500);
        set("force_factor", 10);
        set_skill("force", 60);
        set_skill("unarmed", 30);
        set_skill("dodge", 60);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        command("say �Ϸ�һ���Ϲ�ͷ����λ�������Ż��ҡ���\n");
        return 0;
}    