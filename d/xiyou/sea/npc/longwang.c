//modified by sgzl for dntg/donghai quest
#include <skill.h>

inherit NPC;
inherit F_MASTER;



void create()
{
       	set_name("����", ({"ao guang", "ao","guang","longwang","wang"}));

	set("long","�����Ƕ��������������ֱֵܷ��ƹܶ��������ϣ����ĺ���
������ˮ���ڶ࣬���ƺƴ�ٲȻ����һ����\n");
       set("gender", "����");
       set("age", 66);
	set("title", "��������");
	set("class","dragon");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 1260000);
       set("daoxing", 1500000);
       set("rank_info/respect", "����");
       set("per", 20);
       set("str", 30);
       set("max_kee", 3000);
       set("max_gin", 400);
       set("max_sen", 1500);
       set("force", 3000);
       set("max_force", 1500);
  


        create_family("��������", 1, "ˮ��");
	set_temp("apply/armor",50);
	set_temp("apply/damage",25);
	setup();

        carry_object("/d/xiyou/sea/obj/longpao")->wear();
}
