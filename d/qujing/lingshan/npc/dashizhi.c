//created by greenwc
//created by greenwc
inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("����������", ({"dashizhi pusa", "dashizhi", "dashi", "pusa"}));
  set ("long", @LONG
���ް����ӷ��ͽ��������������ʦ�ܣ���
�˲�����������
LONG);
  set("title", "��������֮");
  set("gender", "����");
  set("age", 400);
  set("str", 40);
  set("per", 40);
  set("int", 30);
  set("cor", 50);
  set("cps", 40);
    
           set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_jing", 5000);
	set("neili", 4000);
	set("max_neili", 2000);
	set("force_factor", 150);
	set("max_neili", 3000);
	set("neili", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2000000);
	set("combat_exp", 10000000);

	create_family("�Ϻ�����ɽ", 1, "����");
  setup();
      initlvl((1000+random(1000)),random(63));
	carry_object("/d/obj/weapon/hammer/falun2")->wield();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}



void die()
{
        if( environment() ) {
        message("sound", "\n\n����������ҡͷ̾����ԩ��������ԩ����n\n", environment());
        command("sigh");
        message("sound", "\n���������������ƣ��ǲ�����������ȥ�ˡ�����\n\n", environment());
}

	destruct(this_object());
}
