#include <ansi.h>
inherit NPC;
inherit F_MASTER; 
void create()
{
        set_name("���ɹ�", ({ "jiang xiangong", "jiang" }) );
        set("title", HIG "�׷�ͯ��"NOR);
        set("gender", "����" );
        set("age", 80);
        set("str", 30);
        set("per", 25);
        set("long", @LONG
��ͷ�Ļ�������˿�����������ȴ��Ӥ��һ��û��һ˿���ơ�
LONG
);
        set("combat_exp", 800000);
        set("attitude", "friendly");
    set("chat_chance", 1);
    set("chat_msg", ({
                "���ɹ��������ܵ�ͷ��������������ɽ��������\n",
                "���ɹ����ֹ�������֪�������ʲô�����챦�� \n",
    }) );
 //       set_skill("incarnation", 150);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("force", 50);
//        set_skill("celestial", 150);
//        set_skill("celestrike", 150);
//        map_skill("force", "celestial");
//        map_skill("unarmed", "celestrike");
        set("skill_public",1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
int accept_fight(object me)
{
        command("say �����˼����������Ķ��֣�");
        return 0;
} 
int recognize_apprentice(object ob)
{
    if(ob->query("free_learn/incarnation"))
        return 1;
        return 0;
} 
int accept_object(object who, object ob)
{ 
        if (ob->name() == HIY"����"NOR){
                message_vision("$N����"+ ob->name() + "��ϸ���˿��������ã��ã�����������\n",this_object());
                message_vision("$Nתͷ���˿�$n�����Ϸ�����Ϊ�����������������ѧ��������\n", this_object(), who);
                who->set("free_learn/incarnation", 1);
                return 1;
        }
        return 0;
}   
