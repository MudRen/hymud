// ������    /d/menpai/shennong/npc/gao_laozhe.c
// by lala, 1998-01-21

#include <ansi.h>
inherit __DIR__"ShennongNpc.c";



void create()
{
    set_name("������", ({ "gao laozhe", "gao", "laozhe", "gaolaozhe", }) );
    set("class_score/��ũ��",       600);
    set("title", BLU"��ũ������"NOR);
    create_family("��ũ��", 1, "����");
    set("combat_exp",    500000);
    set("social_exp",   100000);
    set("negative_score",  500);
    set("max_force",       1000);
    set("force",           1000);
    set("force_factor",     50);
    set("max_kee",         600);
    set("max_sen",         1500);
    set("kee",             1500);
    set("sen",             600);
    set("age",              50);
    set("int",              27);
    set("long", @LONG
    һ��������ߵ����ߣ�˫��ʮָ����צ�������ǳ���ӥצ��һ����书��
��˵ԭ���Ǹ�����ͷ�죬������ְ�ˣ�Ҳ��֪�ǲ�����Ϊ��ͷ֪����������ũ��Ĺ�ϵ��
LONG
    ); 
    
 set("max_qi", 3700);
	set("max_jing", 3700);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 30);
	set("combat_exp", 600000);
	set("score", 40000);

	set_skill("force", 170);
	set_skill("huagong-dafa", 150);
	set_skill("throwing", 170);
	set_skill("feixing-shu", 180);
	set_skill("dodge", 170);
	set_skill("zhaixinggong", 200);
	set_skill("strike", 180);
	set_skill("chousui-zhang", 180);
	set_skill("claw", 180);
	set_skill("sanyin-wugongzhao", 180);
	set_skill("parry", 170);
	set_skill("poison", 170);
	set_skill("staff", 170);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");

    setup();

    carry_object( "/clone/misc/cloth" )->wear();
//    carry_object( SHORT_DIR + "yaochu" )->wield();
    add_money( "coin", 20 + random(20) );
}
        