
// guanyin.c �ݰ�����
// By Dream Dec. 20, 1996
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("�ݰ�����", ({ "huian xingzhe", "huian", "xingzhe" }));
        set("title", "������ͽ");   
        set("long", @LONG
��������̫��ľ�棬�Ϻ�������ͽ�ܻݰ����ߡ�
LONG);
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("rank_info/self", "ƶɮ");
        set("class", "bonze");
    
    set("max_kee", 1000);
        set("max_gin", 600);
           set("max_sen", 1000);
        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 75);
        set("max_mana", 1000);
        set("mana", 2000);
        set("mana_factor", 55);
        set("combat_exp", 750000);

        set("eff_dx", 150000);
        set("nkgain", 300);

  

        create_family("�Ϻ�����ɽ", 2, "����");

        setup();
        carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
        carry_object("/d/xiyou/nanhai/obj/budd_staff")->wield();
}

