//puti.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("������ʦ", ({"master puti","puti", "master"}));
        set("long", "�������û���ˣ���������������\n");
        set("title", HIC"б������"NOR);
        set("gender", "����");
        set("age", 100);
        set("color", HIW);
        set("class", "taoist");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("rank_info/respect", "��ʦ��");
        set("per", 26);
        set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
        set("int", 30);
        set("max_kee", 5000);
        set("max_gin", 1000);
        set("max_sen", 5000);
        set("force", 5000);
        set("max_force", 2500);
        set("force_factor", 150);
      

        create_family("����ɽ���Ƕ�", 1, "��");
        setup();

        carry_object("/d/xiyou/lingtai/obj/pao")->wear();
        carry_object("/d/xiyou/lingtai/obj/shoe")->wear();
        carry_object("/d/xiyou/lingtai/obj/putibang")->wield();
}



