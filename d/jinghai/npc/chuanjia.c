// chuanjia.c

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_MASTER;

void create()
{
        set_name("����", ({"chuan jia"}));
        set("long", @LONG
����һλ������ɣ���ϴ��ҡ�
LONG
);
        set("gender","����");

        set("age",56);
        set("con",20);
        set("str",30);
	set_skill("unarmed",60);
	set_skill("dodge",60);
	set_skill("parry",60);
	

        set("combat_exp",8000);

	set_max_passenger(6);
	set_cross_msg("�ɺ�");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

