// ����Ѳ�� /d/city/chuzhou/npc/xunbu.c
// by lala, 1997-12-13

#include <ansi.h>

inherit NPC;



void create()
{
    set_name("Ѳ��", ({ "xun bu", "bu", "constable" }));
    set("gender", "����");
    set("age", 35);
    set("title", GRN"����"YEL"�ٲ�"NOR),
    set("long", "����һ��Ѳ��������ֵ���һ���������������ӡ�\n");

    set("no_leave_chuzhou", 1);

    set("str", 30);
    set("con", 30);

	set("combat_exp", 310000);
	set("shen_type", 1);

    set("max_neili",5500);
    set("neili",5500);
    set("qi",5500);
    set("eff_qi",5500);
    set("max_qi",5500);

    set("jing",5500);
    set("eff_jing",5500);
    set("max_jing",5500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

    set("combat_exp", 50000);
    set("chat_chance", 45);
    set("chat_msg", ({
        "Ѳ������������������һ��Ҫ���˻��������ӡ�\n",
        "Ѳ���ȵ�����������������ʲô�أ���\n",
        (:random_move:),
    }) );
    set("talk_msg", ({
        "���ӳ��ݿ����滴ˮ���ϵ�����ȥ����",
        "���Դ��˺��ϵĴ�ֻ�����ͣ���Ķ����Ժ󣬵����ϵ���ƤҲ���ˡ���",
        "������������˰ɣ����ݵ��ھ־�˵����������",
        "��Ҫ����ʲôԩ�飬����Ե�����ȥ��ԩ����",
        "���ӳ��ݹ���ˮ�ܷ��㣬�����и��ɿڡ����Ǻ��Ǳ���ʲô�ط����Ҳ�֪������",
        }) );
    setup();
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/junfu")->wear();
	carry_object("/d/city/npc/obj/jitui")->wear();
}


