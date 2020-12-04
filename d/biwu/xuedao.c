// /kungfu/class/xueshan/xuedao.c  Ѫ������
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Ѫ������", ({ "xuedao laozu", "xue dao", "laozu" }));
        set("long",@LONG
���������Ż��ۣ���ͼ��ϣ���ͷ���������϶������ơ�������Ѫ���ŵ��Ĵ����š�
LONG
        );
        set("title",HIR"Ѫ���ŵ��Ĵ�����"NOR);
        set("gender", "����");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 130);
        set("int", 130);
        set("con", 130);
        set("dex", 130);
        set("max_qi", 355000);
        set("max_jing", 352000);
        set("neili", 352000);
        set("max_neili", 352000);
        set("jiali", 50);
        set("combat_exp", 16500000);
        set("score", 180000);

        set_skill("lamaism", 950);
        set_skill("literate", 980);
        set_skill("force", 1180);
        set_skill("parry", 1180);
        set_skill("blade", 1250);
        set_skill("sword", 1120);
        set_skill("dodge", 980);
        set_skill("longxiang", 980);
        set_skill("shenkong-xing", 980);
        set_skill("hand", 980);
        set_skill("dashou-yin", 980);
        set_skill("mingwang-jian", 980);
        set_skill("xue-dao", 980);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);

        create_family("ѩɽ��", 4, "����");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/p/item/ritemtz3/wblade14")->wield();

        //add_money("gold",2);
}

