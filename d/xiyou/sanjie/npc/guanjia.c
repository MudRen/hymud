// guanjia.c �ܼ�

#include <ansi.h>

int random_go(object me, string* dirs);

//int change_tianyi();
//int change_tianyao();
//int change_tianmo();
//int change_cangshi();
//int change_leidao();
string ask_cancel();
int change_mieyao();
//int change_menpainame();

//int gift();

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(WHT"�ܼ�"NOR, ({"guan jia", "master"}));
       set("long", "����ɽ�Ĺܼң����������ɷ����������ڵ��Ͽ���һ�ҿ�ջ��\n");
       set("title", HIC"����ɽ"NOR);
       set("per", 40);
       set("gender", "����");
       set("age", 40);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "������");
       set("max_kee", 500);
       set("max_gin", 100);
       set("max_sen", 500);
       set("force", 500);
       set("max_force", 500);
       set("force_factor", 50);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 50);
       set("combat_exp", 45000);
       set("daoxing", 55000);

	set("inquiry", ([
	"name"     : "����������ϰ壬��������\n",
	"here"     : "�����ǡ��˶��꡹��������Ҫ���Խ���סס�ꡣ\n",
//        "����ɽ"    : (:change_menpainame:),
/*      "��һ��"   : (:change_tianyi:),
      "������"   : (:change_tianyao:),
      "��ħ��"   : (:change_tianmo:),
      "��ʬ��"   : (:change_cangshi:),
      "�׵���"   : (:change_leidao:),
*/      
      "����"     : (:change_mieyao:),
//      "����"     : (:gift:),
	]));
	
	setup();
}

