// ��ԯ��Ĺ ��Ĺ������
//by junhyun@SK

#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"��������"NOR, ({"hubao yaohu", "fox", "hu"}));
        set("title", HIW"��ԯ��Ĺ"NOR);
        set("gender", "Ů��" );
      set("taskguai",1);
        set("age", 20);
        set("per", 40);
        set("str", 30);
        set("family/family_name", "��ԯ��Ĺ");
        set("class", "yaomo");
    set("long","��������ԯ��Ĺ���ڶ౦�������\n");

        set("attitude", "aggressive");

  set("combat_exp", 10000000);
  set("daoxing", 100000000);

 
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  setup();
    
          carry_object("/d/obj/weapon/sword/xy_sword.c")->wield(); 
}

