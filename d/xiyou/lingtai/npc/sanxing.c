//����ʥĸ
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIW"����ʥĸ"NOR, ({"sanxing shengmu","sanxing", "master"}));
       set("long", "Ǭ����ת�������޷�\n");
       set("title", HIC"�����޷�"NOR);
       set("gender", "Ů��");
       set("age", 20);
        set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ʥĸ");
       set("per", 40);
        set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
    
create_family("����ɽ���Ƕ�", 1, "��");
setup();

        carry_object("/d/xiyou/lingtai/obj/pao")->wear();
        carry_object("/d/xiyou/lingtai/obj/shoe")->wear();
        carry_object("/d/xiyou/lingtai/obj/longxingjian")->wield();
}

