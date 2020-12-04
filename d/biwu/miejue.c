// miejue.c ���ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
        set_name("���ʦ̫", ({ "miejue shitai","miejue","shitai"}));
        set("long",
                "���Ƕ����ɵĵ��������ӣ����ζ����������ˡ�\n");
        set("gender", "Ů��");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 100000);
        set("class", "bonze");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) );
        set("inquiry",([
                "���"  : "ƶ��ֻ֪����ɱħ������ȵ��ӡ�",
                "����"  : "ƶ��ֻ֪����ɱħ������ȵ��ӡ�",
                "����"  :  (: ask_for_quit :),
        ]));

        set("str", 135);
        set("int", 135);
        set("con", 135);
        set("dex", 135);
        set("per", 120);

        set("max_qi", 354000);
        set("max_jing", 352000);
        set("neili", 358000);
        set("max_neili", 358000);
        set("jingli", 351500);
        set("max_jingli", 351500);

        set("combat_exp", 182000000);
        set("score", 1000);
        set_skill("persuading", 150);
        set_skill("throwing", 1300);
        set_skill("force", 1000);
        set_skill("dodge", 1200);
        set_skill("finger", 1300);
        set_skill("parry", 1000);
        set_skill("strike", 1200);
        set_skill("sword", 1250);
        set_skill("blade", 1300);
        set_skill("literate", 1000);
        set_skill("mahayana", 1250);
        set_skill("buddhism", 1250);
        set_skill("jinding-zhang", 980);
        set_skill("tiangang-zhi", 980);
        set_skill("huifeng-jian", 980);
        set_skill("yanxing-dao", 980);
        set_skill("zhutian-bu", 980);
        set_skill("linji-zhuang", 1350);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);

//        map_skill("magic","bashi-shentong");
        create_family("������", 3, "������");

        setup();
    carry_object("/p/item/ritemtz3/wsword13")->wield();
    carry_object("/p/item/ritemtz3/ahands12")->wear();
        carry_object("/d/city/obj/cloth.c")->wear();
}

