// lin.c �ֳ�Ӣ
// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

string ask_yunv();

void create()
{
        set_name("�ֳ�Ӣ", ({"lin chaoying", "lin"}));
        set("gender", "Ů��");
        set("age", 42);
        set("long",
                "�����ǹ�Ĺ�ɵĿ�ɽ��ʦ�ֳ�Ӣ����Ȼ�Ѿ�����ʮ���ˣ���֮ȴ\n"
                "����ͬ��ʮ��ͷ����������ȫ���������������һ�Գ��İ��£�\n"
                "ֻ��ϧ��Ե�޷ݣ�ֻ�ö��������Ĺ���ľӡ�\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 130);
        set("int", 142);
        set("con", 130);
        set("dex", 130);


        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "sword.hebi yang" :),
            		(: command("perform sword.hebi yang") :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }) );

	set("attitude", "peaceful");
        set("qi", 350000);
        set("max_qi",350000);
        set("jing", 350000);
        set("max_jing", 350000);
        set("neili", 353000);
        set("max_neili", 353000);
        set("jiali", 100);

        set("combat_exp", 19000000);
        set("score", 0);

        set_skill("force", 1300);
        set_skill("yunv-xinfa", 1300);    //��Ů�ķ�
        set_skill("sword", 1300);
        set_skill("yunv-jian", 400);     //��Ů��
        set_skill("quanzhen-jian",300);  //ȫ�潣
        set_skill("dodge", 1300);
        set_skill("yunv-shenfa", 1300);   //��Ů��
        set_skill("parry", 1300);
        set_skill("unarmed",1300);
        set_skill("meinv-quan", 1300);    //��Ůȭ��
        set_skill("literate",1320);
        set_skill("taoism",1340);

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);

        create_family("��Ĺ��", 1, "��ɽ��ʦ");

        set("book_count",1);


        setup();
    carry_object("/p/item/ritemtz3/wsword34")->wield();
    carry_object("/p/item/ritemtz3/ahands31")->wear();
        carry_object(__DIR__"obj/qingyi")->wear();

}

