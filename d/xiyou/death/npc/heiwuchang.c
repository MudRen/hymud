// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("���޳�", ({ "hei wuchang","wuchang", "gargoyle" }));
        set("long","һ�����������Ƥ��ʹ�ߣ���ڵ����Ͽ������κ�ϲŭ���֡�\n");
        set("attitude", "peaceful");
	set("per", 10);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", "����˾��");
        set("combat_exp", 150000);
  set("daoxing", 200000);

        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
	set("class", "youling");
	set("force", 1500);
	set("max_force", 800);
	set("force_factor", 50);
	set("max_mana", 600);
	set("mana", 1000);
	set("mana_factor", 40);
	

create_family("���޵ظ�", 3, "���");
  set("inquiry",([
   "name":"��������ʹ���޳�����ʮ��ڤ��֮����ǰ�����乴�ꡣ\n",
   "here":"���������޵ظ���\n",
   "����":"�Ұ��������鹴�ˣ�����ԩ�������뷢�˹���֮ڤ������(complain)��\n",
   "ԩ��":"�Ұ��������鹴�ˣ�����ԩ�������뷢�˹���֮ڤ������(complain)��\n",
   "ԩ��":"�Ұ��������鹴�ˣ�����ԩ�������뷢�˹���֮ڤ������(complain)��\n",
  ]));

        setup();
	carry_object("/d/obj/cloth/hei")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say �ܺã�" + RANK_D->query_respect(me) +
"���Ŭ�������ձض��гɡ�\n");
       command("recruit " + me->query("id") );
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
//		ob->set("title", "�ظ�����˾����");
}

�
