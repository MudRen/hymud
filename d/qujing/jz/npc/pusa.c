//Cracked by Roath

inherit NPC;
#include <ansi.h>
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("��������", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "�ȿ���Ѵ�ȴ�");
	set("long", @LONG
��Բ�ĵ£���������ü��С�£�����˫�ǡ�����������
ޥ�԰����١���������٤ɽ�ϴȱ�������������������
LONG);
	set("gender", "Ů��");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "ƶɮ");
	set("rank_info/respect", "��������");
	set("class", "bonze");
        	set("str",24);
	set("per",100);//means no rong-mao description.
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_jing", 5000);
	set("neili", 4000);
	set("max_neili", 2000);
	set("force_factor", 145);
	set("max_neili", 3000);
	set("neili", 6000);
	set("mana_factor", 150);
	set("combat_exp", 20000000);
	set("combat_exp", 10000000);

	set_skill("literate", 150);


	setup();
initlvl((500+random(500)),1);
	carry_object("/d/qujing/nanhai/obj/jiasha")->wear();
	carry_object("/d/qujing/nanhai/obj/nine-ring")->wield();
}

void announce_success (object who)
{
  
  int i;

  if(!who) return;

  if (who->query("combat_exp",1) < 1000000)
    return;
  if (who->query("obstacle/jz") == "done")
    return;
  if (! who->query_temp("obstacle/jz_libiao_killed"))
    return;
  if (! who->query_temp("obstacle/jz_liuhong_killed"))
    return;
//  if ( who->query("dntg/laojunlu") != "done")
//    return;

  	i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/jz","done");
  who->add("combat_exp",i+6800);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"ɱ��������ˣ��ȳ����");
message("channel:chat",HIY"������ն������������(guanyin pusa)��"+who->query("name")+"��������ȡ��[1;37m��һ�أ�\n"NOR,users());
  tell_object (who,"��Ӯ����"+chinese_number(i+6800)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
  who->save();
}
