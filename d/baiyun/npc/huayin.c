 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����" , ({ "hua yin","hua" }) );
        set("nickname",HIR"������"NOR);
        set("long", "����Ů��ɫ��ȹ������ƮƮ���������ɣ��������������˫�������ػ�����\n�������衣\n");
        set("attitude", "friendly");
        set("per",60);
        set("age", 29);
        set("gender", "Ů��" );
        create_family("���Ƴ�",1, "��Ů");
        set("combat_exp", 2000000);
        set("chat_chance", 2);
        set("chat_msg", ({
        "������Ű�����˫�㣬������б���ڻ����У����ɵĴ��۾�͵͵�ش������㡣\n",
        "����ճ�����������ձ��ǽ���ʦ�ֵ��������û���ʲô�͸�����ʦ���أ�\n",
        }) );
    set_skill("dodge", 200);
        set_skill("parry", 120);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 130);
        set_skill("sword", 140);
        set_skill("unarmed",120);
        set_skill("changquan",120);
        set_skill("feixian-steps",140);
        set_skill("feixian-sword",140);
        set_skill("jingyiforce",60);
        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");
        map_skill("force", "jingyiforce");
        map_skill("parry", "feixian-sword");
        map_skill("unarmed", "changquan");  
                set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
