//zhangdaoling.c

inherit NPC;
inherit F_MASTER;
void consider();

void create()
{
        set_name("�ŵ���", ({"zhang daoling", "zhang", "daoling"}));
        set("long", "�ŵ����������ϵ���ʦ���˿�͵����ɽ�߹۹۾�ɫ��\n");
        set("title", "��ʦ");
        set("gender", "����");
        set("class", "taoist");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("rank_info/respect", "������");
        set("per", 30);
        set("int", 30);
        set("str", 25);
        set("max_kee", 1000);
        set("max_gin", 1000);   
        set("max_sen", 1000);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 40);
        set("max_mana", 1000);
        set("mana",1900);
        set("mana_factor", 50);
        set("combat_exp", 800000);
        set("daoxing", 1000000);
        set("eff_dx", 250000);
        set("nkgain", 400);

     

        create_family("��ң��", 1, "��");
        setup();

        carry_object("/d/xiyou/lingtai/obj/heao")->wear();
        carry_object("/d/xiyou/lingtai/obj/faguan")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng");
}

