//ϲ��
//��ԯ��Ĺ

//ximei.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_leave();


void create()
{
              set_name(HIW"ϲ��" NOR, ({"xi mei", "ximei", "mei"}));
       set("long", "
һֻ������������������а�����Ϊ��槼��ǳ�
ϲ����������������֮�����������Ⱥò�����
�����ڳ���¹̨֮����������槼�����������֮
ʱ��ʤ��������¶ԭ�α���̫ʦ���ٵĽ��֮��
���ڷ���̨��槼�������������\n");
       set("title", HIB"������" NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("per", 40);
        set("int", 40);
       set("max_kee", 900);
       set("max_gin", 600);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 400000);
  set("daoxing", 800000);


        set("eff_dx", 200000);
        set("nkgain", 350);

    

create_family("��ԯ��Ĺ", 2, "����");
setup();


}

