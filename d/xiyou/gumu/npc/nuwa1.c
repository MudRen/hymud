//��ԯ��Ĺ�ռ�ʦ�� Ů�
//by junhyun@SK
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
       set_name("Ů�", ({"nu wa", "nuwa", "nu","wa","master","tianshen"}));
       set("long", "���֮ĸ���������������ʯ���죬
��ٶ��ж��ϲԣ���Ϊ�����ʥ������𣬺���槼��Ⱦ�
����Ů��ר�Ÿ�������
\n");
       set("title", HIM"���֮ĸ"NOR);
       set("color", HIW);
       set("gender", "Ů��");
       set("age", 20);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("cor", 30);
       set("per", 40);
      set("looking", "����Ʈ��,����ʵ�á�");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 8000);
       set("max_force", 5000);
       set("force_factor", 305);
       set("max_mana", 5000);
       set("mana", 8000);
       set("mana_factor", 400);
       set("combat_exp", 10000000);
       set("daoxing", 8000000);
   
create_family("��ԯ��Ĺ", 1, "��");
setup();


  
}

