// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("һ�ƴ�ʦ", ({"yideng-dashi", "dashi", "yideng"}));
    set("nickname", HIG "�ϵ�" NOR );
    set("gender", "����");
    set("age", 52);
    set("long", 
        "�����Ǻųơ��ϵۡ���һ�ƴ�ʦ�����������ˣ�����ѷλΪɮ��\n"
        "��ʦһ�����ƣ��������\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 121);
    set("int", 130);
    set("con", 126);
    set("dex", 130);

    set("qi", 353000);
    set("max_qi", 353000);
    set("jing", 353000);
    set("max_jing", 353000);
    set("neili", 353500);
    set("max_neili", 353500);
    set("jiali", 100);
	
    set("combat_exp", 93000000);
    set("score", 0);
     
    set_skill("kurong-changong", 1350);             // �����ڹ�
    set_skill("unarmed", 1350);             // �����ڹ�
    set_skill("force", 1350);             // �����ڹ�
    set_skill("finger", 370);            // ����ָ��
    set_skill("dodge", 1350);             // ��������
    set_skill("parry", 1350);             // �����м�
    set_skill("six-finger", 980);   // ������
    set_skill("taixuan-gong", 980);      // ̫����
    set_skill("lingxu-bu", 980);         // ���鲽
    set_skill("literate",380);           // ����ʶ��
	
    map_skill("force"  , "kurong-changong");
    map_skill("unarmed" , "six-finger");
    map_skill("finger" , "six-finger");
    map_skill("dodge"  , "lingxu-bu");
    map_skill("parry"  , "six-finger");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "unarmed.liumaijingshen" :),
                (: perform_action, "unarmed.qi" :),
                (: perform_action, "unarmed.zong" :),
                (: perform_action, "unarmed.zongheng" :),
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );



    prepare_skill("finger", "six-finger");

    create_family("����μ�", 17, "����");
    setup();

    carry_object("/p/item/ritemtz3/acloth58")->wear();
    carry_object("/p/item/ritemtz3/ahands32")->wear();
}
