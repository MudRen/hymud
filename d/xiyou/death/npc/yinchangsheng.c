// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "yin changsheng", "yin", "changsheng" }));
        set("long","���������Ǹ������ţ����ڷᶼɽ�������ɣ����⡸��������\n");
        set("attitude", "peaceful");
	set("per", 30);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", "����˾��");
	set("nickname", "����");
        set("combat_exp", 800000);
  set("daoxing", 400000);

        set("max_gin", 1400);
        set("max_kee", 1400);
        set("max_sen", 1400);
	set("class", "youling");
	set("force", 2500);
	set("max_force", 1500);
	set("force_factor", 100);
	set("max_mana", 1500);
	set("mana", 2500);
	set("mana_factor", 100);

	

	set_temp("apply/dodge", 50);
	set_temp("apply/armor", 50);


create_family("���޵ظ�", 2, "���");

        setup();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
	carry_object("/d/obj/cloth/choupao")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say �ܺã�" + RANK_D->query_respect(me) +
"���Ŭ�������ձض��гɡ�\n");
       command("recruit " + me->query("id") );
        me->set("class", "youling");
	return;
}
/*
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
		ob->set("title", "�ظ��л�˾����");
}

*/
�
