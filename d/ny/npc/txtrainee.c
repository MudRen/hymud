
// txtrainee.c
#include <ansi.h>

inherit NPC;

void create()
{
	string *surname=({"��","Ǯ","��","��"});
	string *fname1=({"��","��","��","��"});
	set_name( "��а��"+(surname[random(4)])+(fname1[random(4)]), ({ "trainee" }) );
        set("shen_type",-1);
	set("gender", "����" );
	set("age", 19);
	set("long", "�㿴��һλ��ĸߴ�ĺ��ӣ���������ز�������\n");
        set("combat_exp", 5000);
	set_skill("sword",30);
	set_skill("dodge",40);
	set_skill("unarmed",30);
	set_skill("parry",20);
	setup();
	carry_object(__DIR__"obj/bamboo_sword")->wield();
	carry_object(__DIR__"obj/linen")->wear();
}
