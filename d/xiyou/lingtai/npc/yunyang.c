// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//yunyang.c
inherit NPC;
inherit F_MASTER;



void re_rank(object who);

void create()
{
        set_name("��������", ({"master yunyang", "master", "yunyang"}));
        set("long", "����������������ʦʵ�ǰ�ʦ���ѣ�Ҳ�����Ƕ������ܹܣ�
����׳��ʱ��ħ�����������˳ơ�С��ʦ����\n");
        set("faith",4000);
        set("gender", "����");
        set("title", "С��ʦ");
        set("class", "taoist");
        set("age", 70);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("rank_info/respect", "�ϵ���");
        set("per", 30);
        set("int", 30);
        set("str", 30);
        set("cps", 30);
        set("max_kee", 1100);
        set("max_gin", 1100);
        set("max_sen", 1100);
        set("force", 2300);
        set("max_force", 1200);
        set("force_factor", 80);
        set("max_mana", 1200);
        set("mana", 2300);
        set("mana_factor", 60);
        set("combat_exp", 800000);

     

        create_family("����ɽ���Ƕ�", 1, "��");
        setup();

        carry_object("/d/xiyou/lingtai/obj/bang")->wield();
}

