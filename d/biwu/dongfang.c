// dongfang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("��������", ({"dongfang bubai", "dongfang", "bubai"}));
    set("nickname", HIY "�����޵�" NOR );
    set("title", HIM"������̽���"NOR);
    set("gender", "����");
    set("shen_type", -1);
    set("age", 42);
    set("long",
        "������������̽������ų����˿ɵУ������һ�ƺ�Ϊ���������ܡ���\n");
    set("attitude", "peaceful");

    set("per", 121);
    set("str", 121);
    set("int", 130);
    set("con", 126);
    set("dex", 130);

    set("chat_chance", 1);
    set("chat_msg", ({
 "��������̾�˿����������� ���� �ҵ�����....����ô��������,�Һ�\n"
 "������ ������������������¶������ã��\n",
        }));
    set("inquiry", ([
        "����ͤ"   : "���ֱ���Ұ��˵�����,������ѽ�� \n",
        "��������" : "������ܰ���ȡ�ÿ��������ϲᣬ��һ������л�㡣\n",
    ]));

    set("qi", 356000);
    set("max_qi", 356000);
    set("jing", 351000);
    set("max_jing", 350000);
    set("neili", 358500);
    set("max_neili", 358500);
    set("jiali", 400);

    set("combat_exp", 19500000);
    set("score", 0);

    set_skill("force", 1250);             // �����ڹ�
    set_skill("finger", 1250);            // ����ָ��
    set_skill("unarmed", 1250);           // ����ȭ��
    set_skill("dodge", 1250);             // ��������
    set_skill("parry", 1250);             // �����м�
    set_skill("sword", 1250);             // ��������
    set_skill("pixie-jian", 1350);        // ��а����
    set_skill("changquan", 1350);         // ̫�泤ȭ
    set_skill("literate", 1300);          // ����ʶ��
    set_skill("kuihua-xinfa", 1350);      // �����ķ�
    set_skill("kuihua-dafa", 1350);      // ������
    set_skill("kuihua-feiying", 1350);      // ������
        
    map_skill("force", "kuihua-xinfa");
    map_skill("sword", "kuihua-dafa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "kuihua-feiying");
    map_skill("parry", "kuihua-dafa");
         set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
   create_family("�������", 2, "����");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tonggui" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: command("unwield zhen") :),
                (: command("unwield zhen") :),
                (: command("wield zhen") :),
                (: exert_function, "powerup" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "powerup" :),                
                (: exert_function, "roar" :),                
        }) );

    setup();
    carry_object("/p/item/ritemtz3/wsword28")->wield();
    carry_object("/p/item/ritemtz3/ahands39")->wear();
    carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();

}

