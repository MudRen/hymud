//��ԯ��Ĺ�ռ�ʦ�� ��ԯ��
//by junhyun@SK
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
        set_name("��ԯ��", ({"xuanyuan gong", "xuanyuan", "gong","master","tianshen"}));
       set("long", "����ٵ�֮����Ů�ƽ��ƽ��������Ϊ
�ŷ������ò������ɵ���ͬ��
\n");
       set("title", HIW"����ٵ�"NOR);
       set("color", HIR);
       set("gender", "����");
       set("age", 20);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("cor", 30);
       set("per", 40);
      set("looking", "�ɷ���ǣ���ֹ������");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 5000000);
      
create_family("��ԯ��Ĺ", 1, "��");
setup();


        
}

