#include <ansi.h>
inherit NPC;
inherit F_BANKER;

int test_dart(); 
void create()
{
        set_name("����", ({ "cai shu","cai","caishu" }) );
        set("gender", "����" );
        set("age", 52);
        set("richness",5000000);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long",
                "һ���ֺǺǵ����ڹ�̨�������۾��������ӵ�С��ͷ��\n");
        set("combat_exp", 600000);
        set("attitude", "friendly");
        set("max_neili", 1000);         
        set("force", 1000);             
        set("force_factor", 50);
        set("chat_chance", 2);
        set("chat_msg", ({
                "��������ţ�����·����ʣ�Ƿ�˸����Ӽ�ʮ��Ǯ���Ͳ�֪�㵽��ȥ����ˡ�\n",
                "����˵�������˧Ҫ���˻��ڣ�Ӧ���Ƽ�˭ȥ��������񣨣�������أ���\n",
        }) );

        set("inquiry", ([
        "mission" : (: test_dart :),
                "����" : (: test_dart :),
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/goldabacus")->wield();
} 
void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}
