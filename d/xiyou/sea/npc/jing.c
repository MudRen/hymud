#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int give_me(object ob);
int delete_ask(object ob);
int create_pai(object ob);

void create()
{
       set_name("���޵�", ({"jing wudi", "jing"}));

set("long","��߰��ɣ������Բ���ųƶ�����һ��ʿ��
ˮ���������������Ʋ������ɳ�����ˮ�����С�\n");
       set("gender", "����");
       set("age", 56);
        set("title", "����");
        set("per", 10);
        set("str", 35);
	set("con", 30);
	set("int", 20);
        set("max_kee", 1500);
	set("max_sen", 1000);
       set("attitude", "heroism");
       set("combat_exp", 700000);
  set("daoxing", 200000);

	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("mana", 800);
	set("max_mana", 800);
	set("mana_factor", 40);
	set("have", 3);

       setup();

       carry_object("/d/obj/weapon/hammer/bahammer")->wield();
	carry_object("/d/xiyou/sea/obj/pai");

}

