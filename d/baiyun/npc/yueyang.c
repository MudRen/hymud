#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����", ({ "yue yang", "yue" }) );
        set("long","����ͻ����ᣬ���Ӣ�������ϣ����ż��ְ������ִ��ż���Ұ����\n�۾��ڵ÷������������촽�Եúܼ�ǿ�����̡�\n");
        set("attitude", "heroism");
        set("title", "���뽭��");
        set("str", 18);
        set("per", 25);
        set("cor", 20);
        set("cps", 20); 
        set("combat_exp", 80000); 
        set_skill("unarmed", 100);

        set_skill("parry", 70+random(60));
        set_skill("dodge", 50+random(40));
        set_skill("move", 100+random(100));
        set_skill("force",100+random(100));

        set_temp("apply/attack", 10);
        set_temp("apply/dodge", 70);
        set_temp("apply/damage", 10);
        set("chat_chance", 1);
        set("chat_msg", ({
        "����������һ���޼ʵĴ󺣣��ս���ȭͷ��ĬĬ����һ��Ҫ���������ã�\n",
        }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
        (: perform_action, "spear.zonghengtianxia" :),
        }) ); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/egg");
        carry_object(__DIR__"obj/by_spear")->wield();
} 
