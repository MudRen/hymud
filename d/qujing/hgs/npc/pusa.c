//Cracked by Roath
// guanyin.c ��������
// By Dream Dec. 19, 1996
#include <ansi.h>
inherit NPC;
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
                set("str",100);
                set("spi",80);
                set("cor",80);
                set("cps",80);
                set("con",80);
                set("per",40);
                set("int",40);
                set("kar",40);// Cigar@sjsh_SKxyj add the all attribute.
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_jing", 5000);
        set("neili", 6000);
        set("max_neili", 3000);
        set("force_factor", 250);
        set("max_mana", 4000);
        set("mana", 8000);
        set("mana_factor", 250);
	set("combat_exp", 2000000);
	set("daoxing", 10000000);

      
	set("inquiry",([
      "��ƿ": "ǰЩ�죬���ǽ��ҵľ�ƿ�ã�������Ҳû�л�����ȥ�����ɡ�" ]));



	//let's use cast bighammer to protect her...weiqi:)
	create_family("�Ϻ�����ɽ", 1, "����");

	setup();
	initlvl((3500+random(3500)),random(63));
        carry_object("/d/qujing/nanhai/obj/jiasha")->wear();
        carry_object("/d/qujing/nanhai/obj/nine-ring")->wield(); 
}


void die()
{
	int i;
	string file;
	object *inv;

        if( environment() ) {
        message("sound", "\n\n��������ҡͷ̾�����������ϣ�����ħ�ϣ����伲�࣬���˶�֮��\n\n", environment());
        command("sigh");
        message("sound", "\n�������������ƣ��ǲ�����������ȥ�ˡ�����\n\n", environment());


	destruct(this_object());
}
}


void announce_success (object who)
{
  
  int i;

  if(!who) return;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/liuer-mihou") == "done")
    return;

  if (! who->query_temp("obstacle/liuer-mihou"))
    return;
//  if ( who->query("dntg/laojunlu") != "done")
//    return;

  	i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/liuer-mihou","done");
  who->add("combat_exp",i+30000);
   who->add("potential",i*8);
   who->add("mpgx",10);;who->add("expmax",2);
  command("chat "+who->query("name")+"�������⨺");
message("channel:chat",HIY"������ն������������(guanyin pusa)��"+who->query("name")+"��������ȡ�� �������⨺� һ��!\n"NOR,users());
  tell_object (who,"��Ӯ����"+chinese_number(i+30000)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
  who->save();
}