// ����Уξ /d/city/chuzhou/npc/xiaowei.c
// by lala, 1997-12-13

#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "Уξ", ({ "xiao wei", "jiang" }));
    set( "title", YEL"����"GRN"�ر�"NOR );
    set( "age", 31 );
    set( "gender", "����" );
    set( "long", "\n" );
    set( "str", 30 );
    set( "con", 30 );
    set( "no_kill", "yangzhou" );
    set( "combat_exp", 20000 );
    set( "max_gin", 200 );
    set( "max_qi", 400 );
    set( "max_sen", 400 );
    set( "max_force", 1000 );
    set( "force_factor", 10 );
    set( "chat_chance_combat", 10 );
    set( "chat_msg_combat", ({
        "Уξ�ȵ������󵨵��񣬾���ɱ�٣�Ī�������췴���ɣ���\n",
        "Уξ�ȵ������㻹���ӳ����ι��粻�ɣ����ǹԹ�Ͷ���ɣ���\n",
    }));
    set("talk_msg", ({
        "��������ô����������Ǹ�Уξ������������",
        "���ڳ��ݻ�����ô�����ˣ�ȴ�ö�ط�ûȥ��������",
        "��������������͸���ˡ�����",
    }));
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
    setup();
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/junfu")->wear();
	carry_object("/d/city/npc/obj/jitui")->wear();
}

