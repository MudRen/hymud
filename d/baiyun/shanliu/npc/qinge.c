 // qinge.c
inherit NPC; 
#include <ansi.h>
void create()
{
        set_name("�ظ�", ({ "qing ge", "qing"}) );
        set("gender", "����" );
        set("age", 25);
        set("title","ɽ�� ����");
        set("nickname",HIW "����"NOR);
        set("long",
"������ϵ��������˿���۾������й⣬�����þ��㲻̫Ӣ��Ư������ƾ������
�ɣ����㹻��Ů��һ�Ӷӵİݵ������ڶ��ӵĿ���¡�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "�ظ��ˬ�ش�Ц������Ҫ�ľͶĸ�ˬ�죬���򻹲���ؼұ�����ȥ��\n",
            "�ظ���ɫ����˭Ҫ����ɽ�����͵���ȫ�����Լ����͵�Ҫ���µ����ľ���
��������Ҳ�������ǣ�\n",
    }) );
        set("inquiry",  ([
                "ɽ��" : "��ĳ�˵���Ϊ��ɽ����ҵ�������ٱ���ǧ����������Ѫ��Ҳ�������ǣ�\n",
                "shanliu" : "��ĳ�˵���Ϊ��ɽ����ҵ�������ٱ���ǧ����������Ѫ��Ҳ�������ǣ�\n",
                "Ѫ��ϭ": "Ѫ��ϭ���˽Գư�һ���ĺڵ����ɣ�����С�ӡ�\n",
                "questnpc": "Ѫ��ϭ���˽Գư�һ���ĺڵ����ɣ�����С�ӡ�\n",
                "������": "���������������ټ��������۵�ƾ�ţ����ǵ��������ν����ʮָ��\n",
                "qinglong-ling": "���������������ټ��������۵�ƾ�ţ����ǵ��������ν����ʮָ��\n",
                ])                      ); 
        set("combat_exp", 33333333);
        set("attitude", "friendly");
        set("per",30);
        set("cor", 100);
        set("str", 100);
        set("force",1000);
        set("max_neili",2000);
        set("force_factor",50);
        set_skill("dodge",200);
        set_skill("iron-cloth",200);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/baiyun/shanliu/npc/obj/ribbon")->wear();
} 
